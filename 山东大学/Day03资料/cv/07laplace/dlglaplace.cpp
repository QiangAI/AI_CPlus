#include "dlglaplace.h"

#include <iostream>
// 构造器与析构器
DlgLaplace::DlgLaplace(QWidget *parent):
    QDialog(parent),
    dlg(new Ui::dlg_laplace){
    
    dlg->setupUi(this);
}
DlgLaplace::~DlgLaplace(){
    delete dlg;
}
// slot函数
void DlgLaplace::image_proc(){
    // 加载图像
    cv::Mat  img_src;
    img_src = cv::imread("bird.png");
    cv::Mat  img_dst;
    // OpenCV lapalce处理
    cv::Laplacian(img_src, img_dst, -1, 7, 1, 10.0, cv::BORDER_REFLECT_101);
    // img_dst = img_src;
    // 显示图像
    cv::Mat  img_out;
    cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2RGBA); 
    // QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);
    
    // cv::cvtColor(img_dst, img_out, cv::COLOR_BGR2GRAY); 
    // cv::cvtColor(img_out, img_out, cv::COLOR_GRAY2RGBA); 
    // std::cout<<img_out.rows << "," << img_out.cols << std::endl;
    // std::cout<<img_out.channels() << "," << img_out.type() << std::endl;
    QImage q_img(img_out.data, img_out.cols, img_out.rows,QImage::Format_RGBA8888);

    QPixmap img_pix = QPixmap::fromImage(q_img);
    this->dlg->lbl_opencv->setPixmap(img_pix);
    this->dlg->lbl_opencv->setScaledContents(true);

    // 手工处理
    cv::Mat  img_manual;
    // --------------------------------
    // laplace_g(img_src, img_manual);
    // laplace(img_src, img_manual);
    laplace_f(img_src, img_manual);
    // img_manual = img_manual - img_src;
    // --------------------------------
    // 显示图像
    cv::Mat  img_out_m;
    cv::cvtColor(img_manual, img_out_m, cv::COLOR_BGR2RGBA); 

    // cv::cvtColor(img_manual, img_out_m, cv::COLOR_GRAY2RGBA); 
    QImage q_img_m(img_out_m.data, img_out_m.cols, img_out_m.rows, QImage::Format_RGBA8888);

    QPixmap img_pix_m = QPixmap::fromImage(q_img_m);
    this->dlg->lbl_manual->setPixmap(img_pix_m);
    this->dlg->lbl_manual->setScaledContents(true);

}
///////////////////////////////
void  DlgLaplace::laplace(cv::InputArray src, cv::OutputArray dst){
    /* 
     cv::InputArray src：输入的图像
     cv::OutputArray dst：输出的图像
     - 本版本函数，没有提供类型转换，采用uchar运算
     */

    // 下面使用cv::Mat表示方式，纯粹是为了操作方便；
    cv::Mat s_img = src.getMat();       
    cv::Mat &d_img = dst.getMatRef();   // 需要修改其中的图像，所以返回引用
    std::cout<< "原图：" << s_img.type() << std::endl;
    // 构造拉普拉斯kernel
    cv::Mat kernel = (
        cv::Mat_<cv::Vec3b>(3,3) << 
            cv::Vec3b(0, 0, 0), cv::Vec3b( 1,  1,  1), cv::Vec3b(0, 0, 0),
            cv::Vec3b(1, 1, 1), cv::Vec3b(-4, -4, -1), cv::Vec3b(1, 1, 1),
            cv::Vec3b(0, 0, 0), cv::Vec3b( 1,  1,  1), cv::Vec3b(0, 0, 0)
    );
    
    std::cout<< "kernel：" << kernel.type() << std::endl;
    // 1. 获取图像行列
    int rows = s_img.rows;
    int cols = s_img.cols;

    // 2. 构造一个Padding图像，Padding补0
    cv::Mat p_img(rows + 2 , cols + 2, s_img.type(), cv::Scalar_<u_char>(0, 0, 0));
    
    // 3. 拷贝图像到padding图像
    s_img.copyTo(p_img(cv::Range(1,rows+1), cv::Range(1, cols+1)));  // 完全相等才能拷贝，否则会调用create
    std::cout<< "补丁：" << p_img.type() << std::endl;
    // 4. 定义输出（与源图像同大小与类型）
    cv::Mat m_out(rows, cols, s_img.type());
    // 5. 循环计算没有输出像素
    for(int y = 0; y< rows; y++){
        for(int x = 0; x< cols; x++){
            // 获取padding图像的子图
            cv::Mat sub = p_img(cv::Range(y, y + 3), cv::Range(x, x + 3)); // 子图大小为3
            // 计算矩阵hadamard乘积
            cv::Mat prod = sub.mul(kernel); // 子图与kernel矩阵的乘积 
            // 计算矩阵的和
            cv::Scalar pixel = cv::sum(prod);
            // 赋值结果到输出图像
            m_out.at<cv::Vec3b>(y, x) = cv::Vec3b(pixel[0], pixel[1], pixel[2]);
        }
    }
    m_out += s_img;
    std::cout<< "输出：" << m_out.type() << std::endl;
    // 处理的结果拷贝到输出
    m_out.copyTo(d_img);
    // cv::Mat diff = s_img - m_out;
    // diff.copyTo(d_img);
    std::cout<< "引用：" << d_img.type() << std::endl;
}
void  DlgLaplace::laplace_f(cv::InputArray src, cv::OutputArray dst){
    /*
        本版本为了计算的精度，使用了类型转换：小数；
     */
    cv::Mat s_img = src.getMat(); 
    cv::Mat &d_img = dst.getMatRef();   // 需要修改其中的图像，所以返回引用
    ////////////////////////////
    cv::Mat fs_img;
    s_img.convertTo(fs_img, CV_32FC3);  //32f
    // 构造拉普拉斯kernel
    cv::Mat kernel = (
        cv::Mat_<cv::Vec3f>(3,3) << 
            cv::Vec3f(0.0, 0.0, 0.0), cv::Vec3f( 1.0,  1.0,  1.0), cv::Vec3f(0.0, 0.0, 0.0),
            cv::Vec3f(1.0, 1.0, 1.0), cv::Vec3f(-4.0, -4.0, -1.0), cv::Vec3f(1.0, 1.0, 1.0),
            cv::Vec3f(0.0, 0.0, 0.0), cv::Vec3f( 1.0,  1.0,  1.0), cv::Vec3f(0.0, 0.0, 0.0)
    );
    // 1. 获取图像行列
    int rows = fs_img.rows;
    int cols = fs_img.cols;
    // 2. 构造一个Padding图像，Padding补0
    cv::Mat p_img(rows + 2 , cols + 2, fs_img.type(), cv::Scalar_<float>(0.0, 0.0, 0.0));
    // 3. 拷贝图像到padding图像
    fs_img.copyTo(p_img(cv::Range(1,rows+1), cv::Range(1, cols+1)));  // 完全相等才能拷贝，否则会调用create
    // 4. 定义输出（与源图像同大小与类型）
    cv::Mat m_out(rows, cols, fs_img.type());
    // 5. 循环计算没有输出像素
    for(int y = 0; y< rows; y++){
        for(int x = 0; x< cols; x++){
            // 获取padding图像的子图
            cv::Mat sub = p_img(cv::Range(y, y + 3), cv::Range(x, x + 3)); // 子图大小为3
            // 计算矩阵hadamard乘积
            cv::Mat prod = sub.mul(kernel); // 子图与kernel矩阵的乘积 
            // 计算矩阵的和
            cv::Scalar pixel = cv::sum(prod);
            // 赋值结果到输出图像
            m_out.at<cv::Vec3f>(y, x) = cv::Vec3f(pixel[0], pixel[1], pixel[2]);

            /* 与上面效果一样，除了速度慢点*/
            // cv::Vec3f pixel(0.0, 0.0, 0.0);
            // for(int i = 0; i < 3; i++){
            //     for(int j = 0; j < 3; j++){
            //         cv::Vec3f p1 = sub.at<cv::Vec3f>(j, i);
            //         cv::Vec3f p2 = kernel.at<cv::Vec3f>(j, i);
            //         pixel[0] += p1[0] * p2 [0];
            //         pixel[1] += p1[1] * p2 [1];
            //         pixel[2] += p1[2] * p2 [2];
            //     }
            // }
            // m_out.at<cv::Vec3f>(y, x) = pixel;
        }
    }
    m_out *= 128.0;
    m_out += fs_img;
    // 归一化
    // double max, min;
    // cv::minMaxLoc(m_out, &min, &max);
    // m_out /= max - min;
    // m_out *= 255;
    // std::cout<< max << "," << min << std::endl;
    ///////////////////////////
    // 转换为CV_8UC3
    m_out.convertTo(d_img, CV_8UC3);
}

///////////////////////////////
void  DlgLaplace::laplace_g(cv::InputArray src, cv::OutputArray dst){
    /* 
     cv::InputArray src：输入的图像
     cv::OutputArray dst：输出的图像
     */

    // 下面使用cv::Mat表示方式，纯粹是为了操作方便；
    cv::Mat s_img = src.getMat();       
    cv::Mat &d_img = dst.getMatRef();   // 需要修改其中的图像，所以返回引用
    // 转换为弧度操作
    cv::Mat g_img;
    cv::cvtColor(s_img, g_img, cv::COLOR_BGR2GRAY); 
    cv::Mat i_img;
    g_img.convertTo(i_img, CV_32FC1);  //32f
    cv::Mat kernel = (
        cv::Mat_<float>(3,3) << 
            0.0,  1.0, 0.0,
            1.0, -4.0, 1.0,
            0.0,  1.0, 0.0
    );
    // 1. 获取图像行列
    int rows = g_img.rows;
    int cols = g_img.cols;
    // 2. 构造一个Padding图像，Padding补0
    cv::Mat p_img(rows + 2 , cols + 2, i_img.type(), cv::Scalar_<float>(0.0));
    // 3. 拷贝图像到padding图像
    i_img.copyTo(p_img(cv::Range(1,rows+1), cv::Range(1, cols+1)));  // 完全相等才能拷贝，否则会调用create
    // 4. 定义输出（与源图像同大小与类型）
    cv::Mat m_out(rows, cols, i_img.type());
    for(int y = 0; y< rows; y++){
        for(int x = 0; x< cols; x++){
            // 获取padding图像的子图
            cv::Mat sub = p_img(cv::Range(y, y + 3), cv::Range(x, x + 3)); // 子图大小为3
            // 计算矩阵hadamard乘积
            cv::Mat prod = sub.mul(kernel); // 子图与kernel矩阵的乘积 
            // 计算矩阵的和
            cv::Scalar pixel = cv::sum(prod);
            // 赋值结果到输出图像
            m_out.at<float>(y, x) = pixel[0];
        }
    }
    m_out *= 100;
    m_out += i_img;
    std::cout << m_out.at<float>(50,50)<< std::endl;
    m_out.convertTo(d_img, CV_8UC1);
    std::cout << int(d_img.at<u_char>(50,50))<< std::endl;
}
