// #pragma once
#ifndef APP_H
#define APP_H
#include <QtWidgets/QApplication>

#include "frame.h"

class App : public QApplication{
private:
    MainFrame *frame;

public:
    App(int, char **);
    ~App();
};
#endif
