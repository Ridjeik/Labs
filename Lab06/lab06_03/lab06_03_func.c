#include "lab06_03_func.h"

int isAnswerExist(int num){
    for(int i = 2; i <= 9; i++){
        while(num % i == 0) num /= i;
    }
    if(num > 1) return 0;
    else return 1;
}