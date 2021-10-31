#include <stdio.h>
#include <conio.h>
#include "lab06_03_func.h"

int main(){
    int n, prod, I = 0;
    scanf("%d", &n);
    if(isAnswerExist(n)){
        do{
            I++;
            POD(I, prod);
        }while(prod != n);

        printf("%d", I);
    }
    else{
        printf("No answer.");
    }
    return 0;
}