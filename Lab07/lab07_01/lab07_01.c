#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "lab07_01_func.h"

#define SIZE 25000

int main(){
    clock_t qs_start_time = 0, qs_end_time = 0, bs_start_time = 0, bs_end_time = 0;
    srand(time(NULL));

    int arr_qs[SIZE], arr_bs[SIZE];

    for(int i = 0; i < SIZE; i++){
        arr_qs[i] = arr_bs[i] = rand();
    }
    if(!is_equal_arrays(arr_qs, arr_bs, SIZE)){
        printf("Error: start arrays aren't equal.\n");
    }

    qs_start_time = clock();
    qs_sort(arr_qs, 0, SIZE-1);
    qs_end_time = clock();
    bs_start_time = clock();
    bubble_sort(arr_bs, SIZE);
    bs_end_time = clock();
    
    if(!is_equal_arrays(arr_qs, arr_bs, SIZE)){
        printf("Error: result arrays aren't equal.\n");
    }
    else if(!is_sorted(arr_qs, SIZE)){
        printf("Error: arrays aren't sorted.\n");
    }
    else{
        printf("\nSorting was successful.\n");
        printf("Quick sort: %.3lf seconds.\n", (double)(qs_end_time - qs_start_time)/ CLOCKS_PER_SEC);
        printf("Bubble sort: %.3lf seconds.\n", (double)(bs_end_time - bs_start_time)/ CLOCKS_PER_SEC);
    }
    getch();
}