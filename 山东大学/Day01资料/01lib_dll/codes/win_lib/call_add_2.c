#include <stdio.h>
#include "add.h"

#pragma comment(lib, "add.lib")

int main(int argc, char **argv){
    printf("计算你结果：%d\n", yq_add(45,55));
    return 0;
}
