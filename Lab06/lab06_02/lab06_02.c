#include <stdio.h>
#include <conio.h>
#include "lab06_02_func.h"

int find_nums(int num, ...);

int main(){
    int quantity = find_nums(1, 4, 77, 125, 26, 88, 200, 74, -4, -8, -174, 13, 7, -1, 6);
    
    if(quantity != 0) printf("\nFinded numbers: %d\n", quantity);
    else printf("No such numbers");
    getch();
    return 0;
}

