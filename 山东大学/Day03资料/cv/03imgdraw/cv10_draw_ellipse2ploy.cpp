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

    /**
     * void cv::ellipse2Poly(
     *      Point center, 
     *      Size axes, 
     *      int angle, 
     *      int arcStart, 
     *      int arcEnd, 
     *      int delta, 
     *      std::vector< Point > &pts)
        // 增加精度
        void cv::ellipse2Poly(
            Point2d center,     // 2d，否点数
            Size2d axes, 
            int angle, 
            int arcStart, 
            int arcEnd, 
            int delta, 
            std::vector< Point2d > &pts)
     */
    std::vector<cv::Point>  pts;  // 定义一个数组
    cv::ellipse2Poly(cv::Point(100,100),cv::Size(100,50),0, 0, 135, 1, pts);  // 把椭圆转换为多边线顶点
    pts.push_back(cv::Point(100,100)); // 加上就是饼弧，不加就是弦弧
    std::vector< std::vector<cv::Point> > vpts;   // 多个多边线顶点
    vpts.push_back(pts);
    // cv::polylines(   // 绘制
    //     image,      // 图像
    //     vpts,       // 顶点 (二重vector)
    //     true,       // 封闭
    //     cv::Scalar(0, 255, 255, 255), 
    //     2, 
    //     cv::LINE_8,
    //     0);              // 空心
    cv::fillPoly(image, vpts, CV_RGB(255,0,0));  // 实心
    cv::imshow("Win_draw", image);
    ///////////////////////////////////

    cv::waitKey();
    return 0;
}

// 编译命令：g++  -omain  cv10_draw_ellipse2ploy.cpp -std=c++11 -I/usr/local/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
