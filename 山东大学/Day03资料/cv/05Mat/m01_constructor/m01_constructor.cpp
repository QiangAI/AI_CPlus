#include "m01_constructor.h"
cv::Mat create_matrix(){
    int rows = 300;             // 图像高度
    int cols = 400;             // 图像宽度
    int type = CV_8UC4;         // 像素类型（宏没有命名空间）
    uchar *data = new uchar[rows * cols * 4];  // 像素4通道unsigned char（0-255之间）；
    /* data暂时不初始化，使用分配时的脏数据 */
    /* data初始化 */
    // bzero(data, rows * cols * 4);  // 初始化为0(透明的黑色)
    // // memset(data, 255, rows * cols * 4);   // 全部初始化为255，不透明的白色
    // // 循环初始化（4通道中第1通道与第4通道为255，其他为0）
    // for(int idx=0; idx <rows * cols * 4/2; idx++){   // 初始化一半
    //     if(idx % 4 == 0 || idx % 4 == 3){
    //         data[idx] = 255;
    //     }
    // }
    // cv::Mat  img(rows, cols, type, data, cv::Mat::AUTO_STEP);   // AUTO_STEP定义在Mat类内部的
    cv::Scalar pixel(0,255,0, 255);
    cv::Mat  img(rows, cols, type, pixel); 
    return img;
    /*
        data不用释放，由cv::Mat管理；
     */
}
