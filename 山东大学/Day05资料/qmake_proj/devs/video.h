#ifndef VIDEO_H
#define VIDEO_H
#include <QtCore/QThread>
#include <opencv2/opencv.hpp>

class CameraDev : public QThread{
    Q_OBJECT
public:
    CameraDev();
    ~CameraDev();
    virtual void close();
protected:
    virtual void run();   // 实现线程任务代码段

private:
    bool is_over;
    cv::VideoCapture *dev;
signals:
    void sig_video(cv::Mat img);
};
#endif
