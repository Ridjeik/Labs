#include <stdio.h>
#include <conio.h>
#include "lab06_03_func.h"

int main(){
    int N, prod, Q = 0;
    printf("Number: ");
    scanf("%d", &N);
    if(isAnswerExist(N)){
        do{
            Q++;
            int temp = Q;
            POD(Q, prod);
            Q = temp;
        }while(prod != N);

        printf("Answer: %d", Q);
    }
    else{
        printf("No answer.");
    }
    getch();
    return 0;
}