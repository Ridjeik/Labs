#include "lab09_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Array *createIntArr(int arrSize){
    int *mem = (int*)calloc(arrSize, sizeof(int));
    if(!mem) return NULL;
    Array *structMem = (Array*)malloc(sizeof(Array));
    if(!structMem) return NULL;
    structMem->values = mem;
    structMem->size = arrSize;
    return structMem;
}

int intArrCmp(Array* a, Array* b){
    if(a == NULL || b == NULL) return 0;
    for(int i = 0; i < min(a->size, b->size); i++){
        if(a->values[i] > b->values[i]) return 1;
        else if(a->values[i] < b->values[i]) return -1;
    }
    if(a->size > b->size) return 1;
    else if(b->size > a->size) return -1;
    else return 0;
}

void printArray(Array *arr){
    if(arr == NULL) return;
    printf("[");
    for(int i = 0; i < arr->size - 1; i++){
        printf("%d, ", arr->values[i]);
    }
    printf("%d", arr->values[arr->size - 1]);
    printf("]\n");
}

void printManyArrays(Array **arrays, int size){
    for(int i = 0; i < size; i++){
        printArray(*(arrays + i));
    }
}

void swap(Array **a, Array **b){
    Array *temp = *a;
    *a = *b;
    *b = temp;
}

void sortArrayOfArrays(Array **arrays, int size){
    if(arrays == NULL) return;
    for(int i = 0; i < size; i++){
        for(int j = 1; j < size-i; j++){
            if(intArrCmp(*(arrays + j - 1), *(arrays + j)) > 0){
                swap(arrays + j - 1, arrays + j);
            }
        }
    }
}

void freeSubArrays(Array **arrays, int size){
    if(arrays == NULL) return;
    for(int i = 0; i < size; i++){
        if(arrays + i == NULL) continue;
        if((*(arrays + i))->values != NULL) free((*(arrays + i))->values);
        free(*(arrays + i));
    }
}

void randomFill(Array *array, int maxElem){
    for(int i = 0; i < array->size; i++){
        array->values[i] = rand() % maxElem + 1;
    }
}

Array **createArraysRandomly(int arraysCount, int maxElementsCount, int maxElement){
    if(arraysCount <= 0 || maxElementsCount <= 0 || maxElement <= 0) return NULL;
    srand(time(NULL));
    int size = 0;
    Array **arrays = (Array**)calloc(arraysCount, sizeof(Array*));
    if(arrays == NULL) return NULL;

    for(int i = 0; i < arraysCount; i++){
        size = rand() % maxElementsCount + 1;
        *(arrays+ i) = createIntArr(size);
        if(*(arrays + i) == NULL) return NULL;
        randomFill(*(arrays + i), maxElement);
    }

    return arrays;
}

void fillArrayFromConsole(Array *array){
    for(int i = 0; i < array->size; i++){
        scanf("%d", array->values + i);
    }
}

int checkCommandLineArgs(int argc, char *argv[]){
    int num = 0;
    if(argc > 1 && atoi(argv[1]) == argc - 2){
        for(int i = 2; i < argc; i++){
            if(atoi(argv[i]) < 1) return 0;
        }
        return 1;
    }
    return 0;
}

Array **createArraysFromCommandLine(int argc, char *argv[]){
    Array **arrays;
    int arraysCount = atoi(argv[1]);

    arrays = (Array**)calloc(arraysCount, sizeof(Array*));

    int arraySize = 0;
    for(int i = 0; i < arraysCount; i++){
        arraySize = atoi(argv[i + 2]);
        *(arrays + i) = createIntArr(arraySize);
        printf("Enter elements of %d%s array(size: %d): ", i+1, i + 1 == 1 ? "st" : i + 1 == 2 ? "nd" : i + 1 == 3 ? "rd" : "th", arraySize);
        fillArrayFromConsole(*(arrays + i));
    }

    return arrays;
}

Array **createArraysFromConsole(int arraysCount){
    Array **arrays;

    arrays = (Array**)calloc(arraysCount, sizeof(Array*));

    int arraySize = 0;
    for(int i = 0; i < arraysCount; i++){
        printf("\nEnter size of %d%s array: ", i+1, i + 1 == 1 ? "st" : i + 1 == 2 ? "nd" : i + 1 == 3 ? "rd" : "th");
        scanf("%d", &arraySize);
        
        *(arrays + i) = createIntArr(arraySize);
        printf("Enter elements of %d%s array: ", i+1, i + 1 == 1 ? "st" : i + 1 == 2 ? "nd" : i + 1 == 3 ? "rd" : "th");
        fillArrayFromConsole(*(arrays + i));
    }

    return arrays;
}

// [address]            [address]           [address]           [address]           [address]
// [[elems] [size]]     [[elems] [size]]    [[elems] [size]]    [[elems] [size]]    [[elems] [size]]
// [num           ]     [num num num num]   [num num       ]    [num num num   ]    [num num num num]