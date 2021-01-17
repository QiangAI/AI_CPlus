// #include <opencv2/opencv.hpp>
#include "app.h"
#include <QtCore/QMetaType>

Q_DECLARE_METATYPE(cv::Mat)

App::App(int argc, char **argv):
        QApplication(argc, argv), 
        frame(new MainFrame()){
    // 构造器
    
    qRegisterMetaType<cv::Mat>("Mat");
    qRegisterMetaType<cv::Mat>("Mat&");
    frame->show();
}
App::~App(){
    delete frame;
}