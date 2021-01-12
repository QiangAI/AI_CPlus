#include <QApplication>
#include <QDialog>
#include <QLabel>
// #include <QImage>    // 不需要引入
// #include <QPixmap>
////////////////////////////////
#include <opencv2/opencv.hpp>
///////////////////////////////
#include "./m01_constructor/m01_constructor.h"

#include <iostream>

int main(int argc, char* argv[]) {
    // 初始化QT应用
    QApplication app(argc, argv);
    // 创建一个对话框
    QDialog  dlg;
    // 设置对话框大小
    dlg.setWindowTitle("OpenCV之Mat图像表示");
    dlg.setGeometry(100,100,400,300);

    // 显示图片的标签框
    QLabel lbl_image("显示图片", &dlg); // 以dlg作为父窗体
    // 图片框大小位置
    lbl_image.setGeometry(0,0, 400,300);

    
    /* 图像显示 */
    cv::Mat src_image;
    cv::Mat image;
    ////////////////////////////////////
    src_image = create_matrix();    // 调用矩阵构造函数

    // 测试Mat的属性：
    // std::cout<<"行列：（" << src_image.rows << ","<< src_image.cols <<")"<<std::endl;
    // std::cout<<"维度，通道与深度：（" << src_image.dims << "," << src_image.channels() << "," << src_image.depth() << ")" <<std::endl;
    // std::cout<<"类型："<< src_image.type() <<", 是否是CV_8UC4？" <<(CV_8UC4 == src_image.type()) << std::endl;
    // std::cout<<"元素字节数，通道字节数，总的元素个数：" << src_image.elemSize() <<","<< src_image.elemSize1() << "," << src_image.total() <<std::endl;
    // ------------------
    int flags = src_image.flags;
    std::cout << "标记值：" << flags << std::endl;
    std::cout << "魔法值：" << (flags & cv::Mat::MAGIC_MASK) << "," << cv::Mat::MAGIC_VAL << std::endl;  
    std::cout << "深度值：" << (flags & cv::Mat::DEPTH_MASK) << "," << CV_8U << std::endl;  
    std::cout << "类型值：" << (flags & cv::Mat::TYPE_MASK) << "," << CV_8UC4 << std::endl;  
    // 矩阵是否连续，flags & cv::Mat::CONTINUOUS_FLA 不等于0都是连续的。
    std::cout << "连续值：" << (flags & cv::Mat::CONTINUOUS_FLAG) << "," << cv::Mat::CONTINUOUS_FLAG << std::endl;  
    ////////////////////////////////////
    // 转换图像颜色空间
    cv::cvtColor(src_image, image, cv::COLOR_BGRA2RGBA);  // opencv读取数据的格式是BGRA，需要转换为QT能处理的格式
    // 把图像转换: cv::Mat -> QImage -> QPixmap -> 设置到QLabel
    const uchar *u_image = image.data;
    QImage img_buffer(u_image, image.cols, image.rows, QImage::Format_RGBA8888);
    QPixmap img_map = QPixmap::fromImage(img_buffer);
    lbl_image.setPixmap(img_map);
    

    lbl_image.setScaledContents(true);
    // std::cout<< image.dims<<std::endl;
    // std::cout<< image.depth()<<std::endl;
    dlg.show();
    return app.exec();
}
