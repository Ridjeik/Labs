#include <stdio.h>
#include <limits.h>

#define LIMIT 1000

int main()
{
    double vector[LIMIT], num = 0, negSum = 0;
    int minPos = 0, maxPos = 0, number = 0;
    
    do{
        printf("How many numbers should be in vector?");
        scanf("%i", &number);
    }while(number <= 0);

    printf("Enter %i numbers: ", number);

    for(int i = 0; i < number; i++)
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

    if(minPos >= 1 && minPos <= number-2)
    {
        int temp = *(vector + minPos - 1); 
        *(vector + minPos - 1) = *(vector + minPos + 1);
        *(vector + minPos + 1) = temp;
    }


    printf("Result: ");
    for (int i = 0; i < number; i++)
    {
        printf("%.2lf ", vector[i]);
    }
    printf("\n");

    return 0;
}