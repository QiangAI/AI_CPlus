#include "guis/app.h"
#include <windows.h>
#include <stdlib.h>

int  main(int argc, char **argv){
    App p(argc, argv);
    return p.exec();
}

// 窗体应用
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpCmdLine, int nShowCmd){
    // 可以解析lpCmdLine得到argc与argv，但这里我们直接使用stdlib.h中的内置变量__argc, __argv
    App p(__argc, __argv);
    return p.exec();
    
}
