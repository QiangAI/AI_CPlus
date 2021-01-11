#include "cvideo.h"

CVideo::CVideo(QObject *parent):
    QThread(parent),
    dev(new cv::VideoCapture(0, cv::CAP_DSHOW)){
}
CVideo::~CVideo(){
    dev->release();
    delete dev;
}

void CVideo::run(){
    while(true){
        cv::Mat  img;
        dev->read(img);
        cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
        emit sig_video(img);
        QThread::usleep(100000);
    }
}
