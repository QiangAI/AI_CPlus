#include <iostream>
#include <locale.h>
#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#include <opencv2/opencv.hpp>


int main(int argc, const char** argv) {
    // 1. 初始化字体库 
    FT_Library  library;
    int error = FT_Init_FreeType( &library );
    if (error){
        std::cout<< "初始化字体库错误！" <<std::endl;
        return -1;
    }
    std::cout << "库初始化成功！" << std::endl;

    // 2. 加载字体库
    FT_Face     face; 
    error = FT_New_Face(library,
                     "msyh.ttf",    // 自己找一个ttf格式的字体库文件
                     0,             // 如果几个字体类型，封装在一个字体库文件中，需要指定字体类型索引编号，一般0就行了
                     &face);
    if ( error == FT_Err_Unknown_File_Format ){
        std::cout << "字体文件格式错误！" << std::endl;
        return -2;
    }
    else if ( error ){
        std::cout << "加载字体库错误！" << std::endl;
        return -3;
    }
    std::cout << "字体加载成功！" << std::endl;
    
    // 3. 设置字体大小
    error = FT_Set_Char_Size(
          face,    /* handle to face object             */
          16*64,       /* 字符宽度，单位1/64点                 */
          16*64,   /* 字符高度，单位1/64点                 */
          500,     /* 水平方向分辨率DPI 默认是72            */
          500 );   /* 垂直方向分辨率DPI(Dots Per Inch)     */   // 这个也决定最后输出的图像大小
    if (error){
        std::cout<< "设置字体大小错误！" <<std::endl;
        return -4;
    }
    std::cout << "设置字体大小成功！" << std::endl;

    // 4. 把字符转换为索引
    wchar_t		ch_char = L'汗';
    int char_index = FT_Get_Char_Index( face, ch_char);
    std::cout << ch_char << "索引是：" << char_index << std::endl;

    // 5. 加载字符图像
    error = FT_Load_Glyph(
          face,                 /* handle to face object   */
          char_index,           /* 字体索引                 */
          FT_LOAD_DEFAULT);     /* 加载方式                 */
    if (error){
        std::cout<< "加载字符图像失败！" <<std::endl;
        return -5;
    }
    std::cout << "加载字符图像成功！" << std::endl;

    // 6. 绘制字符图像到slot
    error = FT_Render_Glyph(
        face->glyph,   /* 字符图像slot  */
        FT_RENDER_MODE_NORMAL ); /* 渲染方式 */
    if (error){
        std::cout<< "渲染字符图像失败！" <<std::endl;
        return -6;
    }
    std::cout << "渲染字符图像成功！" << std::endl;

    // 7. 处理导出的图像为cv::Mat
    FT_GlyphSlot  slot = face->glyph;  /* 渲染的图像槽（slot） */
    int img_h = slot->bitmap.rows;
    int img_w = slot->bitmap.width;
    int img_d = slot->bitmap.pitch;    // 每一行的数据位数
    std::cout<< img_h << "," << img_w << "," << img_d << std::endl;

    // opencv的缓冲图像表示
    cv::Mat  img(img_h, img_w, CV_8UC1);
    // 按照行列循环，开始导出图像像素到cv::Mat。
    for(int y = 0; y < img_h; y++){
        for(int x = 0; x < img_w; x++){
            img.at<uchar>(y,x) = slot->bitmap.buffer[y * img_d + x];
        }
    }
    // 显示汉字的图像
    cv::namedWindow("W", cv::WINDOW_NORMAL);
    cv::resizeWindow("W", 400,300);
    cv::imshow("W", img);
    cv::waitKey();
    return 0;
}

// 编译指令：g++ -omain  cv13_freetype.cpp -std=c++11 -I/usr/local/include/freetype2  -I/usr/local/include/opencv4 -lfreetype -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc 