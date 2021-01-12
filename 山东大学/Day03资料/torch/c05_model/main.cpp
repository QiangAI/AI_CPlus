
#include <torch/torch.h>
#include <opencv2/opencv.hpp>
/**
 * 卷积选项的使用：Conv2dOptions(3, 2, 3).stride(1).bias(false)
 * 构造器：
 *  ConvOptions(
 *      int64_t in_channels,
 *      int64_t out_channels,
 *      ExpandingArray<D> kernel_size)
 * 可以扩展的参数：
 * TORCH_ARG(ExpandingArray<D>, stride) = 1;
 * TORCH_ARG(ExpandingArray<D>, padding) = 0;
 * TORCH_ARG(ExpandingArray<D>, dilation) = 1;    // 核膨胀
 * TORCH_ARG(int64_t, groups) = 1;
 * TORCH_ARG(bool, bias) = true;
 */

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
        std::cout << "Conv-1:" << x.sizes() << std::endl;
        // 第二个卷积层
        x = conv2->forward(x);
        x = torch::max_pool2d(x, 2);
        x = torch::relu(x);
        std::cout << "Conv-2:" << x.sizes() << std::endl;
        // 第三卷积层
        x = conv3->forward(x);
        std::cout << "Conv-3:" << x.sizes() << std::endl;
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

int main(int argc, char **argv){
    cv::Mat im = cv::imread("5.png");
    im.convertTo(im, CV_32FC1, 1.0f / 255.0f);   // 参数im是输出
    torch::Tensor in_tensor = torch::from_blob(im.data, {1, im.rows, im.cols, 1}); // 图像数量，图像高，宽，通道
    //pytorch 使用两种格式 N*C*H*W （或者 N*H*W*C） 
    in_tensor = in_tensor.permute({0, 3, 1, 2});  // 交换维度
    std::cout << in_tensor.sizes() << std::endl;
    // Lenet5对象- 共享指针：自动释放
    std::shared_ptr<Lenet5> net = std::make_shared<Lenet5>();
    torch::Tensor out_tensor = net->forward(in_tensor);
    std::cout << out_tensor << std::endl;
    // 预测模型
    torch::Tensor pred = out_tensor.argmax(1);
    std::cout << "预测结果:" << pred << std::endl;

    // Lenet5对象- 栈内存：根据生命周期释放///////////////////////////////////////////////////
    Lenet5 net2;
    torch::Tensor out_tensor2 = net2.forward(in_tensor);
    std::cout << out_tensor2 << std::endl;
    // 预测模型
    torch::Tensor pred2 = out_tensor2.argmax(1);
    std::cout << "预测结果:" << pred2 << std::endl;

    // Lenet5对象- 指针：手工释放///////////////////////////////////////////////////
    Lenet5 *net3 = new Lenet5();
    torch::Tensor out_tensor3 = net3->forward(in_tensor);
    std::cout << out_tensor3 << std::endl;
    // 预测模型
    torch::Tensor pred3 = out_tensor3.argmax(1);
    std::cout << "预测结果:" << pred3 << std::endl;
    delete net3;
    
    return 0;
}
