#ifndef LENET5_TRAIN_H
#define LENET5_TRAIN_H
#include "../model/lenet5.h"
#include <torch/torch.h>
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
    class torch::optim::Optimizer &optimizer);

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
    class torch::data::samplers::RandomSampler> &batch_ds);

#endif
