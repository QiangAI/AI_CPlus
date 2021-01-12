#include "dlgcanny.h"

#include <iostream>
// 构造器与析构器
DlgCanny::DlgCanny(QWidget *parent):
        QDialog(parent),
        dlg(new Ui::dlg_canny),
        proc(new ImageProc()){
    dlg->setupUi(this);
}
DlgCanny::~DlgCanny(){
    delete dlg;
    delete proc;
}
// 显示图像到指定组件 
void DlgCanny::showGrayImage(cv::Mat img, QLabel *container){
    if(img.empty() || ! container ) return;   // 图像与现实容器都非空才处理

    cv::Mat  m_out;
    // OpenCV到Qt的颜色格式转换
    cv::cvtColor(img, m_out, cv::COLOR_GRAY2RGBA); 
    // 转换为Qt图像
    QImage i_out(m_out.data, m_out.cols, m_out.rows, QImage::Format_RGBA8888);
    // 转换为组件能处理的像素格式
    QPixmap p_out = QPixmap::fromImage(i_out);
    // 显示图像
    container->setPixmap(p_out);
    // 缩放图像适应组件大小
    container->setScaledContents(true);
}
// 显示事件
void DlgCanny::showEvent(QShowEvent *event){
    // 原图转换为灰度图像，
    proc->toGray();
    // 显示灰度图像
    showGrayImage(proc->m_gray, dlg->lbl_gray);
}

void DlgCanny::canny(){
    // 梯度图计算
    proc->toGradient();
    // 显示梯度图
    showGrayImage(proc->m_grad_x, dlg->lbl_x_grad);
    showGrayImage(proc->m_grad_y, dlg->lbl_y_grad);
    // 边缘检测计算
    proc->toCanny();
    // 显示边缘图
    showGrayImage(proc->m_canny, dlg->lbl_canny);
}
