#ifndef VIDEO_H
#define VIDEO_H
#include <QtCore/QThread>
#include <opencv2/opencv.hpp>

class  CameraDev : public QThread{
    Q_OBJECT
protected:
    virtual void run();
public:
    CameraDev();
    ~CameraDev();

    void close();
private:
    bool is_over;
    cv::VideoCapture *dev;

signals:
    void sig_video(cv::Mat img);
};
#endif
