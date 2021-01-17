#include "video.h"
#include <iostream>
CameraDev::CameraDev():
    is_over(false),
    dev(new cv::VideoCapture(0, cv::CAP_DSHOW)){

}
CameraDev::~CameraDev(){
    delete dev;
}
void CameraDev::run(){
    // run结束则线程就结束
    while (!is_over){
        // std::cout << "线程工作" << std::endl;
        // 抓取视频
        cv::Mat  img;
        dev->read(img);
        // std::cout << img.size << std::endl;
        // 进行颜色通道处理
        cv::cvtColor(img/*输入图像*/, img/*输出图像*/, cv::COLOR_BGR2RGB);
        emit sig_video(img);
        // 暂停
        QThread::usleep(100000);
    }
}

void CameraDev::close(){
    is_over = true;
    while (isRunning()){

    }
    std::cout << "线程结束" << std::endl;
    dev->release();
}