#include <QtWidgets/QApplication>
#include "cdialog.h"
#include <QtCore/QMetaType>
#include <opencv2/opencv.hpp>

Q_DECLARE_METATYPE(cv::Mat);

int main(int argc, char **argv){
    QApplication app(argc, argv);
    qRegisterMetaType<cv::Mat>("Mat");
    qRegisterMetaType<cv::Mat>("Mat&");
    CDialog dlg;
    dlg.show();
    return app.exec();

}