#include <stdio.h>
#include "lab05_func.h"

double func(double x){
    return (3*x*x + x - 2)/(3*x + 1);
}
int func2(double x, double *y){
    double res = func(x);
    *y = res;
    
    if(res < 1e-6 && res > -1e-6){
        return 0;
    }
    else if (res > 0)
    {
        return 1;
    }
    else{
        return -1;
    } 
}

void tabulate(double a, double b, double h){
    if(a < b && h < b-a){
        printf("1)\n");
        printf("%-10s | %-10s\n", "X", "Y");
        for(double x = a; x <= b; x += h){
            printf("------------------------\n");
            printf("% -10.4lf | % -10.4lf\n", x, func(x));
        }
    }
    else{
        printf("Incorrect parameters!");
    }
}

void tabulate2(double a, double b, double h){
    if(a < b && h < b-a){
        double y = 0;
        int res = 0;

        printf("2)\n");
        printf("%-10s | %-10s | %-10s\n", "X", "Y", "Return");
        for(double x = a; x <= b; x += h){
            printf("------------------------------------\n");
            res = func2(x, &y);
            printf("% -10.4lf | % -10.4lf | % -10d\n", x, y, res);
        }
    }
    else{
        printf("Incorrect parameters!");
    }
}

/*
void tabulate(double a, double b, double h){
    if(a < b && h < b-a){
        double y = 0;
        int res = 0;

        printf("1)\n");
        printf("%-10s | %-10s\n", "X", "Y");
        for(double x = a; x <= b; x += h){
            printf("------------------------\n");
            printf("% -10.4lf | % -10.4lf\n", x, func(x));
        }

        printf("2)\n");
        printf("%-10s | %-10s | %-10s\n", "X", "Y", "Return");
        for(double x = a; x <= b; x += h){
            printf("------------------------------------\n");
            res = func2(x, &y);
            printf("% -10.4lf | % -10.4lf | % -10d\n", x, y, res);
        }
    }
    else{
        printf("Incorrect parameters!");
    }
}
*/