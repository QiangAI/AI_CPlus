#ifndef IMAGE_PROCESS_H
#define IMAGE_PROCESS_H
#include <opencv2/opencv.hpp>
class ImageProc{
private:
    cv::String *filename_image;     // 文件名：std::string

public:
    cv::Mat m_src;                  // 原始图像的数据结构
    cv::Mat m_gray;         
    /////////////////
    cv::Mat m_diff_x; 
    cv::Mat m_diff_y; 
    cv::Mat m_diff_1;
    cv::Mat m_diff_2;    

    cv::Mat m_roboerts_x;     
    cv::Mat m_roboerts_y;  
    cv::Mat m_roboerts_1;  
    cv::Mat m_roboerts_2;     
    
    cv::Mat m_prewitt_x;     
    cv::Mat m_prewitt_y;     
    cv::Mat m_prewitt_1; 
    cv::Mat m_prewitt_2;

    cv::Mat m_sobels_x; 
    cv::Mat m_sobels_y;     
    cv::Mat m_sobels_1;
    cv::Mat m_sobels_2;       
             
public:
    ImageProc();
    ImageProc(const char *filename);
    ~ImageProc();

    void toGray();

    void diff_x();
    void diff_y();
    void diff_1();
    void diff_2();

    void roberts_x();
    void roberts_y();
    void roberts_1();
    void roberts_2();

    void prewitt_x();
    void prewitt_y();
    void prewitt_1();
    void prewitt_2();

    void sobel_x();
    void sobel_y();
    void sobel_1();
    void sobel_2();    
};
#endif // ! IMAGE_PROCESS_H
