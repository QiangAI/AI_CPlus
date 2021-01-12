#ifndef DLG_OPENCV_H
#define DLG_OPENCV_H
#include <opencv2/opencv.hpp>
#include "ui_output.h"
#include "imageprocess.h"

class DlgCanny: public QDialog{
Q_OBJECT    // 使用signal与slot，记得添加这个宏（如果继承QObject类型，则可选）。
private:
    Ui::dlg_canny  *dlg;
    ImageProc  *proc;
    void showGrayImage(cv::Mat img, QLabel *container);  // 显示图像到指定组件
public:
    DlgCanny(QWidget *parent = 0);     // 编程套路
    ~DlgCanny();
protected:
    virtual void showEvent(QShowEvent *event);
private slots:
    void canny();
};
#endif
