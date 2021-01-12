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

    cv::Point  points[2][3] = {
        {
            cv::Point(200, 10),
            cv::Point(10, 150),
            cv::Point(390, 150)
        },  
        {
            cv::Point(10, 160),
            cv::Point(300, 160),
            cv::Point(200, 290)
        }

    };
    int count[2] = {3, 3};
    const cv::Point  *pts[] = {points[0], points[1]};
    /**
    void cv::fillPoly (
        InputOutputArray img, 
        const Point **pts, 
        const int *npts, 
        int ncontours, 
        const Scalar &color, 
        int lineType=LINE_8, 
        int shift=0, 
        Point offset=Point())
    void cv::fillPoly (
        InputOutputArray img, 
        InputArrayOfArrays pts, 
        const Scalar &color, 
        int lineType=LINE_8, 
        int shift=0, 
        Point offset=Point())
     */
    // fillPoly(image, pts, count, 2, cv::Scalar(255, 255, 0));
    std::vector< std::vector<cv::Point>>  vpts;
    std::vector<cv::Point> py_1;
    py_1.push_back(points[0][0]);
    py_1.push_back(points[0][1]);
    py_1.push_back(points[0][2]);

    std::vector<cv::Point> py_2;
    py_2.push_back(points[1][0]);
    py_2.push_back(points[1][1]);
    py_2.push_back(points[1][2]);

    vpts.push_back(py_1);
    vpts.push_back(py_2);
    cv::fillPoly(image, vpts, CV_RGB(255,0,0));
    cv::imshow("Win_draw", image);

    /** 填充为凸的。
     void 	cv::fillConvexPoly (InputOutputArray img, const Point *pts, int npts, const Scalar &color, int lineType=LINE_8, int shift=0)
     void 	cv::fillConvexPoly (InputOutputArray img, InputArray points, const Scalar &color, int lineType=LINE_8, int shift=0)
     */
    ///////////////////////////////////

    cv::waitKey();
    return 0;
}

// 编译命令：g++  -omain  cv09_draw_fill.cpp -std=c++11 -I/usr/local/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
