#include <opencv2/opencv.hpp>
#include <iostream>
#define WIN_W 400
#define WIN_H 300

int main(int argc, const char** argv) {
    cv::namedWindow("Win_draw", cv::WINDOW_NORMAL);
    cv::resizeWindow("Win_draw", WIN_W, WIN_H);
    cv::moveWindow("Win_draw", (1280 - WIN_W) / 2, (800 - WIN_H) / 2);
    ///////////////////////////////////
    // 构造一副图像
    cv::Mat  image(WIN_H, WIN_W, CV_8UC4);      // 图像格式4个无符号字节（存放RGBA像素）

    cv::putText(
        image,
        "Hello OpenCV",     // 汉字存在问题，后面单独处理
        cv::Point(20,100),
        cv::FONT_HERSHEY_COMPLEX,
        1.5,
        CV_RGB(255,0,0),
        2,
        cv::LINE_AA,
        false   // 图像的原点左下角（true）与左上角（false）的区别
    );
    cv::imshow("Win_draw", image);
    ///////////////////////////////////

    cv::waitKey();
    return 0;
}

// 编译命令：g++  -omain  cv11_draw_text.cpp -std=c++11 -I/usr/local/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
