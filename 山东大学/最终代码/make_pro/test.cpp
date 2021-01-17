#include "models/lenet5_reco.h"
// 测试推理封装
int main(){
    // 构造一个识别对象
    LeNet5Recognizer reco("pts\\lenet5_digit.pt");
    // 调用识别函数
    reco.recognize_by_imgfile("00019.png");
    // 获取识别结果
    std::cout<< "----------------------------" << std::endl;
    std::cout<< reco.cls_id << ":" << reco.prob << std::endl;
    reco.recognize_by_imgfile("img_02_4.png");
    // 获取识别结果
    std::cout<< "----------------------------" << std::endl;
    std::cout<< reco.cls_id << ":" << reco.prob << std::endl;

     reco.recognize_by_imgfile("img_04_9.png");
    // 获取识别结果
    std::cout<< "----------------------------" << std::endl;
    std::cout<< reco.cls_id << ":" << reco.prob << std::endl;

     reco.recognize_by_imgfile("img_03_1.png");
    // 获取识别结果
    std::cout<< "----------------------------" << std::endl;
    std::cout<< reco.cls_id << ":" << reco.prob << std::endl;
    return 0;
}
