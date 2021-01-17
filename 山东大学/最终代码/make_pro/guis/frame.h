#ifndef FRAME_H
#define FRAME_H
// #include "../models/lenet5_reco.h"
#include "../forms/camera.h"
#include "../devs/video.h"
#include <QtWidgets/QDialog>



class MainFrame : public QDialog{
    Q_OBJECT
private:
    Ui::Camera *ui;
    CameraDev  *dev;
    bool is_capture;
    cv::Mat img_capture;
    // 识别器
    // LeNet5Recognizer *reco;
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
