#include <math.h>
#include "lab06_01_func.h"

double dot(double vec1[], double vec2[], int size){
    double res = 0;
    for(int i = 0; i < size; i++){
        
        res += vec1[i] * vec2[i];
    }
    return res;
}

int isOrthogonal(double Matrix[][MAX_SIZE], int size){
    for(int i = 0; i < size - 1; i++){
       for(int j = i; j < size; j++){
           if(i != j && fabs(dot(Matrix[i], Matrix[j], size)) > 1e-4) return 0;
           if(i == j && fabs(dot(Matrix[i], Matrix[j], size)) < 1e-4 ) return 0;
       } 
    }
    return 1;
}
