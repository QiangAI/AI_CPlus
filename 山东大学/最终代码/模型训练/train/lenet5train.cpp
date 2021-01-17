#include "lenet5train.h"

void train_one(
    class std::shared_ptr<class LeNet5> &net, 
    class torch::data::StatelessDataLoader<
        class torch::data::datasets::MapDataset<
            class torch::data::datasets::MapDataset<
                class torch::data::datasets::MNIST,
                struct torch::data::transforms::Normalize<class at::Tensor
            > 
        >,
        struct torch::data::transforms::Stack<
            struct torch::data::Example<
                class at::Tensor,class at::Tensor
            > 
        > 
    >,
    class torch::data::samplers::RandomSampler> &batch_ds, 
    class torch::optim::Optimizer &optimizer){
    net->train(); // 对我们的Lenet5模型没有意义， eval()/train() 开关函数：batchnorm/dropout
    // 训练的实现
    // 对批次数据循环
    size_t batch = 0; 
    for(const auto &a_batch : batch_ds){
        // forward向前计算输出
        torch::Tensor x = a_batch.data;   // NCHW
        torch::Tensor y = a_batch.target;
        optimizer.zero_grad();
        torch::Tensor y_ = net->forward(x);  // 计算预测结果
        // 计算误差
        torch::Tensor  loss = torch::nll_loss(y_, y);
        // 求导数
        loss.backward();
        // 更新的卷积核参数与分类矩阵
        optimizer.step();
        // optimizer.zero_grad();
        std::cout<< "\t - 批次：" << std::setw(2) << std::setfill('0') << ++batch << ", 误差损失:" << loss.data_ptr<float>()[0] << std::endl; 
    }

}

void valid(
    class std::shared_ptr<class LeNet5> &net, 
    class torch::data::StatelessDataLoader<
        class torch::data::datasets::MapDataset<
            class torch::data::datasets::MapDataset<
                class torch::data::datasets::MNIST,
                struct torch::data::transforms::Normalize<class at::Tensor
            > 
        >,
        struct torch::data::transforms::Stack<
            struct torch::data::Example<
                class at::Tensor,class at::Tensor
            > 
        > 
    >,
    class torch::data::samplers::RandomSampler> &batch_ds){
    // 提供了一个实现，禁止运算的求导图跟踪
    torch::NoGradGuard no_grad;  // 禁止下面的函数运算被求导，直到这个对象被释放
    float all_loss = 0.0f;
    int32_t  all_correct = 0;
    int32_t  all_samples = 0;

    net->eval();  // 关闭batchnorm/dropout的函数运算 
    // 循环数据集
    // for(const torch::data::Example<> &a_batch: batch_ds){
     for(const auto &a_batch: batch_ds){
        // 预测
        auto vx = a_batch.data;
        auto vy = a_batch.target;
        all_samples += vx.sizes()[0]; // 累积样本数量
        auto vy_ = net->forward(vx);
        // 处理，想得到预测结果
        auto predict = vy_.argmax(1);
        auto loss = torch::nll_loss(vy_, vy, {}, at::Reduction::Sum);   // 单热编码过程one-hot。
        // 处理结果：统计正确率，累积损失值
        all_loss += loss.item<float>();
        all_correct += predict.eq(vy).sum().item<int32_t>();
    }
    // 输出
    std::cout
        << "- 正确率：" << std::setfill(' ') << std::setw(8) << std::setprecision(6) << 100.0f * float(all_correct) / (float)all_samples << "%"
        << ", 测试集损失值：" << std::setw(8) << std::setprecision(6)  << all_loss / all_samples
        << std::endl;
}
