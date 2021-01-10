#include <iostream>
#include <windows.h>
#include "model.h"

#pragma comment(lib, "model.lib")

typedef Sobel (*builder)();

int main(int argc, const char *argv){
    std::cout << "---------------编译调用-------------------" << std::endl;
    Sobel s;   // 构造对象
    int re = s.getInfo("Hello"); // 调用成员
    std::cout << "动态库调用结果:" << re << std::endl; 
    
    std::cout << "---------------编译调用-------------------" << std::endl;
    HMODULE h = LoadLibraryA("libmodel.dll");
    if(h == NULL){
        std::cout << "加载动态库文件失败！" << std::endl;
        return -1;
    }
    else{
        std::cout << "加载动态库文件成功！" << std::endl;
    }
    // 查找符号函数
    FARPROC cls_name = GetProcAddress(h, MAKEINTRESOURCEA(1)); 
    FARPROC cls_getInfo = GetProcAddress(h, MAKEINTRESOURCEA(2));    
    if(cls_name == NULL || cls_getInfo == NULL){
        std::cout << "查找类或者成员函数失败！" << std::endl;
        // 释放加载的库
        FreeLibrary(h);
        return -1;
    }
    else{
        std::cout << "查找类构造器与成员函数成功！" << std::endl;
    }
    // 调用变量
    builder con = (builder)cls_name;
    Sobel sobel = con();
    int r = sobel.getInfo("Hello"); // 调用成员
    std::cout << "动态库手工调用结果:" << r << std::endl; 
    std::cout << "---------------------------------------" << std::endl;
    int (*cal)(const char *) =(int (*)(const char *)) cls_getInfo;     // 没有对象依赖，指向没有初始化的全局栈位置。
    std::cout << "动态库手工调用结果:" << cal("world") << std::endl;
    FreeLibrary(h);
    
    return 0;
}
