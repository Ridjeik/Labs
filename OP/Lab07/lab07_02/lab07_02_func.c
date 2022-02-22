#include <math.h>
#include <stdio.h>

double f(double x){
    if(x - 1 > - 1e-6  || fabs(x) < 1e-6 || x < -1) return NAN;
    return asin(sqrt(x))/sqrt(x * (1-x));
} 

void forTab(double a, double b, double h){
    if(b < a) return;
    printf("\n  [For tabulation]  \n");
    printf("%-8s | %8s\n", "X", "Y");
    printf("---------+---------\n");
    
    for(double x = a; x < b; x += h){
        double res = f(x);
        if(isnan(res)){
            printf("%-8.3lf | %8s\n", x, "Not def.");    
        } 
        else 
            printf("%-8.3lf | %8.3lf\n", x, res);
    }
}
void whileTab(double a, double b, double h){
    if(b < a) return;
    printf("\n [While tabulation] \n");
    printf("%-8s | %8s\n", "X", "Y");
    printf("---------+---------\n");
    double x = a;
    while(x < b){
        double res = f(x);
        if(isnan(res)){
            printf("%-8.3lf | %8s\n", x, "Not def.");    
        } 
        else 
            printf("%-8.3lf | %8.3lf\n", x, res);
        x += h;
    }
}
void doWhileTab(double a, double b, double h){
    if(b < a) return;
    printf("\n[DoWhile tabulation]\n");
    printf("%-8s | %8s\n", "X", "Y");
    printf("---------+---------\n");
    double x = a;
    do{
        double res = f(x);
        if(isnan(res)){
            printf("%-8.3lf | %8s\n", x, "Not def.");    
        } 
        else 
            printf("%-8.3lf | %8.3lf\n", x, res);
        x += h;
    }while(x < b);
}
