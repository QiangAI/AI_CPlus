// #pragma once
#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H
#include <QtWidgets/QDialog>
#include "../forms/camera.h"
#include "../devs/video.h"

class  MainFrame : public QDialog{
    Q_OBJECT
public:
    MainFrame();
    ~MainFrame();
private:
    Ui::Camera  *ui;
    CameraDev   *dev;

protected:
    virtual void closeEvent(QCloseEvent *e);

public slots:
    void show_video(cv::Mat);
};
#endif
