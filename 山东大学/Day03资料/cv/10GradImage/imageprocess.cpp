#include "imageprocess.h"

ImageProc::ImageProc():
    filename_image(new cv::String("lotus.png")){
    m_src = cv::imread(*filename_image);
}
ImageProc::ImageProc(const char *filename):
    filename_image(new cv::String(filename)){
    m_src = cv::imread(*filename_image);
}
ImageProc::~ImageProc(){
    delete filename_image;
    m_src.release();
}
void ImageProc::toGray(){
    cv::cvtColor(m_src, m_gray,cv::COLOR_BGR2GRAY);
}

void ImageProc::diff_x(){
    if (! m_diff_x.empty()) return;  // 已经完成计算的，不再二次计算（算法比较龊速度慢）
    // 定义模板
    cv::Mat  tp = (cv::Mat_<float>(1,2) << -1, 1);
    // 原图像类型转换为CV_32FC1（因为精度）
    cv::Mat  m_in;
    m_gray.convertTo(m_in, CV_32FC1);
    int rows = m_in.rows;
    int cols = m_in.cols;
    // 原灰度图像padding
    cv::Mat m_padding(m_in.rows, m_in.cols + 2, m_in.type(), cv::Scalar(0.0));
    m_in.copyTo(m_padding(cv::Range(0, rows), cv::Range(1, cols + 1)));
    // // 计算差分输出
    cv::Mat m_out(rows, cols, m_in.type());

    for(int y = 0; y <rows; y++){
        for(int x = 0; x < cols; x++){
            cv::Mat m = tp.mul(m_padding(cv::Range(y, y+1), cv::Range(x, x+2))); 
            cv::Scalar v = cv::sum(m);
            m_out.at<float>(y, x) = v[0];
        }
    } 
    m_out += 128;   // 为了效果，做了128的灰度偏移
    m_out.convertTo(m_diff_x, CV_8UC1);

}
void ImageProc::diff_y(){
    if (! m_diff_y.empty()) return;  // 已经完成计算的，不再二次计算（算法比较龊速度慢）
    // 定义模板
    cv::Mat  tp = (cv::Mat_<float>(2,1) << -1, 1);
    // 原图像类型转换为CV_32FC1（因为精度）
    cv::Mat  m_in;
    m_gray.convertTo(m_in, CV_32FC1);
    int rows = m_in.rows;
    int cols = m_in.cols;
    // 原灰度图像padding
    cv::Mat m_padding(m_in.rows + 2, m_in.cols, m_in.type(), cv::Scalar(0.0));
    m_in.copyTo(m_padding(cv::Range(1, rows + 1), cv::Range(0, cols )));
    // // 计算差分输出
    cv::Mat m_out(rows, cols, m_in.type());

    for(int y = 0; y <rows; y++){
        for(int x = 0; x < cols; x++){
            cv::Mat m = tp.mul(m_padding(cv::Range(y, y+2), cv::Range(x, x+1))); 
            cv::Scalar v = cv::sum(m);
            m_out.at<float>(y, x) = v[0];
        }
    } 
    m_out += 128;   // 为了效果，做了128的灰度偏移
    m_out.convertTo(m_diff_y, CV_8UC1);
}
void ImageProc::diff_1(){
    if (! m_diff_1.empty()) return;

    if ( m_diff_x.empty())  diff_x();
    if ( m_diff_y.empty())  diff_y();

    // 1-范数计算
    m_diff_1 = cv::abs(m_diff_x - 128) + cv::abs(m_diff_y -128);
    m_diff_1 += 128;  

}
void ImageProc::diff_2(){
    if (! m_diff_2.empty()) return;

    if ( m_diff_x.empty())  diff_x();
    if ( m_diff_y.empty())  diff_y();

    // 2-范数计算
    cv::Mat r2= (m_diff_x - 128).mul(m_diff_x - 128) + (m_diff_y -128).mul(m_diff_y -128);
    cv::Mat fr2;
    r2.convertTo(fr2, CV_32FC1);
    cv::Mat out;
    cv::sqrt(fr2, out);
    out.convertTo(m_diff_2, CV_8UC1);
    // m_diff_2 += 128;   // 算术强化
    m_diff_2 *= 20;   // 几何强化
}


void ImageProc::roberts_x(){
    if (! m_roboerts_x.empty()) return;  // 已经完成计算的，不再二次计算（算法比较龊速度慢）
    // 定义模板
    cv::Mat  tp = (cv::Mat_<float>(2,2) << 
                -1,  0,
                 0,  1
    );
    // 原图像类型转换为CV_32FC1（因为精度）
    cv::Mat  m_in;
    m_gray.convertTo(m_in, CV_32FC1);
    int rows = m_in.rows;
    int cols = m_in.cols;
    // 原灰度图像padding
    cv::Mat m_padding(m_in.rows + 2, m_in.cols + 2, m_in.type(), cv::Scalar(0.0));
    m_in.copyTo(m_padding(cv::Range(1, rows + 1), cv::Range(1, cols + 1)));
    // // 计算差分输出
    cv::Mat m_out(rows, cols, m_in.type());

    for(int y = 0; y <rows; y++){
        for(int x = 0; x < cols; x++){
            cv::Mat m = tp.mul(m_padding(cv::Range(y, y+2), cv::Range(x, x+2))); 
            cv::Scalar v = cv::sum(m);
            m_out.at<float>(y, x) = v[0];
        }
    } 
    m_out += 128;   // 为了效果，做了128的灰度偏移
    m_out.convertTo(m_roboerts_x, CV_8UC1);
}
void ImageProc::roberts_y(){
    if (! m_roboerts_y.empty()) return;  // 已经完成计算的，不再二次计算（算法比较龊速度慢）
    // 定义模板
    cv::Mat  tp = (cv::Mat_<float>(2,2) << 
                0, -1,
                1,  0
    );
    // 原图像类型转换为CV_32FC1（因为精度）
    cv::Mat  m_in;
    m_gray.convertTo(m_in, CV_32FC1);
    int rows = m_in.rows;
    int cols = m_in.cols;
    // 原灰度图像padding
    cv::Mat m_padding(m_in.rows + 2, m_in.cols + 2, m_in.type(), cv::Scalar(0.0));
    m_in.copyTo(m_padding(cv::Range(1, rows + 1), cv::Range(1, cols + 1)));
    // // 计算差分输出
    cv::Mat m_out(rows, cols, m_in.type());

    for(int y = 0; y <rows; y++){
        for(int x = 0; x < cols; x++){
            cv::Mat m = tp.mul(m_padding(cv::Range(y, y+2), cv::Range(x, x+2))); 
            cv::Scalar v = cv::sum(m);
            m_out.at<float>(y, x) = v[0];
        }
    } 
    m_out += 128;   // 为了效果，做了128的灰度偏移
    m_out.convertTo(m_roboerts_y, CV_8UC1);
}
void ImageProc::roberts_1(){
    if (! m_roboerts_1.empty()) return;

    if ( m_roboerts_x.empty())  roberts_x();
    if ( m_roboerts_y.empty())  roberts_y();

    // 1-范数计算
    m_roboerts_1 = cv::abs(m_roboerts_x - 128) + cv::abs(m_roboerts_y -128);
    m_roboerts_1 += 128;  
}
void ImageProc::roberts_2(){
    if (! m_roboerts_2.empty()) return;

    if ( m_roboerts_x.empty())  roberts_x();
    if ( m_roboerts_y.empty())  roberts_y();

    // 2-范数计算
    cv::Mat r2= (m_roboerts_x - 128).mul(m_roboerts_x - 128) + (m_roboerts_y -128).mul(m_roboerts_y -128);
    cv::Mat fr2;
    r2.convertTo(fr2, CV_32FC1);
    cv::Mat out;
    cv::sqrt(fr2, out);
    out.convertTo(m_roboerts_2, CV_8UC1);
    // m_diff_2 += 128;   // 算术强化
    m_roboerts_2 *= 20;   // 几何强化
}

void ImageProc::prewitt_x(){
    if (! m_prewitt_x.empty()) return;  // 已经完成计算的，不再二次计算（算法比较龊速度慢）
    // 定义模板
    cv::Mat  tp = (cv::Mat_<float>(3, 3) << 
                -1.0, -1.0, -1.0,
                 0.0,  0.0,  0.0,
                 1.0,  1.0,  1.0
    );
    // 原图像类型转换为CV_32FC1（因为精度）
    cv::Mat  m_in;
    m_gray.convertTo(m_in, CV_32FC1);
    int rows = m_in.rows;
    int cols = m_in.cols;
    // 原灰度图像padding
    cv::Mat m_padding(m_in.rows + 2, m_in.cols + 2, m_in.type(), cv::Scalar(0.0));
    m_in.copyTo(m_padding(cv::Range(1, rows + 1), cv::Range(1, cols + 1)));
    // // 计算差分输出
    cv::Mat m_out(rows, cols, m_in.type());

    for(int y = 0; y <rows; y++){
        for(int x = 0; x < cols; x++){
            cv::Mat m = tp.mul(m_padding(cv::Range(y, y+3), cv::Range(x, x+3))); 
            cv::Scalar v = cv::sum(m);
            m_out.at<float>(y, x) = v[0];
        }
    } 
    m_out += 128;   // 为了效果，做了128的灰度偏移
    m_out.convertTo(m_prewitt_x, CV_8UC1);
}
void ImageProc::prewitt_y(){
    if (! m_prewitt_y.empty()) return;  // 已经完成计算的，不再二次计算（算法比较龊速度慢）
    // 定义模板
    cv::Mat  tp = (cv::Mat_<float>(3, 3) << 
                -1.0,  0.0,  1.0,
                -1.0,  0.0,  1.0,
                -1.0,  0.0,  1.0
    );
    // 原图像类型转换为CV_32FC1（因为精度）
    cv::Mat  m_in;
    m_gray.convertTo(m_in, CV_32FC1);
    int rows = m_in.rows;
    int cols = m_in.cols;
    // 原灰度图像padding
    cv::Mat m_padding(m_in.rows + 2, m_in.cols + 2, m_in.type(), cv::Scalar(0.0));
    m_in.copyTo(m_padding(cv::Range(1, rows + 1), cv::Range(1, cols + 1)));
    // // 计算差分输出
    cv::Mat m_out(rows, cols, m_in.type());

    for(int y = 0; y <rows; y++){
        for(int x = 0; x < cols; x++){
            cv::Mat m = tp.mul(m_padding(cv::Range(y, y+3), cv::Range(x, x+3))); 
            cv::Scalar v = cv::sum(m);
            m_out.at<float>(y, x) = v[0];
        }
    } 
    m_out += 128;   // 为了效果，做了128的灰度偏移
    m_out.convertTo(m_prewitt_y, CV_8UC1);
}
void ImageProc::prewitt_1(){
    if (! m_prewitt_1.empty()) return;

    if ( m_prewitt_x.empty())  prewitt_x();
    if ( m_prewitt_y.empty())  prewitt_y();

    // 1-范数计算
    m_prewitt_1 = cv::abs(m_prewitt_x - 128) + cv::abs(m_prewitt_y -128);
    m_prewitt_1 += 128;  
}
void ImageProc::prewitt_2(){
    if (! m_prewitt_2.empty()) return;

    if ( m_prewitt_x.empty())  prewitt_x();
    if ( m_prewitt_y.empty())  prewitt_y();

    // 2-范数计算
    cv::Mat r2= (m_prewitt_x - 128).mul(m_prewitt_x - 128) + (m_prewitt_y -128).mul(m_prewitt_y -128);
    cv::Mat fr2;
    r2.convertTo(fr2, CV_32FC1);
    cv::Mat out;
    cv::sqrt(fr2, out);
    out.convertTo(m_prewitt_2, CV_8UC1);
    // m_diff_2 += 128;   // 算术强化
    m_prewitt_2 *= 20;   // 几何强化
}
void ImageProc::sobel_x(){
    if (! m_sobels_x.empty()) return;  // 已经完成计算的，不再二次计算（算法比较龊速度慢）
    // 定义模板
    cv::Mat  tp = (cv::Mat_<float>(3, 3) << 
                -1.0, -2.0, -1.0,
                 0.0,  0.0,  0.0,
                 1.0,  2.0,  1.0
    );
    // 原图像类型转换为CV_32FC1（因为精度）
    cv::Mat  m_in;
    m_gray.convertTo(m_in, CV_32FC1);
    int rows = m_in.rows;
    int cols = m_in.cols;
    // 原灰度图像padding
    cv::Mat m_padding(m_in.rows + 2, m_in.cols + 2, m_in.type(), cv::Scalar(0.0));
    m_in.copyTo(m_padding(cv::Range(1, rows + 1), cv::Range(1, cols + 1)));
    // // 计算差分输出
    cv::Mat m_out(rows, cols, m_in.type());

    for(int y = 0; y <rows; y++){
        for(int x = 0; x < cols; x++){
            cv::Mat m = tp.mul(m_padding(cv::Range(y, y+3), cv::Range(x, x+3))); 
            cv::Scalar v = cv::sum(m);
            m_out.at<float>(y, x) = v[0];
        }
    } 
    m_out += 128;   // 为了效果，做了128的灰度偏移
    m_out.convertTo(m_sobels_x, CV_8UC1);
}

void ImageProc::sobel_y(){
    if (! m_sobels_y.empty()) return;  // 已经完成计算的，不再二次计算（算法比较龊速度慢）
    // 定义模板
    cv::Mat  tp = (cv::Mat_<float>(3, 3) << 
                -1.0, 0.0, 1.0,
                -2.0, 0.0, 2.0,
                -1.0, 0.0, 1.0
    );
    // 原图像类型转换为CV_32FC1（因为精度）
    cv::Mat  m_in;
    m_gray.convertTo(m_in, CV_32FC1);
    int rows = m_in.rows;
    int cols = m_in.cols;
    // 原灰度图像padding
    cv::Mat m_padding(m_in.rows + 2, m_in.cols + 2, m_in.type(), cv::Scalar(0.0));
    m_in.copyTo(m_padding(cv::Range(1, rows + 1), cv::Range(1, cols + 1)));
    // // 计算差分输出
    cv::Mat m_out(rows, cols, m_in.type());

    for(int y = 0; y <rows; y++){
        for(int x = 0; x < cols; x++){
            cv::Mat m = tp.mul(m_padding(cv::Range(y, y+3), cv::Range(x, x+3))); 
            cv::Scalar v = cv::sum(m);
            m_out.at<float>(y, x) = v[0];
        }
    } 
    m_out += 128;   // 为了效果，做了128的灰度偏移
    m_out.convertTo(m_sobels_y, CV_8UC1);
}
void ImageProc::sobel_1(){
    if (! m_sobels_1.empty()) return;

    if ( m_sobels_x.empty())  sobel_x();
    if ( m_sobels_y.empty())  sobel_y();

    // 1-范数计算
    m_sobels_1 = cv::abs(m_sobels_x - 128) + cv::abs(m_sobels_y -128);
    m_sobels_1 += 128;  
}
void ImageProc::sobel_2(){
    if (! m_sobels_2.empty()) return;

    if ( m_sobels_x.empty())  sobel_x();
    if ( m_sobels_y.empty())  sobel_y();

    // 2-范数计算
    cv::Mat r2= (m_sobels_x - 128).mul(m_sobels_x - 128) + (m_sobels_y -128).mul(m_sobels_y -128);
    cv::Mat fr2;
    r2.convertTo(fr2, CV_32FC1);
    cv::Mat out;
    cv::sqrt(fr2, out);
    out.convertTo(m_sobels_2, CV_8UC1);
    // m_sobels_2 += 128;   // 算术强化
    m_sobels_2 *= 15;   // 几何强化
}
