#ifndef FRAME_H
#define FRAME_H
#include <QtWidgets/QDialog>
#include "../forms/ui_camera.h"    // cmake的默认编译规则
#include "../devs/video.h"
#include <opencv2/opencv.hpp>

class MainFrame : public QDialog{
    Q_OBJECT
private:
    Ui::Camera *ui;
    CameraDev  *dev;
public:
    MainFrame();
    ~MainFrame();
protected:
    virtual void closeEvent(QCloseEvent *e);

public slots:
    virtual void capture();
    virtual void recognize();
    virtual void show_video(cv::Mat img);

};
#endif
