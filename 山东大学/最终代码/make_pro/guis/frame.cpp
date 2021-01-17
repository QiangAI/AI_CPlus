#include "../models/lenet5_reco.h"
#include "frame.h"
#include <iostream>
#include <stdio.h>
MainFrame::MainFrame(): 
        ui(new Ui::Camera()), 
        dev(new CameraDev()),
        is_capture(false){
    ui->setupUi(this);
    // 识别器
    // reco = new LeNet5Recognizer("pts\\lenet5_digit.pt");
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
    is_capture = true;
}
void MainFrame::recognize(){
    std::cout << "识别" << std::endl;
    LeNet5Recognizer *reco = new LeNet5Recognizer("pts\\lenet5_digit.pt");
    reco->recognize(img_capture);
    int32_t clis_id = reco->cls_id;
    float prob = reco->prob;
    char s_result[128] = {0};
    sprintf(s_result, "%d，%4.2f", clis_id, prob);
    ui->lbl_digit_result->setText(s_result);
    delete reco;
}

void MainFrame::show_video(cv::Mat img){
    if (is_capture){
        img_capture = img.clone();
        is_capture = false;
        // 显示
        QImage _qimg(img_capture.data, img_capture.cols, img_capture.rows, QImage::Format_RGB888);  // 有的版本不支持Format_BGR888
        // 把QImage转换像素图QPixelmap
        QPixmap _pimg = QPixmap::fromImage(_qimg);
        // 设置到标签框
        ui->lbl_digit_image->setPixmap(_pimg);
        ui->lbl_digit_image->setScaledContents(true);
    }
    // 负责显示img图像
    // std::cout << "有信号" << std::endl;
    // 把opencv的矩阵转换为QImage
    QImage q_img(img.data, img.cols, img.rows, QImage::Format_RGB888);  // 有的版本不支持Format_BGR888
    // 把QImage转换像素图QPixelmap
    QPixmap p_img = QPixmap::fromImage(q_img);
    // 设置到标签框
    ui->lbl_video->setPixmap(p_img);
    ui->lbl_video->setScaledContents(true);
}
