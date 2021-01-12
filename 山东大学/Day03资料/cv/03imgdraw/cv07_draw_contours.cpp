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
    /**
    void cv::drawContours	(	
        InputOutputArray 	image,      // 缓冲图像
        InputArrayOfArrays 	contours,   // 数据顶点  std::vector< std::vector<cv::Point>>  一个vector一个轮廓
        int 	contourIdx,             // 需要绘制的轮廓线，负数表示绘制所有轮廓线
        const Scalar & 	color,
        int 	thickness = 1,
        int 	lineType = LINE_8,
        InputArray 	hierarchy = noArray(),  // 执行需要绘制的轮廓信息
        int 	maxLevel = INT_MAX,         // 轮廓线嵌套的深度
        Point 	offset = Point()            // 轮廓线的偏移位置𝚘𝚏𝚏𝚜𝚎𝚝=(dx,dy)
    )	
     */
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
    int h[]={0,1};
    cv::drawContours(
        image,
        vpts,
        0,
        CV_RGB(255,0,0),
        2,
        cv::LINE_AA);   // 剩下的参数可选，使用默认
    /**
     * 自己构造轮廓线（等高线）比较复杂，这个可以通过算法，抽取图像轮廓，后面专门用一节研究
     */
    cv::imshow("Win_draw", image);
    ///////////////////////////////////

    cv::waitKey();
    return 0;
}

// 编译命令：g++  -omain  cv07_draw_contours.cpp -std=c++11 -I/usr/local/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
