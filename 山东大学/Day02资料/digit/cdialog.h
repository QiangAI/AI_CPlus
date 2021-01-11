#ifndef C_DIALOG_H
#define C_DIALOG_H
#include <QtWidgets/QDialog>
#include "ui_digit.h"
#include "cvideo.h"
class CDialog : public QDialog{
    Q_OBJECT
public:
    CDialog(QWidget *parent=0);
    virtual ~CDialog();
    virtual void closeEvent(QCloseEvent *e);
private:
    Ui::digit *ui;
    CVideo   *video;
    int get_;
    int identify_;

public slots:
    void show_video(cv::Mat);
    void get();
    void identify();
};
#endif