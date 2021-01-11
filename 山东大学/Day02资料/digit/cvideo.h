#ifndef C_VIDEO_H
#define C_VIDEO_H
#include <QtCore/QThread>
#include <opencv2/opencv.hpp>

class CVideo: public QThread{
    Q_OBJECT
public:
    CVideo(QObject *parent=nullptr);
    ~CVideo();
protected:
    virtual void run();

private:
    cv::VideoCapture  *dev;

signals:
    void sig_video(cv::Mat img);
};
#endif