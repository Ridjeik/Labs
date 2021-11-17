#include "lab08_lib.h"
#include <stdio.h>

// void getNewBooks(struct Book input[], int input_size, struct Book output[], int *output_size){
//     for(int i = 0; i < input_size; i++){
//         if(input[i].pubYear >= 1970){
//             output[*output_size] = input[i];
//             (*output_size)++;
//         }
//     }
//     printf("Getting new books(>= 1970 year), only %d books left", *output_size);
// }

int main(){
    struct Book books[MAX_BOOK_COUNT];
    int book_count;

    getBooksFromFile(FILE_PATH, books, &book_count);    

    struct Book result[MAX_BOOK_COUNT];
    int result_size = 0;

    performActions(books, book_count, result, &result_size, getBooksBelowAverage, sortBooksBySurname, NULL);

    formTable(result, result_size);
}