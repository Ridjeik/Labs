#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include "lab06_02_func.h"

int containsSeven(int num){
    num = num < 0 ? -num : num;
    while(num > 0){
        if(num % 10 == 7) return 1;
        num /= 10;
    }
    return 0;
}

int find_nums(int num, ...){
    int n = num;
    va_list args;
    va_start(args, num);
    int count = 0;
    while(n != -1){
        if(n % 2 == 0 && !containsSeven(n)){
            printf("%d ", n);
            count++;
        }
        n = va_arg(args, int);
    }
    va_end(args);
    return count;
}