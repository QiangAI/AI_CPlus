#include "imgs.h"

void image_format(cv::Mat& img){
    for(int y = 0; y < img.rows; y++){
        for(int x = 0; x < img.cols; x++){
            cv::Vec3b& pixel = img.at<cv::Vec3b>(y, x);
            pixel[2] = 0;  // 改变颜色通道
        }
    }
}

void gaussian_blur(cv::Mat& in_img, cv::Mat& out_img){
    cv::GaussianBlur(in_img, out_img, cv::Size(9, 9), 10);
}
void conv(cv::Mat& in_img, cv::Mat& out_img){
    cv::Mat kernel = (cv::Mat_<int>(3, 3) << 1, 1, 1, 0, 0, 0, -1, -1, -1);
    cv::filter2D(in_img, out_img, -1, kernel, cv::Point(-1, -1), 200);
}
void sobel(cv::Mat& in_img, cv::Mat& out_img){
    cv::Sobel(in_img, out_img, -1, 1, 1, 3, 1.0, 200);
}
