#ifndef LENET_5_RECO_H
#define LENET_5_RECO_H
#include <opencv2/opencv.hpp>
#include <torch/torch.h>
#include "lenet5.h"

class LeNet5Recognizer{
private:
    // 前置条件
    std::shared_ptr<LeNet5> net;
    std::string model_file;
    // 中间数据

    // 内部的处理函数
    torch::Tensor pre_image(cv::Mat in_img);


public:
    // 后置数据
    int32_t cls_id;  /* 识别的类别id     */
    float prob;  /* 识别的类别的概率 */
    LeNet5Recognizer(std::string filename);
    ~LeNet5Recognizer();

    void recognize(cv::Mat &img);
    void recognize_by_imgfile(std::string imgfile);  
};
#endif
