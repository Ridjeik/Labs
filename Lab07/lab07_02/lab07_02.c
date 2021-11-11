#include <stdio.h>
#include <conio.h>
#include "lab07_02_func.h"

int main(){
    double a, b, h;
    int choice;
    printf("Enter start and end values: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter step: ");
    scanf("%lf", &h);
    printf("\n(0) for\n(1) while\n(2) do while\nWhich cycle would you choose? ");
    
    do{
        scanf("%d", &choice);
    }while(choice < 0 && choice > 2);

    void (*tabFuncs[3]) (double, double, double) = {forTab, whileTab, doWhileTab};

    tabFuncs[choice](a, b, h);
    getch();
}