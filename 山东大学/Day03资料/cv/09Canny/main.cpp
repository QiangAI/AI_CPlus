#include <QApplication>
#include "dlgcanny.h"

#include <iostream>

int main(int argc, char* argv[]) {
    // 初始化QT应用
    QApplication app(argc, argv);
    // 创建一个对话框
    DlgCanny dlg;
    dlg.show();
    return app.exec();
}
