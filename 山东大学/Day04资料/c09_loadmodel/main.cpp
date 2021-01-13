
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
    const char * data_dir = ".\\data";
    // 模型
    std::shared_ptr<Lenet5> model = std::make_shared<Lenet5>();
    // 数据集 - 测试数据集
    auto test_dataset  = torch::data::datasets::MNIST(data_dir, torch::data::datasets::MNIST::Mode::kTest)
            .map(torch::data::transforms::Normalize<>(0.1307, 0.3081))
            .map(torch::data::transforms::Stack<>());
    auto test_loader  = torch::data::make_data_loader(std::move(test_dataset), 10000);
    std::cout << "加载模型" << std::endl;
    // 训练完毕保存模型
    torch::load(model, "lenet5.pt");
    // 识别测试
    valid(model, *test_loader);

    // 识别一张图片
    auto test_img = torch::data::datasets::MNIST(data_dir, torch::data::datasets::MNIST::Mode::kTest);
    torch::data::Example<> ex = test_img.get(2);
    torch::Tensor img = ex.data;
    torch::Tensor lab = ex.target;

    // 规范化
    torch::data::transforms::Normalize<> norm(0.1307, 0.3081);
    img = norm(img);

    std::cout << img.sizes() << std::endl;
    // 改变格式
    img = img.view({-1, img.sizes()[0], img.sizes()[1], img.sizes()[2]});
    auto pred = model->forward(img);
    int p = pred.argmax(1).item<int>();
    std::cout << lab.item<int>() << " -> " << p << std::endl;

    return 0;
}
