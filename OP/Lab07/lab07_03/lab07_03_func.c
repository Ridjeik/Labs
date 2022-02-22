#include <stdio.h>
#include "lab07_03_func.h"

void get_and_print(){
    char str;
    str = getchar();
    if(str != EOF){
        get_and_print();
    }
    printf("%c", str);
}