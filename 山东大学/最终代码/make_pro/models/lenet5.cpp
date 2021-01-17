#include "lenet5.h"

LeNet5::LeNet5():
        conv1(torch::nn::Conv2dOptions( 1,   6, 5).stride(1).padding(2)),
        conv2(torch::nn::Conv2dOptions( 6,  16, 5).stride(1).padding(0)),
        conv3(torch::nn::Conv2dOptions(16, 120, 5).stride(1).padding(0)),
        fc1(120, 84),
        fc2(84, 10){
    // 注册运算（构造权重矩阵，而且初始化）
    register_module("conv1", conv1);
    register_module("conv2", conv2);
    register_module("conv3", conv3);
    register_module("fc1", fc1);
    register_module("fc2", fc2);

}
torch::Tensor LeNet5::forward(torch::Tensor x){  // x -> NCHW
    // 运算
    // 第01层
    x = conv1->forward(x);
    x = torch::max_pool2d(x, 2);    // 池化
    x = torch::relu(x);             // 激活
    // 
    x = conv2->forward(x);
    x = torch::max_pool2d(x, 2);    // 池化
    x = torch::relu(x);             // 激活
    // 
    x = conv3->forward(x);
    x = torch::relu(x);             // 激活 NCHW
    // 数据格式转换
    x = x.view({-1, 120});          // NV

    // 
    x = fc1->forward(x);
    x = torch::relu(x);
    //
    x = fc2->forward(x);
    // 概率转换
    x = torch::log_softmax(x, /*dim=*/1);  
    return x;
}
