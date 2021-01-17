#ifndef LENET_5_H
#define LENET_5_H
#include <torch/torch.h>

class LeNet5 : public torch::nn::Module{
private:
    // 定义运算
    torch::nn::Conv2d  conv1;
    torch::nn::Conv2d  conv2;
    torch::nn::Conv2d  conv3;

    torch::nn::Linear  fc1;
    torch::nn::Linear  fc2;
public:
    LeNet5();
    virtual torch::Tensor forward(torch::Tensor);

};
#endif
