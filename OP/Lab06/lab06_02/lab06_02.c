#include <stdio.h>
#include <conio.h>
#include "lab06_02_func.h"

#define MAX_SIZE 25

int main(){
    int arr[MAX_SIZE] = {0};
    printf("Numbers: ");

    for(int i = 0; i < MAX_SIZE; i++){
        scanf("%d", arr+i);
        if(arr[i] == -1) break;
    }
    
    printf("Result: ");
    int quantity = find_nums(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9],
                                arr[10], arr[11], arr[12], arr[13], arr[14], arr[15], arr[16], arr[17], arr[18],
                                arr[19], arr[20], arr[21], arr[22], arr[23], arr[24]);
    
    if(quantity != 0) printf("\nFinded numbers: %d\n", quantity);
    else printf("\nNo such numbers.");
    getch();
    return 0;
}

