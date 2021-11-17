#include "lab08_lib.h"

void getNewBooks(struct Book input[], int input_size, struct Book output[], int *output_size){
    for(int i = 0; i < input_size; i++){
        if(input[i].pubYear >= 1970){
            output[*output_size] = input[i];
            (*output_size)++;
        }
    }
    printf("Getting new books(>= 1970 year), only %d books left", *output_size);
}

int main(){
    struct Book books[MAX_BOOK_COUNT];
    int book_count;

    getBooksFromFile(FILE_PATH, books, &book_count);    

    struct Book result[MAX_BOOK_COUNT];
    int result_size = 0;
    
    void (*actions[])(struct Book[], int , struct Book[], int*) = {getBooksBelowAverage, sortBooksBySurname, getNewBooks};
    performActions(books, book_count, result, &result_size, actions, sizeof(actions)/sizeof(actions[0]));

    formTable(result, result_size);
}