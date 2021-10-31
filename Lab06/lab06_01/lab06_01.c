#include <stdio.h>
#include <conio.h>
#include "lab06_01_func.h"

int main(){
    int size;
    double M[MAX_SIZE][MAX_SIZE];
    printf("Size: ");
    scanf("%d", &size);
    printf("Elements:\n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            scanf("%lf", *(M + i) + j);
        }
    }

    printf(isOrthogonal(M, size) ? "Orthogonal" : "Not orthogonal");
    getch();
    return 0;
}