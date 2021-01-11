#include "video.h"
#include <iostream>

CameraDev::CameraDev():is_over(false), dev(new cv::VideoCapture(0, cv::CAP_DSHOW)){

}
CameraDev::~CameraDev(){
    delete dev;
}
void CameraDev::run(){
    while(!is_over){
        cv::Mat  img;
        dev->read(img);
        cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
        emit sig_video(img);
        QThread::usleep(100000);
    }
}
void CameraDev::close(){
    is_over=true;
    // 等待线程自然结束
    while (isRunning()){
    }
    std::cout << "线程结束" << std::endl;
    dev->release();
}