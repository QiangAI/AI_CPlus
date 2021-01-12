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
    void cv::drawMarker (
        InputOutputArray img, 
        Point position,                 // 位置
        const Scalar &color,    
        int markerType=MARKER_CROSS,    // marler类型
        int markerSize=20,              // marker大小
        int thickness=1,                // 线粗细
        int line_type=8)                // 线绘制算法
     */
    /**
     * - marker类型
            - MARKER_CROSS 
            - MARKER_TILTED_CROSS
            - MARKER_STAR
            - MARKER_DIAMOND
            - MARKER_SQUARE
            - MARKER_TRIANGLE_UP
            - MARKER_TRIANGLE_DOWN
     */
    cv::drawMarker(
        image,
        cv::Point(100,100),
        CV_RGB(255,0,0),
        cv::MARKER_CROSS,
        5,
        1,
        cv::LINE_AA
    );
    cv::imshow("Win_draw", image);
    ///////////////////////////////////

    cv::waitKey();
    return 0;
}

// 编译命令：g++  -omain  cv08_draw_marker.cpp -std=c++11 -I/usr/local/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
