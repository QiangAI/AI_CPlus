#ifndef IMGS_H
#define IMGS_H
#include <opencv2/opencv.hpp>
void image_format(cv::Mat&);
void gaussian_blur(cv::Mat&, cv::Mat&);
void conv(cv::Mat&, cv::Mat&);
void sobel(cv::Mat&, cv::Mat&);
#endif
