#ifndef LAB09
#define LAB09

#define RAND_MAX_ARRAY_COUNT 10
#define RAND_MAX_ELEMENT_COUNT 10
#define RAND_MAX_ELEMENT 20


#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct{
    int* values;
    int size;
} Array;

Array *createIntArr(int arrSize);
void printArray(Array *arr);
void printManyArrays(Array **arrays, int size);
void sortArrayOfArrays(Array **arrays, int size);
void freeSubArrays(Array **arrays, int size);
Array **createArraysRandomly(int arraysCount, int maxElementsCount, int maxElement);
int checkCommandLineArgs(int argc, char *argv[]);
Array **createArraysFromCommandLine(int argc, char *argv[]);
Array **createArraysFromConsole(int arraysCount);

#endif