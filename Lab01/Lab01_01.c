#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(void){
    double X = 0, Y = 0;
    const double Z = 0.15;
    printf("X = ");
    scanf("%lf", &X);
    printf("Y = ");
    scanf("%lf", &Y);
    double b = pow(asin(Z), 2) + fabs(X + Y);
    printf("b = %lf", b);
    getch();
    return 0;
}
