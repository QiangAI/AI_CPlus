#include <iostream>
#include <windows.h>

#pragma comment(lib, "model.lib")
__declspec(dllimport) int var_a;
__declspec(dllimport) int var_b;

float calculate(float, float);

int main(int argc, const char *argv){
    std::cout << "---------------编译调用-------------------" << std::endl;
    std::cout << var_a << std::endl;
    std::cout << var_b << std::endl;
    std::cout << calculate(45.0, 55.0) << std::endl;   
    std::cout << var_a << std::endl;
    std::cout << var_b << std::endl;

    std::cout << "---------------动态调用-------------------" << std::endl;
    HMODULE h = LoadLibraryA("libmodel.dll");
    if(h == NULL){
        std::cout << "加载动态库文件失败！" << std::endl;
        return -1;
    }
    else{
        std::cout << "加载动态库文件成功！" << std::endl;
    }
    // 查找符号函数
    // FARPROC v = GetProcAddress(h, "var_b");       // 非修饰名
    // FARPROC v = GetProcAddress(h, "?var_a@@3HA");    // 修饰名
    FARPROC v = GetProcAddress(h, MAKEINTRESOURCEA(2));    // 序号 #define MAKEINTRESOURCEA(i) (LPSTR)((DWORD)((WORD)(i)))
    if(v == NULL){
        std::cout << "查找变量失败！" << std::endl;
        // 释放加载的库
        FreeLibrary(h);
        return -1;
    }
    else{
        std::cout << "查找变量成功！" << std::endl;
    }
    // 调用变量
    std::cout << *(int*)v << std::endl;

    FreeLibrary(h);
    
    return 0;
}
