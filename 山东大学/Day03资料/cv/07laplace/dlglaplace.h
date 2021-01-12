#ifndef DLG_OPENCV_H
#define DLG_OPENCV_H
#include <opencv2/opencv.hpp>
#include "laplace.h"

class DlgLaplace: public QDialog{
Q_OBJECT    // 使用signal与slot，记得添加这个宏。
private:
    Ui::dlg_laplace  *dlg;
public:
    DlgLaplace(QWidget *parent = 0);     // 编程套路
    ~DlgLaplace();

private slots:
    void image_proc();

private:
    void  laplace(cv::InputArray src, cv::OutputArray dst);
    void  laplace_f(cv::InputArray src, cv::OutputArray dst);
    void  laplace_g(cv::InputArray src, cv::OutputArray dst);
};
#endif
