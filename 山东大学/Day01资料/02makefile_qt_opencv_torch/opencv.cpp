#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv, char** arge){
    cv::Mat  img = cv::imread("gpu.bmp");
    std::cout << "图像大小：" << img.size[0] << "," << img.size[0] << std::endl;
    std::cout << "图像大小：" << img.size << std::endl;
    return 0;
}

