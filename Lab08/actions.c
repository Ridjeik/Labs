#include <stdio.h>
#include <string.h>
#include "lab08_lib.h"
#include "actions.h"


double averagePrice(struct Book books[], int size){
    double result = 0;
    for(int i = 0 ; i < size; i++){
        result += books[i].price;
    }
    result /= size;
    return result;
}

void getBooksBelowAverage(struct Book input[], int input_size, struct Book output[], int * output_size){
    int res_size = 0;
    double average = averagePrice(input, input_size);
    for(int i = 0; i < input_size; i++){
        if(input[i].price < average){
            output[res_size] = input[i];
            res_size++;
        }
    }
    *output_size = res_size;
    printf("Average price: %.2lf; There %s %d %s, which price less than average left.\n", average, *output_size > 1 ? "are" : "is", *output_size, *output_size > 1 ? "elements" : "element");
}

void swap(struct Book *a, struct Book *b){
    struct Book tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortBooksBySurname(struct Book input[], int input_size, struct Book output[], int * output_size){
    arrcpy(output, input, input_size);

    for(int i = 0; i < input_size; i++){
        for(int j = 1; j < input_size - i; j++){
            if(strcmp(output[j].author.surname, output[j-1].author.surname) < 0) swap(&output[j], &output[j-1]);
        }
    }

    *output_size = input_size;
    printf("Sorting books by authors' surnames.\n");
}