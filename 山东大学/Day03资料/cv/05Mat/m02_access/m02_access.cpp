#include "m02_access.h"
#include <iostream>
/*
    访问Mat矩阵，并直接对数据进行操作。
 */
void access_at(cv::Mat &mat){
    int rows = mat.rows;
    int cols = mat.cols;
    int channels = mat.channels();  // 三通道
    int depth = mat.depth();
    std::cout<< depth << "," << channels << std::endl;
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            cv::Vec<u_char, 3>& pixel = mat.at<cv::Vec<u_char, 3> >(y, x);
            // std::cout<<(unsigned int)pixel[0]<< ",";
            // std::cout<<(unsigned int)pixel[1]<< ",";
            // std::cout<<(unsigned int)pixel[2]<< ",";
            // std::cout<<std::endl;
            pixel[0] = 0;   // B把蓝色通道设置为0
            // pixel[1] = 0;   // G绿色通道
            // pixel[2] = 0;   // R红色通道
        }
    }
}

void access_ptr(cv::Mat &mat){
    int rows = mat.rows;
    int cols = mat.cols;
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            cv::Vec<u_char, 3>* pixel = mat.ptr<cv::Vec<u_char, 3> >(y, x);
            (*pixel)[0] = 0;   // B把蓝色通道设置为0
        }
    }
}
void access_row(cv::Mat &mat){
    int rows = mat.rows;
    int cols = mat.cols;
    // 取部分矩阵
    cv::Mat part_mat = mat.rowRange(100,200); 

    for(int y = 0; y < 100; y++){   // 注意不要越界
        cv::Mat row = part_mat.row(y);
        for(int x = 0; x < cols; x++){
            cv::Vec<u_char, 3>& pixel = row.at<cv::Vec<u_char, 3> >(x);
            pixel[0] = 0;   // B把蓝色通道设置为0
            pixel[1] = 0;   // B把蓝色通道设置为0
        }
    }
}

void access_begin_end(cv::Mat &mat){
    // 获取元素开始的迭代器
    // cv::MatConstIterator_<cv::Vec<u_char, 3> > pixel = mat.begin<cv::Vec<u_char, 3> >(); // 使用外部迭代器，使用[]无法修改。
    cv::Mat_<cv::Vec<u_char, 3> >::iterator pixel = mat.begin<cv::Vec<u_char, 3> >();  // 使用内部迭代器，可以访问成员
    // 循环迭代
    do{
        (*pixel)[0] = 0;   // B把蓝色通道设置为0
        (*pixel)[1] = 0;   // B把蓝色通道设置为0
        pixel++;
    } while(pixel != mat.end<cv::Vec<u_char, 3> >());

}
// Functor(这个是并行调用的)
// struct PixelFunctor{
//     void operator ()(cv::Vec<u_char, 3>& pixel, const int *pos) const{ // 传递像素与像素在矩阵中位置
//         // std::cout << pos[0] << "," << pos[1] << std::endl;  （位置）// 因为并行，打印可能是错乱的。
//         pixel[0] = 0;
//     }
// };   // 记得这个分号

class PixelFunctor{
public:
    void operator ()(cv::Vec<u_char, 3>& pixel, const int *pos) const{ // 传递像素与像素在矩阵中位置
        // std::cout << pos[0] << "," << pos[1] << std::endl;  （位置）// 因为并行，打印可能是错乱的。
        pixel[0] = 0;
    }
};   // 记得这个分号
void function_ptr(cv::Vec<u_char, 3>& pixel, const int *pos){
    pixel[0] = 0;
}
void access_foreach(cv::Mat &mat){
    // struct PixelFunctor functor;
    // PixelFunctor functor;
    // mat.forEach<cv::Vec<u_char, 3> >(functor);
    // mat.forEach<cv::Vec<u_char, 3> >(&function_ptr);
    int a = 20;
    mat.forEach<cv::Vec<u_char, 3> >([&a](cv::Vec<u_char, 3>& pixel, const int *pos)->void{
        pixel[1] = 0;
        a = 30;  // [&]知名本地局部变量按照引用访问
    });
    std::cout<<a<<std::endl;  // 30
}




