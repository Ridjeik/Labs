#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lab09_lib.h"


int main(int argc, char *argv[]){
    int num = 0;
    Array **arrays;

    if(argc > 1 && strcmp(argv[1], "-r") == 0){
        srand(time(NULL));
        num = rand() % RAND_MAX_ARRAY_COUNT + 1;
        arrays = createArraysRandomly(num, RAND_MAX_ELEMENT_COUNT, RAND_MAX_ELEMENT);
    }
    else if(checkCommandLineArgs(argc, argv)){
        num = atoi(argv[1]);
        arrays = createArraysFromCommandLine(argc, argv);
    }
    else{
        printf("Enter count of arrays: ");
        scanf("%d", &num);
        printf("\n");
        arrays = createArraysFromConsole(num);
    }
    
    printf("\nCount of arrays: %d", num);

    printf("\n\nUnsorted list of arrays:\n");
    printManyArrays(arrays, num);

    sortArrayOfArrays(arrays, num);

    printf("\n\nSorted list:\n");
    printManyArrays(arrays, num);

    freeSubArrays(arrays,num);
    free(arrays);

    return 0;
}