#include <stdio.h>
#include <string.h>
#include "lab08_lib.h"
#include "actions.h"

int main(int argc, char *argv[]){

    char *filePath = DEFAULT_FILE_PATH;
    int printMiddleSteps = 0, textInput = 1;

    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-m") == 0) printMiddleSteps = 1;
        else if((strcmp(argv[i], "-f") == 0  || strcmp(argv[i], "-ft") == 0) && i + 1 < argc){
            filePath = argv[i + 1];
            textInput = 1;
        } 
        else if(strcmp(argv[i], "-fb") == 0 && i + 1 < argc){
            filePath = argv[i + 1];
            textInput = 0;
        }
    }

    struct Book books[MAX_BOOK_COUNT];
    int book_count;

    if(textInput && readBooksFromTextFile(filePath, books, &book_count) == -1){
        printf("\nError accessing the text file \"%s\".", filePath);
        return -1;
    } 
    else if(!textInput && readBooksFromBinFile(filePath, books, &book_count) == -1){
        printf("\nError accessing the binary file \"%s\".", filePath);
        return -1;
    }

    printf("\nInput:");
    formTable(books, book_count);   

    struct Book result[MAX_BOOK_COUNT];
    int result_size = 0;
    performActions(books, book_count, result, &result_size, printMiddleSteps, getBooksBelowAverage, sortBooksBySurname, NULL);

    printf("\nOutput:");
    formTable(result, result_size);
}