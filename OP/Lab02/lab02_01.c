#include <stdio.h>
#include <math.h>

int main()
{
    long long int n;
    scanf("%lli", &n);

    if(n <= 0){
        printf("Incorrect input.");
        return 0;
    }

    long long int max = (int)sqrt(n);
    int found = 0;
    
    for (long long int i = 1; i < max; i++)
    {
        for(long long int j = 1; j <= i; j++)
        {
            for (long long int k = 1; k <= j; k++)
            {
                if(i*i + j*j + k*k == n)
                {
                    if(!found)
                    {
                        printf("Number can be represented by sum of 3 squares of natural numbers:\n");
                        found = 1;
                    }
                    printf("%lli^2 + %lli^2 + %lli^2 = %lli\n", i, j, k, n);
                }
                
            }
        }
    }

    if(!found){
        printf("Number cannot be represented by sum of 3 squares of natural numbers.\n");
    }


    return 0;
}
