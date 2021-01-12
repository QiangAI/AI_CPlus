#include "dlgcv.h"
#include <opencv2/opencv.hpp>
#include <iostream>
// 构造器与析构器
DlgOpenCV::DlgOpenCV(QWidget *parent):
    QDialog(parent),
    dlg(new Ui::dlg_opencv){
    
    dlg->setupUi(this);
}
DlgOpenCV::~DlgOpenCV(){
    delete dlg;
}

// slot函数
void DlgOpenCV::blur(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    // 图像滤波
    cv::Mat  img_dst;
    cv::blur(
        img_src, 
        img_dst, 
        cv::Size2i(100, 100),
        cv::Point2i(-1, -1),
        cv::BORDER_REFLECT_101
    );
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::bilater(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    // 图像滤波
    cv::Mat  img_dst;
    cv::bilateralFilter(
        img_src, 
        img_dst, 
        -1,          // 决定Gaussian中的kernel大小
        200,        // 颜色分散度
        20,        // 像素分散度（与第三个参数选择一个），因为上面使用了5，这个参数就没有意义
        cv::BORDER_REFLECT_101
    );
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::gauss(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    // 图像滤波
    cv::Mat  img_dst;
    cv::GaussianBlur(
        img_src, 
        img_dst, 
        cv::Size2i(51,51),
        50.0,       // 上一个参数b不为0，这个参数不需要计算，这个参数如果大于0，则会计算出标准方差
        50.0,
        cv::BORDER_REFLECT_101
    );
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::box(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    // 图像滤波
    cv::Mat  img_dst;
    cv::boxFilter(
        img_src, 
        img_dst, 
        -1,    // 采用非数据深度格式 CV_32F, CV_8U也行，其他参数对这类加载的图像不行能使用。
        cv::Size2i(51, 51),
        cv::Point2i(-1, -1),
        true,
        cv::BORDER_REFLECT_101
    );
    std::cout<<img_dst.depth()<<std::endl;  // 这个输出是上面参数ddepth设置的格式。
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::fliter2d(){
    cv::Mat kernel = (cv::Mat_<int>(3,3) << 
                    -1,-1,-1,
                    -1, 8,-1,
                    -1,-1,-1);

        // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    // 图像滤波
    cv::Mat  img_dst;
    cv::filter2D(
        img_src, 
        img_dst,
        -1,                 // 输出图像的深度
        kernel,             // 滤波核
        cv::Point2i(-1, -1),    // 锚点
        128.0,                  // 正向（加法运算）偏移值(取255得中间值)
        cv::BORDER_REFLECT_101
    );
    std::cout<<img_dst.depth()<<std::endl;  // 这个输出是上面参数ddepth设置的格式。
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::sobel(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    // 图像滤波
    cv::Mat  img_dst;
    cv::Sobel(
        img_src, 
        img_dst, 
        -1,                // 深度
        3,                 // x偏导阶数
        3,                 // y偏导阶数
        5,                 // kernel size
        10,                 // scale
        0.0,               // delta 
        cv::BORDER_REFLECT_101        
    );
    std::cout<<img_dst.depth()<<std::endl;  // 这个输出是上面参数ddepth设置的格式。
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::median(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    // 图像滤波
    cv::Mat  img_dst;
    cv::medianBlur(
        img_src, 
        img_dst, 
        49
    );
    std::cout<<img_dst.depth()<<std::endl;  // 这个输出是上面参数ddepth设置的格式。
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::laplace(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    // 图像滤波
    cv::Mat  img_dst;
    cv::Laplacian(
        img_src, 
        img_dst, 
        -1,                // 深度
        3,                 // 核大小
        1,                 // 缩放因子
        10.0,               // 偏移量
        cv::BORDER_REFLECT_101        
    );
    std::cout<<img_dst.depth()<<std::endl;  // 这个输出是上面参数ddepth设置的格式。
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}

void DlgOpenCV::down(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    int rows = img_src.rows;
    int cols = img_src.cols;
    std::cout << cols << "," << rows <<std::endl; 
    // 图像滤波
    cv::Mat  img_dst;
    cv::pyrDown(
        img_src, 
        img_dst, 
        cv::Size(cols/2, rows/2),
        cv::BORDER_REFLECT_101        
    );
    std::cout << img_dst.cols << "," << img_dst.rows <<std::endl;  // 这个输出是上面参数ddepth设置的格式。
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::up(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    int rows = img_src.rows;
    int cols = img_src.cols;
    std::cout << cols << "," << rows <<std::endl; 
    // 图像滤波
    cv::Mat  img_dst;
    cv::pyrUp(
        img_src, 
        img_dst, 
        cv::Size(cols*2, rows*2),
        cv::BORDER_REFLECT_101        
    );
    std::cout << img_dst.cols << "," << img_dst.rows <<std::endl;  // 这个输出是上面参数ddepth设置的格式。
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::mean(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    int rows = img_src.rows;
    int cols = img_src.cols;
    // 图像滤波
    cv::Mat  img_dst;
    cv::pyrMeanShiftFiltering(
        img_src, 
        img_dst, 
        20,             // sp: 像素坐标空间范围
        100              // sr: 香色颜色空间范围
    );
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::dilate(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    int rows = img_src.rows;
    int cols = img_src.cols;
    // 图像滤波
    cv::Mat  img_dst;
    cv::Mat  kernel = cv::getStructuringElement(
        cv::MORPH_ELLIPSE,
        cv::Size(100,100),
        cv::Point(-1,-1)
    );
    cv::dilate(
        img_src, 
        img_dst, 
        kernel,
        cv::Point(-1,-1),       // 锚点
        1                      // 迭代次数 （剩下的参数使用默认值，处理式对边界像素的特殊处理）
    );
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::erode(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    int rows = img_src.rows;
    int cols = img_src.cols;
    // 图像滤波
    cv::Mat  img_dst;
    cv::Mat  kernel = cv::getStructuringElement(
        cv::MORPH_ELLIPSE,
        cv::Size(200,200),
        cv::Point(-1,-1)
    );
    cv::erode(
        img_src, 
        img_dst, 
        kernel,
        cv::Point(-1,-1),       // 锚点
        1                      // 迭代次数 （剩下的参数使用默认值，处理式对边界像素的特殊处理）
    );
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::sepfilter(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    int rows = img_src.rows;
    int cols = img_src.cols;
    // 图像滤波
    cv::Mat  img_dst;
    cv::Mat x_kernel = (cv::Mat_<int>(5,1) << 1, 1, -3, 1, 1);
    cv::Mat y_kernel = (cv::Mat_<int>(1,5) << 1, 1, -4, 1, 1);
    cv::sepFilter2D(
        img_src, 
        img_dst, 
        -1,               // 使用默认输出深度
        x_kernel,
        y_kernel          // 1-D卷积核（剩下参数默认）
    );
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::scharr(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    int rows = img_src.rows;
    int cols = img_src.cols;
    // 图像滤波
    cv::Mat  img_dst;
    cv::Scharr(
        img_src,
        img_dst, 
        -1,           // 深度
        0,            // x方向微分阶数
        1,            // y方向微分阶数
        1,            // 控制微分的初始值（方大）
        0.0           // 偏移值（最后一个参数使用默认值）
    );
    
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::sqrbox(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    int rows = img_src.rows;
    int cols = img_src.cols;
    // 图像滤波
    cv::Mat  img_dst;
    cv::sqrBoxFilter(
        img_src, 
        img_dst, 
        -1,           // 深度
        cv::Size(3, 3),    // kernel大小（Box大小）
        cv::Point(-1, -1),   // 锚点
        false   // 标准化
    );
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);
}
void DlgOpenCV::pyramid(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    int rows = img_src.rows;
    int cols = img_src.cols;
    // 图像滤波
    int maxlevels = 1;
    std::vector<cv::Mat>  img_dst;   // 输出金字塔多层(可以使用std::vector, cv::Mat，std::array)
    cv::buildPyramid(
        img_src,
        img_dst,
        1               // 金字塔层数（使用的是maxlevel + 1）
    );
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst[0], img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);

    // 迭代输出金字塔图像的大小。
    for(cv::Mat im : img_dst){  // 循环与上面设置的maxlevels有关系
        std::cout << im.cols << "," << im.rows <<std::endl;  
    }
}
void DlgOpenCV::morph(){
    // 加载图像（为了方便，没有把图像作为成员数据）
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    int rows = img_src.rows;
    int cols = img_src.cols;
    // 图像滤波
    cv::Mat  img_dst;
    cv::Mat  kernel = cv::getStructuringElement(
        cv::MORPH_ELLIPSE,
        cv::Size(100,100),
        cv::Point(-1,-1)
    );
    cv::morphologyEx(
        img_src, 
        img_dst, 
        cv::MORPH_OPEN,
        kernel,
        cv::Point2i(-1, -1),        // 锚点
        1                           // 迭代次数（其他采用默认参数）
    );
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_output->setPixmap(img_pix);
    this->dlg->lbl_output->setScaledContents(true);    
}
