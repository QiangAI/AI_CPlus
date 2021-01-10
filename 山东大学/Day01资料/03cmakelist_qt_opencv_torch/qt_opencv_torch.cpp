#include <torch/torch.h>      // 放第一行，否则可能出问题！
#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QDesktopWidget>
#include <opencv2/opencv.hpp>

// 没有使用面向对象的封装

int main(int argc, char**argv){
    torch::Tensor tensor = torch::rand({2, 3});
    std::cout << tensor << std::endl;

    // 创建Qt应用
    QApplication application(argc, argv);
    // 创建窗体QDialog / QMainWindow 及其他的窗体QWidget等。
    QDialog  dlg;
    dlg.setWindowTitle("Qt与OpenCV-Makefile");
    dlg.resize(800, 600);
    dlg.setFixedSize(dlg.width(), dlg.height());   // 不允许改变窗体大小
    dlg.move ((QApplication::desktop()->width() - dlg.width()) / 2, (QApplication::desktop()->height() - dlg.height()) / 2);

    // 使用QLabel显示图像
    QLabel lbl_show("显示图像区域",&dlg);
    lbl_show.setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    lbl_show.setGeometry(0, 0, dlg.width(), dlg.height());

    // // 图像的处理
    cv::Mat  img = cv::imread("gpu.bmp");
    // 把图像转换为Qt支持的对象
    QImage qt_img(img.data, img.cols, img.rows, QImage::Format_RGB888);
    QPixmap qt_pixmap = QPixmap::fromImage(qt_img);
    lbl_show.setPixmap(qt_pixmap);
    lbl_show.setScaledContents(true);

    dlg.show();
    // 应用消息处理
    return application.exec();
}
