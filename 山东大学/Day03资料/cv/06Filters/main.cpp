#include <QApplication>
#include "dlgcv.h"

#include <iostream>

int main(int argc, char* argv[]) {
    // 初始化QT应用
    QApplication app(argc, argv);
    // 创建一个对话框
    DlgOpenCV dlg;
    dlg.show();
    return app.exec();
}
