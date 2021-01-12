#include <opencv2/opencv.hpp>


int main(int argc, char* argv[]) {
    // 初始化列表
    std::initializer_list<int> v1 = {1,2,3,4};
    cv::Mat m1(v1);
    cv::Mat m2({1,2,3,4,5});

    cv::Mat_<int> m3={1,2,3,4};  // 这种方式对Mat错误（语法没有问题），但是要求显式选择构造器（模板类型歧义造成）

    // MatCommaInitializer_ 必须由矩阵产生
    cv::Mat M = (cv::Mat_<int>(3,3) << 1, 0, 0, 0, 1, 0, 0, 0, 1);
    return 0;
}
