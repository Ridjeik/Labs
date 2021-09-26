#include <stdio.h>

int main()
{
    const int N = 5;

    double A[N][N];

    

    for(int i = 0; i < N*N; i++){
        scanf("%lf", (*A + i));    
    }

    for(int i = 0; i < N; i++){
        int rowMinPos = 0, rowMaxPos = 0;
        for(int j = 1; j < N; j++){
            rowMinPos = A[i][j] < A[i][rowMinPos] ? j : rowMinPos;
            rowMaxPos = A[i][j] > A[i][rowMaxPos] ? j : rowMaxPos;
        }
        double diagElem = A[i][i];
        A[i][i] = A[i][rowMinPos];
        A[i][rowMaxPos] = diagElem;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%lf ", *(*(A+i) + j));
        }
        printf("\n");
    }

    return 0;
}