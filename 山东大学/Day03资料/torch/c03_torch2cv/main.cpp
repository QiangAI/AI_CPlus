
#include <torch/torch.h>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    std::cout << "开始" << std::endl; 
    // 数据集
    torch::data::datasets::MNIST train_dataset = torch::data::datasets::MNIST(".\\data");
    std::cout << "加载数据集" << std::endl;
    

    // 获取数据
    /*
        MNIST
        /// 获取指定位置的手写数字图像
        Example<> get(size_t index) override;
        /// 返回数据集的大小
        optional<size_t> size() const override;

        /// 返回一个状态来说明加载得是训练集还是测试集；
        bool is_train() const noexcept;

        /// 返回一个所有图像都打包一起得张量
        const Tensor& images() const;

        /// 返回对应所有图像的所有标签
        const Tensor& targets() const;
    */
    c10::optional<size_t> s = train_dataset.size();
    std::cout << "数据个数：" << s.value() << std::endl;
    torch::data::Example<> ex = train_dataset.get(2);
    torch::Tensor data = ex.data;
    torch::Tensor target = ex.target;
    std::cout << data << std::endl;
    std::cout << target << std::endl;   // 数字5

    // 使用opencv保存图像
    c10::IntArrayRef  sz = data.sizes();
    std::cout << "维度：" << sz << "(" << sz[0] << "," << sz[1]<< "," << sz[2] << ")" << std::endl;   // 数字5
    int64_t dim = data.dim();
    std::cout << "维数：" << dim << std::endl;   // 数字5
    int d1 = data.size(1);
    std::cout << "第2维长度：" << d1 << std::endl;   // 数字5

    // Opencv的图像都使用uint8类型，而且都是0-255，所以需要扩大255倍，并转换为uint8
    torch::Tensor cv_tensor = data.mul(255).clamp(0, 255).to(torch::kU8);  // 先乘255，缩放到0-255之间，然后转换
    // opencv的图像
    cv::Mat img(sz[1], sz[2], CV_8UC1);
    // 内存拷贝
    std::memcpy((void *) img.data, cv_tensor.data_ptr(), sizeof(torch::kU8) * cv_tensor.numel());    // numel = number of element
    // 保存
    cv::imwrite("5.png", img);


    // 页可以把cv::Mat图像转换为torch::Tensor
    // 读取图像
    cv::Mat im = cv::imread("5.png");
    std::cout << im.size << "," << im.dims << std::endl;
    // cv::cvtColor(im, im, cv::COLOR_BGR2RGB);   // 如果是三通道彩色图像，需要转换下像素格式。
    // 把图像转换为0-1之间的小数
    im.convertTo(im, CV_32FC1, 1.0f / 255.0f);
    // 转换为张量
    
    std::cout << im.rows << "," << im.cols << "," << im.depth() << "," << im.channels() << std::endl;
    torch::Tensor t_tensor = torch::from_blob(im.data, {1, im.rows, im.cols, 1}); // 图像数量，图像高，宽，通道
    //pytorch 使用两种格式 N*C*H*W 或者 N*H*W*C 
    t_tensor = t_tensor.permute({0, 3, 1, 2});  // 交换维度
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << t_tensor << std::endl;
    return 0;
}
