#include <stdio.h>
#include "add.h"
#pragma comment(lib, "add.lib") 

int main(int argc, char **argv){
    printf("调用结果:%d\n", yq_add(200, 55));
    return 0;
}
