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
    // 使用指针传递折线的多个点
    void 	cv::polylines (
        InputOutputArray img, 
        const Point *const *pts, const int *npts,     // 折线的顶点数据 与 顶点数
        int ncontours,                                // 绘制的折线个数
        bool isClosed,                                // 是否自动封闭
        const Scalar &color, 
        int thickness=1, 
        int lineType=LINE_8, 
        int shift=0)
    // 使用InputArrayOfArrays数据结构传递折线的多个点
    void 	cv::polylines (InputOutputArray img, InputArrayOfArrays pts, bool isClosed, const Scalar &color, int thickness=1, int lineType=LINE_8, int shift=0)
     */
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
    cv::polylines(
        image,      // 图像
        pts,        // 顶点（二重指针，行表示一个多边形，列表示点），注意类型const Point *const *pts
        count,      // 数组，用来表示每个多边形
        2,          // 多边形个数
        true,       // 封闭
        cv::Scalar(255,0,255, 255), 
        2, 
        cv::LINE_8,
        0);
    // 上面不能使用数组，因为数组的是连续数据类型，二重指针无法正确索引，所以需要使用二重指针重新索引。
    /**
     * void cv::polylines	(	
            InputOutputArray 	img,
            InputArrayOfArrays 	pts,
            bool 	isClosed,
            const Scalar & 	color,
            int 	thickness = 1,
            int 	lineType = LINE_8,
            int 	shift = 0 
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

    cv::polylines(
        image,      // 图像
        vpts,       // 顶点 (二重vector)
        true,       // 封闭
        cv::Scalar(0, 255, 255, 255), 
        2, 
        cv::LINE_8,
        0);
    cv::imshow("Win_draw", image);
    ///////////////////////////////////

    cv::waitKey();
    return 0;
}

// 编译命令：g++  -omain  cv02_draw_ploylines.cpp -std=c++11 -I/usr/local/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
