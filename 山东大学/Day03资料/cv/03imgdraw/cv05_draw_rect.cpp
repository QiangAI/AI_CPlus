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
    /*  参数简单明了。
    // 第一个函数指定矩形的左下角与右上角点
    void cv::rectangle (InputOutputArray img, Point pt1, Point pt2, const Scalar &color, int thickness=1, int lineType=LINE_8, int shift=0)
    // 第二个函数指定矩形左上角与高宽
    void cv::rectangle (
        InputOutputArray img, 
        Rect rec,      // 矩形参数
        const Scalar &color, 
        int thickness=1, 
        int lineType=LINE_8, 
        int shift=0)
    */
   cv::rectangle(
       image,
       cv::Rect(10,100,200,200),   // 左下角顶点与高宽
       CV_RGB(255,0,0),
       2,
       cv::LINE_AA,
       0
    );
    cv::imshow("Win_draw", image);
    ///////////////////////////////////

    cv::waitKey();
    return 0;
}

// 编译命令：g++  -omain  cv05_draw_rect.cpp -std=c++11 -I/usr/local/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
