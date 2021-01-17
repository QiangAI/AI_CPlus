#include "train/lenet5train.h"
#include <iostream>
#include <torch/torch.h>
#include <string>
#include "model/lenet5.h"


int main(int args, char *argv, char *arge){
    std::string datapath = ".\\data";
    std::string modle_file = "lenet5_digit.pt";
    // 超参数
    std::cout << "1. 定义超参数" << std::endl;    
    size_t  epoch = 50;             // 训练的轮数
    size_t  interval = 10;           // 测试验证的周期
    size_t  batch_size = 1000;      // 批次数
    float   learninng_rate = 0.0001; // 学习率（控制求损失值最小中梯度下降的速度）
    
    // 批次数据集（NCHW）
    // std::cout << "2. 加载数据集" << std::endl;
    // torch::data::datasets::MNIST ds_train 
    //     = torch::data::datasets::MNIST(datapath, torch::data::datasets::MNIST::Mode::kTrain); // 训练数据集
    // torch::data::datasets::MNIST ds_valid 
    //     = torch::data::datasets::MNIST(datapath, torch::data::datasets::MNIST::Mode::kTest);  // 测试数据集
    
    ///////////////////////////////////////////////////
    // 归一化操作
    // torch::data::transforms::Normalize<> normal(0.1307, 0.3081); 
    // torch::data::datasets::MapDataset<
    //     torch::data::datasets::MNIST, 
    //     torch::data::transforms::Normalize<> > n_train =  ds_train.map(normal);
    // 打包的操作
    // torch::data::transforms::Stack<> stack;    // CHW -stack-> NCHW
    // torch::data::datasets::MapDataset<
    //     torch::data::datasets::MapDataset<
    //         torch::data::datasets::MNIST, 
    //         torch::data::transforms::Normalize<> 
    //     >, 
    //     torch::data::transforms::Stack<> > s_train = n_train.map(stack);

    std::cout << "2. 加载训练集，并打包成批次数据集" << std::endl;
    auto s_train = torch::data::datasets::MNIST(datapath, torch::data::datasets::MNIST::Mode::kTrain)
        .map(torch::data::transforms::Normalize<>(0.1307, 0.3081))
        .map(torch::data::transforms::Stack<>());
    auto batch_train = torch::data::make_data_loader<>(std::move(s_train), batch_size); 

    std::cout << "3. 加载测试集，并打包成批次数据集" << std::endl;
    auto s_valid = torch::data::datasets::MNIST(datapath, torch::data::datasets::MNIST::Mode::kTest)
        .map(torch::data::transforms::Normalize<>(0.1307, 0.3081))
        .map(torch::data::transforms::Stack<>());
    auto batch_valid = torch::data::make_data_loader<>(std::move(s_valid), batch_size); 
    // std::cout << typeid(batch_train).name() << std::endl;
    // int i = 0 ;
    // for( torch::data::Example<>& a_batch : *batch_valid){
    // for(const auto &a_batch : *batch_train){
    //     std::cout << i++ << std::endl;
    //     std::cout << a_batch.data.sizes() << std::endl; 
    // }
    ////////////////////////////////////////////////////////////////////////////////////
    // 优化器 （根据求导的结果，+-权重系数）
    std::cout << "4. 定义优化器" << std::endl;
    // 定义网络
    std::shared_ptr<LeNet5> net = std::make_shared<LeNet5>();

    // 加载上次训练结果，从上次结束处开始继续训练
    std::cout << "加载已有模型" << std::endl;
    torch::load(net, modle_file);
    // 选项
    // torch::optim::AdamOptions options(learninng_rate);
    // 构造优化器
    torch::optim::Adam optimizer(net->parameters(), torch::optim::AdamOptions(learninng_rate));

    // 开始训练
    std::cout << "5. 开始训练，轮数：" << epoch << std::endl;
    for(int e = 0; e < epoch; e++){
        std::cout << "训练轮数：" << std::setw(3) << std::setfill('0')<< e << std::endl;
        train_one(net, *batch_train, optimizer);
        if (e % interval == 0){
            valid(net, *batch_valid);
            // 这儿也可以保存
        }
        // 保存模型
        std::cout << "- 保存模型....." << std::endl;
        torch::save(net, modle_file);
    }

    return 0;
}