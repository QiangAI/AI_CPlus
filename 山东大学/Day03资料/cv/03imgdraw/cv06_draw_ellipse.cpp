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
    void cv::ellipse (
        InputOutputArray img, 
        Point center,           // 椭圆的圆心
        Size axes,              // 长半轴与短半轴
        double angle,           // 倾斜角度(单位度数，不是弧度)
        double startAngle,      // 椭圆弧开始角度
        double endAngle,        // 椭圆弧结束角度
        const Scalar &color, 
        int thickness=1, 
        int lineType=LINE_8, 
        int shift=0)
    void cv::ellipse(
        InputOutputArray img, 
        const RotatedRect &box,   // 使用类封装椭圆的几个参数：圆心，长半轴与短半轴，角度
        const Scalar &color, 
        int thickness=1, 
        int lineType=LINE_8)  // 没有开始与结束角度，最后的小数点位数也没有了
    // 旋转矩形类
    RotatedRect (const Point2f &center, const Size2f &size, float angle)
    */
    // cv::ellipse(
    //     image,
    //     cv::Point(100,100),
    //     cv::Size(100,50),
    //     45.0,
    //     0.0,
    //     330.0,
    //     CV_RGB(255,0,0),
    //     2,
    //     cv::LINE_AA,
    //     0);
        cv::ellipse(
        image,
        cv::RotatedRect(cv::Point(100,100),cv::Size(100,50),45.0),
        CV_RGB(255,0,0),
        2,
        cv::LINE_AA);
    cv::imshow("Win_draw", image);
    ///////////////////////////////////

    cv::waitKey();
    return 0;
}

// 编译命令：g++  -omain  cv06_draw_ellipse.cpp -std=c++11 -I/usr/local/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
