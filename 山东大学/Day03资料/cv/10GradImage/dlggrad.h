#ifndef DLG_OPENCV_H
#define DLG_OPENCV_H
#include <opencv2/opencv.hpp>
#include "ui_output.h"
#include "imageprocess.h"

class DlgGrad: public QDialog{
Q_OBJECT    // 使用signal与slot，记得添加这个宏（如果继承QObject类型，则可选）。
private:
    int type_id;
    int direction_id;     
    
    Ui::dlg_grad  *dlg;
    ImageProc  *proc;
    void showGrayImage(cv::Mat img, QLabel *container);  // 显示图像到指定组件
public:
    DlgGrad(QWidget *parent = 0);     // 编程套路
    ~DlgGrad();
protected:
    virtual void showEvent(QShowEvent *event);
private slots:
    void grad();
    void type(int);
    void direction(int);
};
#endif
