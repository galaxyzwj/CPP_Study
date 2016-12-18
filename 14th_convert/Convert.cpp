#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **agrv)
{
    double d = 100.1;
    int i = d; // double转换为int
    const char *str1 = "100ask.taobao.com";
    char *str2 = const_cast<char *>(str1);
    int *p = reinterpret_cast<int *>(str2); // char *转为int *
    
    printf("i=%d, str = 0x%x, p = 0x%x\n", i, reinterpret_cast<unsigned int>str1, reinterpret_cast<unsigned int>str2);
    
    return 0;
}

