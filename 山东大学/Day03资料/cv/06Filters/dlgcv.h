#ifndef DLG_OPENCV_H
#define DLG_OPENCV_H
#include "dlgmain.h"

class DlgOpenCV: public QDialog{
Q_OBJECT    // 使用signal与slot，记得添加这个宏。
private:
    Ui::dlg_opencv  *dlg;
public:
    DlgOpenCV(QWidget *parent = 0);     // 编程套路
    ~DlgOpenCV();

private slots:
    void blur();
    void bilater();
    void gauss();
    void box();
    void fliter2d();
    void sobel();
    void median();
    void laplace();
    ///////////////
    void down();
    void up();
    void mean();
    void dilate();
    void erode();
    void scharr();
    void sepfilter();
    void sqrbox();
    ///////////////
    void pyramid();
    void morph();
};
#endif
