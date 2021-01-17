#include "lenet5_reco.h"

torch::Tensor LeNet5Recognizer::pre_image(cv::Mat in_img){
    // std::cout << "图像预处理" << std::endl;
    // 1. 缩放
    cv::resize(in_img, in_img, cv::Size(28, 28));
    // 2. 灰度
    cv::cvtColor(in_img, in_img, cv::COLOR_BGR2GRAY);
    cv::imwrite("1_gray.png", in_img);
    // 3. 反转（黑白颠倒） ----------------- 
    in_img = 255 - in_img;
    cv::imwrite("2_inverse.png", in_img);
    // 4. 去噪
    int threhold = 165;
    for(int y = 0; y < in_img.rows; y++){
        uchar *lines = in_img.ptr<uchar>(y);
        for(int x = 0; x < in_img.cols; x++){
            // if(out_img.at<uchar>(y, x) > threhold){
            //    out_img.at<uchar>(y, x) = 255;
            // }
            // else{
            //     out_img.at<uchar>(y, x) = 0;
            // }
            if(lines[x] <= threhold){
                lines[x] = 0;
            }
        }
    }
    cv::imwrite("3_noise.png", in_img);
    // 5. 标准化
    in_img.convertTo(in_img, CV_32FC1, 1.0f / 255.0f);
    // 6. 转换为张量
    torch::Tensor t_img = torch::from_blob(in_img.data, {1, 28, 28});
    // 7. 格式化NCHW
    t_img = t_img.view({-1, 1, 28, 28});
    // std::cout << t_img << std::endl;
    // std::cout << "图像预处理完毕！" << std::endl;
    return t_img.clone();
}
LeNet5Recognizer::LeNet5Recognizer(std::string filename):
        model_file(filename),
        cls_id(-1),
        prob(0.0f){
    // 初始化
    
    net = std::make_shared<LeNet5>();
    torch::load(net, model_file);
    // std::cout << "构造器结束" << std::endl;
}
LeNet5Recognizer::~LeNet5Recognizer(){

}

void LeNet5Recognizer::recognize(cv::Mat &img){
    // 预处理
    torch::Tensor t_img = this->pre_image(img);
    // std::cout << t_img << std::endl;
    // 预测
    torch::Tensor y = net->forward(t_img);
    // std::cout << torch::sigmoid(y) << std::endl; 
    y = torch::sigmoid(y);
    // 处理预测结果
    cls_id = y.argmax(1).item<int32_t>();
    prob = y[0][cls_id].item<float>();
}
void LeNet5Recognizer::recognize_by_imgfile(std::string imgfile){
    // 打开图像
    cv::Mat img = cv::imread(imgfile);
    this->recognize(img);
}