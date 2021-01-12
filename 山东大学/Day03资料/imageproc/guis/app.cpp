#include "app.h"

#include <QtCore/QMetaType>
#include <opencv2/opencv.hpp>

Q_DECLARE_METATYPE(cv::Mat);

App::App(int argc, char **argv): 
        QApplication(argc, argv), 
        frame(new MainFrame()){
    qRegisterMetaType<cv::Mat>("Mat");
    qRegisterMetaType<cv::Mat>("Mat&");
    frame->show();

}

App::~App(){
    delete frame;
}

