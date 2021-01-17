#include "guis/app.h"
// #include <windows.h>
// #include <cstdlib>
// 控制台应用
int main(int argc, char **argv, char **arge){
    App a(argc, argv);
    return a.exec();
}

// // 窗体应用
// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPTSTR lpcommand, int nShoweCmd){
//     App a(__argc, __argv);
//     return a.exec();
// }
