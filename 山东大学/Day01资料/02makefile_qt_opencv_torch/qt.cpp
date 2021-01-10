#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QDesktopWidget>


// 没有使用面向对象的封装

int main(int argc, char**argv){
    // 创建Qt应用
    QApplication application(argc, argv);
    // 创建窗体QDialog / QMainWindow 及其他的窗体QWidget等。
    QDialog  dlg;
    dlg.setWindowTitle("Qt与OpenCV-Makefile");
    dlg.resize(800, 600);
    dlg.setFixedSize(dlg.width(), dlg.height());   // 不允许改变窗体大小
    dlg.move ((QApplication::desktop()->width() - dlg.width()) / 2, (QApplication::desktop()->height() - dlg.height()) / 2);

    dlg.show();
    // 应用消息处理
    return application.exec();
}
