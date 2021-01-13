
#include <torch/torch.h>
#include <opencv2/opencv.hpp>

// 模型
class Lenet5 : public torch::nn::Module {
private:
    torch::nn::Conv2d conv1;
    torch::nn::Conv2d conv2;
    torch::nn::Conv2d conv3;
    torch::nn::Linear fc1;
    torch::nn::Linear fc2;
public:
    // 构造器
    Lenet5(): 
            conv1(torch::nn::Conv2dOptions(1, 6, 5).stride(1).padding(2)),    // 输入的是28 * 28 图像，如果是32 * 32，则padding=0
            conv2(torch::nn::Conv2dOptions(6, 16, 5).stride(1).padding(0)),
            conv3(torch::nn::Conv2dOptions(16, 120, 5).stride(1).padding(0)),
            fc1(120, 84),
            fc2(84, 10) {
        register_module("conv1", conv1);    // 注册后的模块，其中的参数将得到训练
        register_module("conv2", conv2);
        register_module("conv3", conv3);
        register_module("fc1", fc1);
        register_module("fc2", fc2);
    }

    // override函数 forward
    torch::Tensor forward(torch::Tensor x) {
        // 第一个卷积层
        x = conv1->forward(x);   // 卷积
        x = torch::max_pool2d(x, 2);  // 池化
        x = torch::relu(x);  // 激活函数
        // std::cout << "Conv-1:" << x.sizes() << std::endl;
        // 第二个卷积层
        x = conv2->forward(x);
        x = torch::max_pool2d(x, 2);
        x = torch::relu(x);
        // std::cout << "Conv-2:" << x.sizes() << std::endl;
        // 第三卷积层
        x = conv3->forward(x);
        // std::cout << "Conv-3:" << x.sizes() << std::endl;
        x = torch::relu(x);
        // 格式转换（从图像转为向量）
        x = x.view({-1, 120});

        // // 全连接层
        x = fc1->forward(x);
        x = torch::relu(x);

        x = fc2->forward(x);
        return torch::log_softmax(x, /*dim=*/1);  // 维度dim=1，按照列计算
    }
};


// 训练函数需要传递几个参数：需要训练的模型，训练数据集；优化器（包括学习率），训练的轮数
// 因为数据集批次加载器类型的复杂性，我们使用模板，来实现自动推导
// 因为优化器很多，我们采用通用编程，使用其父类

template <typename DataLoader>
void train(std::shared_ptr<Lenet5> &model, DataLoader &loader, torch::optim::Optimizer &optimizer){  // 训练一次
    model->train();  // 该函数的用途是使BatchNorm与Dropout有效
    // 对数据集批次进行循环训练
    // for (auto& batch : data_loader) {} // 这种循环更加方便
    int n = 0;
    for (const torch::data::Example<>& batch : loader) {
        // 获取数据集与标签
        torch::Tensor data = batch.data;
        torch::Tensor labels = batch.target;
        // 优化器上次计算的梯度清0
        optimizer.zero_grad();
        // forward计算结果
        torch::Tensor y = model->forward(data);  // 这个数据是批次数据集
        // 计算损失函数Softmax– Log –NLLLoss = CrossEntropyLoss （本来可以直接使用交叉熵函数作为损失函数，因为我们在模型中使用了log-softmax, 所以这里使用nll损失函数）
        torch::Tensor loss = torch::nll_loss(y, labels);
        // 前馈求导，计算梯度
        loss.backward();
        // 优化器更新梯度，模型得到训练与学习
        optimizer.step();
        // 输出损失值，观察训练是否有效
        // std::cout << "\t |- 批次:"<< std::setw(2) << std::setfill(' ') << ++n << "，\t损失值：" << loss.data_ptr<float>()[0] << std::endl;
    }

}

// 测试那就是验证，主要测试识别准确率，统计计算测试集的损失精度，判定拟合情况
template <typename DataLoader>
void valid(std::shared_ptr<Lenet5> &model, DataLoader &loader){   // 不需要优化器
    // 禁止张量跟踪计算图，并计算梯度
    torch::NoGradGuard no_grad;
    model->eval(); // 这个函数在模型中没有BatchNorm与Dropout的时候是不需要的，该函数的用途就是屏蔽BatchNorm与Dropout，使其失效
    double sum_loss = 0;   // 累计所有测试样本的损失
    int32_t num_correct = 0; // 累计识别正确的样本数
    int32_t num_samples = 0; // 测试集样本总数
    for (const auto& batch : loader) {
        // 获取测试批次
        auto data = batch.data;
        auto labels = batch.target;

        num_samples += data.sizes()[0]; // 第一维度为当前批次样本数量
        // 计算输出
        auto y = model->forward(data);
        // 计算损失
        sum_loss += torch::nll_loss(y, labels, {},at::Reduction::Sum).item<float>();
        // 判定识别正确度
        auto pred = y.argmax(1);
        num_correct += pred.eq(labels).sum().item<int32_t>();
    }
    std::cout << std::setw(8) << std::setprecision(4) 
        << "平均损失值:" << sum_loss / num_samples  << ", 识别正确率："<< 1.0 * num_correct / num_samples  << "%" << std::endl;
}

int main(int argc, char **argv){
    // 训练轮数
    int epoch = 10;
    int batch_size = 1000;
    const char * data_dir = ".\\data";

    // 模型
    std::shared_ptr<Lenet5> model = std::make_shared<Lenet5>();
    // 数据集 - 训练数据集
    auto train_dataset = torch::data::datasets::MNIST(data_dir)
            .map(torch::data::transforms::Normalize<>(0.1307, 0.3081))
            .map(torch::data::transforms::Stack<>());
    // 数据集 - 测试数据集
    auto test_dataset  = torch::data::datasets::MNIST(data_dir, torch::data::datasets::MNIST::Mode::kTest)
            .map(torch::data::transforms::Normalize<>(0.1307, 0.3081))
            .map(torch::data::transforms::Stack<>());
    // 数据批次加载器 - 训练集
    auto train_loader = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(std::move(train_dataset), batch_size);
    // 数据批次加载器 - 测试集
    auto test_loader  = torch::data::make_data_loader(std::move(test_dataset), batch_size);

    // 优化器
    torch::optim::Adam optimizer = torch::optim::Adam(model->parameters(), torch::optim::AdamOptions(0.0001)); // 第二个参数是学习率

    // 调用训练
    std::cout << "开始训练" << std::endl;
    for(int n = 0; n < epoch; n++){
        std::printf("第%03d轮\n", n+1);
        train(model, *train_loader, optimizer);
        if(n % 5 == 0){
            valid(model, *test_loader);
        }
    }
    // 结束的时候再校验一次
    valid(model, *test_loader);
    std::cout << "训练结束" << std::endl;
    // 训练完毕保存模型
    torch::save(model, "lenet5.pt");
    return 0;
}
