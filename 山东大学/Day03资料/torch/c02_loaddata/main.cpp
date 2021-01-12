
#include <torch/torch.h>



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
    torch::data::Example<> ex = train_dataset.get(0);
    torch::Tensor data = ex.data;
    torch::Tensor target = ex.target;
    std::cout << data << std::endl;
    std::cout << target << std::endl;   // 数字5
}
