#include "clenet.h"

CLenet::CLenet():
    conv1(torch::nn::Conv2dOptions(1, 6, 5).stride(1).padding(2)),  // 1 * 28 * 28 -> 6 * 28 * 28 -> 6 * 14 * 14
    conv2(torch::nn::Conv2dOptions(6, 16, 5).stride(1).padding(0)),  // 6 * 14 * 14 -> 16 * 10 * 10 -> 16 * 5 * 5
    conv3(torch::nn::Conv2dOptions(16, 120, 5).stride(1).padding(0)), // 16 * 5 * 5 -> 120 * 1 * 1 (不需要池化)
    fc1(120, 84),  // 120 -> 84
    fc2(84, 10){
        register_module("conv1", conv1);
        register_module("conv2", conv2);
        register_module("conv3", conv3);
        register_module("fc1", fc1);
        register_module("fc2", fc2);
}

torch::Tensor CLenet::forward(torch::Tensor x){
        // 1. conv
        x = conv1->forward(x);   // {n * 6 * 28 * 28}
        x = torch::max_pool2d(x, 2);   // {n * 6 * 14 * 14}
        x = torch::relu(x); // 激活函数 // {n * 6 * 14 * 14}
        // 2. conv
        x = conv2->forward(x);   // {n * 16 * 10 * 10}
        x = torch::max_pool2d(x, 2);   // {n * 16 * 5 * 5}
        x = torch::relu(x); // 激活函数 // {n * 16 * 5 * 5}
        // 3. conv
        x = conv3->forward(x);   // {n * 120 * 1 * 1}
        x = torch::relu(x); // 激活函数 // {n * 120 * 1 * 1}
        // 做数据格式转换
        x = x.view({-1, 120});   // {n * 120}
        // 4. fc
        x = fc1->forward(x);
        x = torch::relu(x);
        
        // 5. fc 
        x = fc2->forward(x);
        return  torch::log_softmax(x, 1);   // CrossEntryLoss = log_softmax + nll
}
