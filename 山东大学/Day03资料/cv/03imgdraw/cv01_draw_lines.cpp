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
    /* 
    void cv::line(
        InputOutputArray img, 
        Point pt1, 
        Point pt2, 
        const Scalar &color, 
        int thickness=1, 
        int lineType=LINE_8, 
        int shift=0)
    */
    cv::line(
       image,                       // 绘制的图像缓冲
       cv::Point(0, 0),             // 绘制直线的开始点
       cv::Point(WIN_W, WIN_H),     // 绘制直线的结束点
       cv::Scalar(255, 0, 0, 0),    // 绘制直线的颜色(BGRA)或者使用cv::RGB()宏
       5,                           // 线条的粗细
       cv::LINE_AA,                 // 绘制线条的算法
       0                            // 坐标点的小数位数
    );
    cv::imshow("Win_draw", image);
    ///////////////////////////////////

    cv::waitKey();
    return 0;
}

// 编译命令：g++  -omain  cv01_draw_lines.cpp -std=c++11 -I/usr/local/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
