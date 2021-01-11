#include "./frame.h"
#include <iostream>

MainFrame::MainFrame():ui(new Ui::Camera()), dev(new CameraDev()){
    std::cout<<"构造器"<<std::endl;
    ui->setupUi(this);
    dev->start();
    QObject::connect(dev, SIGNAL(sig_video(cv::Mat)), this, SLOT(show_video(cv::Mat)));
}
MainFrame::~MainFrame(){
    std::cout<<"析构器"<<std::endl;
    delete ui;
    delete dev;
}

void MainFrame::closeEvent(QCloseEvent *e){
    dev->close();
}

void MainFrame::show_video(cv::Mat img){     
    QImage i_out(img.data, img.cols, img.rows, QImage::Format_RGB888);
    QPixmap p_out = QPixmap::fromImage(i_out); 
    ui->lbl_video->setPixmap(p_out);
    ui->lbl_video->setScaledContents(true);   
}
