#include "imageprocess.h"

ImageProc::ImageProc():
    filename_image(new cv::String("lotus.png")){
    m_src = cv::imread(*filename_image);
}
ImageProc::ImageProc(const char *filename):
    filename_image(new cv::String(filename)){
    m_src = cv::imread(*filename_image);
}
ImageProc::~ImageProc(){
    delete filename_image;
    m_src.release();
}
void ImageProc::toGray(){
    cv::cvtColor(m_src, m_gray,cv::COLOR_BGR2GRAY);
}
// 计算梯度
void ImageProc::toGradient(){
    cv::Sobel(m_gray, m_grad_x_16, CV_16SC1, 1, 0, 3);  // 最后参数3表示kernel的大小
    cv::Sobel(
        m_gray,             // 输入的灰度图像
        m_grad_y_16,        // 输出的CV_16SC1类型的梯度（可以输出位CV_8UC1），但在Canny函数需要CV_16SC1的格式
        CV_16SC1, 
        0, 
        1, 
        3);

    m_grad_x_16.convertTo(m_grad_x, CV_8UC1);   // 转换为颜色CV_8UC1格式（便于Qt显示）
    m_grad_y_16.convertTo(m_grad_y, CV_8UC1);       

}
// 边缘检测
void ImageProc::toCanny(){
    /* cv::Canny(
        m_gray,         // 输入的灰度图
        m_canny,        // 输出的边缘图
        150,            // 过滤的最小阈值
        255,            // 过滤的最大阈值
        3,              // 使用sobel计算x与y梯度的kernel的大小。
        true);          // x与y梯度转换为像素的梯度的计算方式1-范数与2范数。
    */
    cv::Canny(          // 与上面效果一样
        m_grad_x_16,    // x梯度- 必须是CV_16S1或者CV_16S3类型
        m_grad_y_16,    // y梯度- 必须是CV_16S1或者CV_16S3类型
        m_canny,        // 输出边缘图像
        150,            // 过滤的最小阈值
        255,            // 过滤的最大阈值
        true);          // x与y梯度转换为像素的梯度的计算方式1-范数与2范数。
}
