#include <stdio.h>
#include <math.h>

int main(){
    const int STEPS = 20;
    const double EPS = 1e-2;
    double x = 0, sum = 1, S = 1, res = 0, A = 0, B = 0;

    scanf("%lf %lf", &A, &B);
    if(fabs(A) > 1 || fabs(B) > 1 || B <= A){
        printf("Incorrect input.");
        return 0;
    }

    printf("X\t\tf(x)\t\t\tpow(1-x, 1/3)\t\tdifference\n");

    for(x = A; x < B; x += (B-A)/STEPS){
        sum = 1;
        S = 1;
        res = pow(1-x, 1.0/3);
        int i = 0;
        while(fabs(res - sum) > EPS){
            S *= (3.0*i - 1)/(3.0*i + 3) * x;
            sum += S;
            i++;
        }

        printf("% lf\t%.18lf\t%.18lf\t%.18lf\n", x, sum, res, fabs(res-sum));
    }
     


    return 0;
}