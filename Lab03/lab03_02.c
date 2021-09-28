#include <stdio.h>

#define LIMIT 100

int main()
{
    double A[LIMIT][LIMIT];

    int size;
    do{
        printf("Size pf matrix: ");
        scanf("%d", &size);
    }while(size <= 0);

    printf("Enter matrix %dx%d:\n", size, size);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            scanf("%lf", (*(A+i) + j));
        }
    }

    for(int i = 0; i < size; i++){
        int rowMinPos = 0, rowMaxPos = 0;
        for(int j = 1; j < size; j++){
            rowMinPos = A[i][j] < A[i][rowMinPos] ? j : rowMinPos;
            rowMaxPos = A[i][j] > A[i][rowMaxPos] ? j : rowMaxPos;
        }
        double diagElem = A[i][i];
        A[i][i] = A[i][rowMinPos];
        A[i][rowMaxPos] = diagElem;
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%lf ", *(*(A+i) + j));
        }
        printf("\n");
    }

    return 0;
}

// *(*(A+3) + 4)s