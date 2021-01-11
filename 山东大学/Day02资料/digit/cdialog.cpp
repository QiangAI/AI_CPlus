#include "clenet.h"
#include "cdialog.h"
#include <iostream>
CDialog::CDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::digit()),
    video(new CVideo()),
    get_(0),
    identify_(0){
        ui->setupUi(this);
        QObject::connect(video, SIGNAL(sig_video(cv::Mat)), this, SLOT(show_video(cv::Mat)));
        video->start();
}
CDialog::~CDialog(){
    delete ui;
    delete video;
}
void CDialog::get(){
    get_ = 1;
}
void CDialog::identify(){
    identify_ = 1;
}

void CDialog::show_video(cv::Mat img){
    cv::Mat im = img;
    if(get_ == 1){
        QImage ii_out(im.data, im.cols, im.rows, QImage::Format_RGB888);
        QPixmap pp_out = QPixmap::fromImage(ii_out);
        ui->label2->setPixmap(pp_out);
        ui->label2->setScaledContents(true);
        get_ = 0;
    }
    if(identify_ == 1){
        char a[15]={};
        ui->label3->clear();
        std::shared_ptr<CLenet> model = std::make_shared<CLenet>();
        torch::load(model, "lenet5.pt");
        // 缩放图像
        cv::resize(im, im, cv::Size(28,28));
        cv::cvtColor(im, im, cv::COLOR_BGR2GRAY);
        // 黑白交换下
        im = 255 - im; 

        // 过滤噪音
        for(int y = 0; y < im.rows; y++){ // 访问行
            uchar* row = im.ptr<uchar>(y);  // 获取行首地址
            // 遍历处理列（这里通道为1，可以不考虑通道情况）
            for(int x = 0; x < im.cols; x++){
                if(row[x] < 150){
                    row[x] = 0;
                }
            }  
        } 
        im.convertTo(im, CV_32FC1, 1.0f / 255.0f);
        torch::Tensor  t_img = torch::from_blob(im.data, {1, 28, 28});
        t_img = t_img.view({-1, 1, 28, 28});
        torch::Tensor  y_ = model->forward(t_img);
        int32_t pred = y_.argmax(1).item<int32_t>();
        sprintf(a,"识别结果:%d",pred);
        ui->label3->setText(a);
        identify_ = 0;
    }
    QImage i_out(img.data, img.cols, img.rows, QImage::Format_RGB888);
    QPixmap p_out = QPixmap::fromImage(i_out);
    ui->label1->setPixmap(p_out);
    ui->label1->setScaledContents(true);
}

void CDialog::closeEvent(QCloseEvent *e){
    video->terminate(); // 终止线程，再退出
}