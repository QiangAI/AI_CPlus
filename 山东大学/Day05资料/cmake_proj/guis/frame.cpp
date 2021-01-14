#include "frame.h"
#include <iostream>
MainFrame::MainFrame(): 
        ui(new Ui::Camera()), 
        dev(new CameraDev()){
    ui->setupUi(this);
    // 启动多线程
    dev->start();
    // 绑定后信号与槽
    QObject::connect(dev, SIGNAL(sig_video(cv::Mat)), this, SLOT(show_video(cv::Mat)));
}
MainFrame::~MainFrame(){
    delete ui;
    delete dev;
}
void MainFrame::closeEvent(QCloseEvent *e){
    // std::cout << "关闭窗体，释放设备！" << std::endl;
    dev->close();
}

void MainFrame::capture(){
    std::cout << "抓图" << std::endl;
}
void MainFrame::recognize(){
    std::cout << "识别" << std::endl;
}

void MainFrame::show_video(cv::Mat img){
    // 负责显示img图像
    // std::cout << "有信号" << std::endl;
    // 把opencv的矩阵转换为QImage
    QImage q_img(img.data, img.cols, img.rows, QImage::Format_RGB888);  // 有的版本不支持Format_BGR888
    // 把QImage转换像素图QPixelmap
    QPixmap p_img = QPixmap::fromImage(q_img);
    // 设置到标签框
    ui->lbl_video->setPixmap(p_img);
}
