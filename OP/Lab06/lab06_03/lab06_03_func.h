#ifndef LAB06_03
#define LAB06_03

#define POD(num, res) \
    res = 1;\
    while(num > 0){\
        res *= num % 10; \
        num /= 10; \
    } \

int isAnswerExist(int num);

#endif