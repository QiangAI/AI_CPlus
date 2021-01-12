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
        void cv::circle	(	InputOutputArray 	img,
            Point 	center,
            int 	radius,
            const Scalar & 	color,
            int 	thickness = 1,
            int 	lineType = LINE_8,
            int 	shift = 0 
        )	
    */
    cv::circle(
        image, 
        cv::Point(WIN_W /2, WIN_H / 2),     // 圆心
        100,                                // 半径
        CV_RGB(255,0,0),                    // 颜色
        2, 
        cv::LINE_AA, 
        0
    );
    cv::imshow("Win_draw", image);
    ///////////////////////////////////

    cv::waitKey();
    return 0;
}

// 编译命令：g++  -omain  cv04_draw_circle.cpp -std=c++11 -I/usr/local/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
