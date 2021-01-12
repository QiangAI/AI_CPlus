
#include <torch/torch.h>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    std::cout << "开始" << std::endl; 
    // 数据集
    torch::data::datasets::MNIST train_dataset = torch::data::datasets::MNIST(".\\data");
    std::cout << "加载数据集" << std::endl;
    torch::data::datasets::MapDataset<torch::data::datasets::MNIST, torch::data::transforms::Normalize<> > m_dataset = train_dataset.map(torch::data::transforms::Normalize<>(0.1307, 0.3081));
    std::cout << "归一化数据集" << std::endl;
    torch::data::datasets::MapDataset<torch::data::datasets::MapDataset<torch::data::datasets::MNIST, torch::data::transforms::Normalize<> >, torch::data::transforms::Stack<> > s_dataset = m_dataset.map(torch::data::transforms::Stack<>());
    std::cout << "打包数据集" << std::endl;

    // 创建数据集加载器（用来把数据集分成批次）
    auto dataloader = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(std::move(s_dataset), 10000);
    std::cout << typeid(dataloader).name() << std::endl;
    /*
        放弃使用真正的类型，直接使用auto来交给编译器自动推导，这正类型如下： 
        class std::unique_ptr<
            class torch::data::StatelessDataLoader<
                class torch::data::datasets::MapDataset<
                    class torch::data::datasets::MapDataset<
                        class torch::data::datasets::MNIST,struct torch::data::transforms::Normalize<class at::Tensor> 
                    >,
                    struct torch::data::transforms::Stack<
                        struct torch::data::Example<class at::Tensor,class at::Tensor> 
                    > 
                >,
                class torch::data::samplers::SequentialSampler
            >,
            struct std::default_delete<
                class torch::data::StatelessDataLoader<
                    class torch::data::datasets::MapDataset<
                        class torch::data::datasets::MapDataset<
                            class torch::data::datasets::MNIST,
                            struct torch::data::transforms::Normalize<
                                class at::Tensor
                            > 
                        >,
                        struct torch::data::transforms::Stack<
                            struct torch::data::Example<
                                class at::Tensor,class at::Tensor
                            > 
                        > 
                    >,
                    class torch::data::samplers::SequentialSampler
                > 
            > 
        > 
    */

    /*
        StatelessDataLoader -> DataLoaderBase 
                                    |- begin -> Iterator<Batch>
                                    |- end -> Iterator<Batch>
                                    |- next -> optional<BatchType>
    */
    for(torch::data::Example<>& batch : *dataloader){  // 循环获取每个批次的图像
        // 获取图像
        torch::Tensor data = batch.data;
        // 获取标签
        torch::Tensor label = batch.target;

        // 查看批次图像数据的批次数量
        std::cout << "批次数量：" << data.sizes() << std::endl;
        int64_t  batch_size = data.sizes()[0];
        
        // 获取批次中第一幅图像
        torch::Tensor img = data[0];
        std::cout << img.sizes() << std::endl;
        
        // 标签打印
        // std::cout << label << std::endl;
        std::cout << label[0] << std::endl;
        std::cout << label.data_ptr<int64_t>()[0] << std::endl;
        break; // 不想打印太多，直接结束

    }
    return 0;
}
