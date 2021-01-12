#include <QApplication>
#include <QDialog>
#include <QLabel>
////////////////////////////////
#include <opencv2/opencv.hpp>
////////////////////////////////
#include <iostream>


int main(int argc, char* argv[]) {
    // 初始化QT应用
    QApplication app(argc, argv);
    // 创建一个对话框
    QDialog  dlg;
    // 设置对话框大小
    dlg.setWindowTitle("机器视觉之OpenCV图像处理");
    dlg.setGeometry(100,100,400,300);

    // 显示图片的标签框
    QLabel lbl_image("显示图片", &dlg); // 以dlg作为父窗体
    // 图片框大小位置
    lbl_image.setGeometry(0,0, 400,300);

    // 定义图像缓冲
    cv::Mat src_image;
    cv::Mat image;
    // 打开图像
    src_image = cv::imread("bird.png", cv::IMREAD_COLOR);
    /////////////////////////////////////////////////////
    // ()类型转换运算符
    cv::Mat sub_image = src_image(cv::Range(100, 200), cv::Range(100, 200));  // 返回的是引用
    // 赋值运算符
    sub_image = cv::Scalar(255,0,0);
    /////////////////////////////////////////////////////
    // 转换图像颜色空间
    cv::cvtColor(src_image, image, cv::COLOR_BGR2RGBA);  // opencv读取数据的格式是BGRA，需要转换为QT能处理的格式
    // 把图像转换: cv::Mat -> QImage -> QPixmap -> 设置到QLabel
    const uchar *u_image = image.data;
    QImage img_buffer(u_image, image.cols, image.rows, QImage::Format_RGBA8888);
    QPixmap img_map = QPixmap::fromImage(img_buffer);
    lbl_image.setPixmap(img_map);
    lbl_image.setScaledContents(true);
    dlg.show();
    return app.exec();
}
