#include <stdio.h>
#pragma comment(lib, "add.lib") 

int main(int argc, char **argv){
    printf("调用结果:%d\n", mod_add(200, 55));
    return 0;
}
