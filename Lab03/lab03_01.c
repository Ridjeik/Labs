#include <stdio.h>
#include <limits.h>

int main()
{
    const int N = 10;
    double vector[N], num = 0, negSum = 0;
    int minPos = 0, maxPos = 0;

    printf("Enter %i numbers: ", N);

    for(int i = 0; i < N; i++)
    {
        scanf("%lf", &num);

        if(num < 0){
            negSum += num;
        }
        
        vector[i] = num;

        minPos = num < vector[minPos] ? i : minPos;
        maxPos = num > vector[maxPos] ? i : maxPos; 
    }

    if(negSum != 0)
    {
        *(vector + maxPos) = *(vector + maxPos) / (-negSum);
    }

    if(minPos >= 1 && minPos <= N-2)
    {
        int temp = *(vector + minPos - 1); 
        *(vector + minPos - 1) = *(vector + minPos + 1);
        *(vector + minPos + 1) = temp;
    }


    printf("Result: ");
    for (int i = 0; i < N; i++)
    {
        printf("%lf ", vector[i]);
    }
    printf("\n");

    return 0;
}