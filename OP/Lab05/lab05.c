#include <stdio.h>
#include <conio.h>
#include "lab05_func.h"

int main(){
    double a = 0, b = 0, h = 0;
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter step: ");
    scanf("%lf", &h);
    tabulate(a, b, h);
    tabulate2(a, b, h);
    getch();
}