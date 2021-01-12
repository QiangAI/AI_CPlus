#ifndef IMAGE_PROCESS_H
#define IMAGE_PROCESS_H
#include <opencv2/opencv.hpp>
class ImageProc{
private:
    cv::String *filename_image;     // 文件名：std::string

public:
    cv::Mat m_src;                  // 原始图像的数据结构
    cv::Mat m_gray;                 // 灰度图像
    cv::Mat m_grad_x_16;               // 梯度图-x
    cv::Mat m_grad_y_16;               // 梯度图-y
    cv::Mat m_grad_x;               // 梯度图-x
    cv::Mat m_grad_y;               // 梯度图-y
    cv::Mat m_canny;                // 边缘图
public:
    ImageProc();
    ImageProc(const char *filename);
    ~ImageProc();

    void toGray();
    void toGradient();
    void toCanny();
};
#endif // ! IMAGE_PROCESS_H
