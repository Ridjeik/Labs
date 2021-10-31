#ifndef LAB06_03
#define LAB06_03

#define POD(num, res) \
    res = 1;\
    int t_temp = num; \
    while(num > 0){\
        res *= num % 10; \
        num /= 10; \
    } \
    num = t_temp; 

int isAnswerExist(int num);

#endif