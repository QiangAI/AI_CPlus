#include <stdio.h>
#include <windows.h>
#include "add.h"


int main(int argc, char **argv){
    HMODULE h = LoadLibraryA("add.dll");
    if(h==NULL){
        printf("加载动态库文件失败\n");
        return -1;
    }
    else{
        printf("加载动态库文件成功:%p\n", h);
    }
    // 查找符号函数
    FARPROC f = GetProcAddress(h,"yq_add");
    if(f==NULL){
        printf("查找函数失败！\n");
        // 释放加载的库
        FreeLibrary(h);
        return -1;
    }
    else{
        printf("查找函数成功:%p\n", f);
    }
    // 调用函数
    int(*func)(int,int) = f;    // 函数指针赋值

    // 调用函数
    printf("调用结果:%d\n", func(200, 55));

    FreeLibrary(h);
    return 0;
}
