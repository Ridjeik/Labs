#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lab08_lib.h"

#pragma region Utils
void arrcpy(struct Book dest[], struct Book source[], int size){
    for(int i = 0; i < size; i++){
        dest[i] = source[i];
    }
}

int numLen(int num){
    int result = 0;
    while(num > 0){
        num /= 10; result++;
    }
    return result;
}
#pragma endregion

#pragma region TablePrint
int getAuthorFullNameLen(struct Book book){
    return strlen(book.author.name) + strlen(book.author.surname) + 1;
}

int longestAuthorFieldSize(struct Book books[], int size){
    int result = getAuthorFullNameLen(books[0]);
    for(int i = 1; i < size; i++){
        int curr = getAuthorFullNameLen(books[i]);
        if(curr > result) result = curr;
    }
    return result;
}

int longestBookTitleSize(struct Book books[], int size){
    int result = strlen(books[0].title);
    for(int i = 1; i < size; i++){
        int curr = strlen(books[i].title);
        if(curr > result) result = curr;
    }
    return result;
}

void longestNumberFieldsSize(struct Book books[], int size, int * yearSize, int * pageSize, int * priceSize){
    int 
        maxYearLen = 0, 
        maxPageLen = 0,
        maxPriceLen = 0,
        yearLen = 0,
        pageLen = 0,
        priceLen = 0;

    for(int i = 0; i < size; i++){
        yearLen = numLen(books[i].pubYear);
        pageLen = numLen(books[i].pageCount);
        priceLen = numLen((int)books[i].price) + 3;

        if(yearLen > maxYearLen) maxYearLen = yearLen;
        if(pageLen > maxPageLen) maxPageLen = pageLen;
        if(priceLen > maxPriceLen) maxPriceLen = priceLen;
    }

    *yearSize = maxYearLen;
    *pageSize = maxPageLen;
    *priceSize = maxPriceLen;
}

void formTable(struct Book books[], int size){
    int authorColumnWidth = longestAuthorFieldSize(books, size);
    int titleColumnWidth = longestBookTitleSize(books, size);
    int yearColumnWidth = 0, pageColumnWidth = 0, priceColumnWidth = 0;
    longestNumberFieldsSize(books, size, &yearColumnWidth, &pageColumnWidth, &priceColumnWidth);

    authorColumnWidth = MAX(authorColumnWidth, strlen("Author"));
    titleColumnWidth = MAX(titleColumnWidth, strlen("Title"));
    yearColumnWidth = MAX(yearColumnWidth, strlen("Pub. year"));
    pageColumnWidth = MAX(pageColumnWidth, strlen("Pages"));
    priceColumnWidth = MAX(priceColumnWidth, strlen("Price"));

    printf("\n");

    MAKE_LINE('=','+', authorColumnWidth + 2, titleColumnWidth + 2, yearColumnWidth + 2, pageColumnWidth + 2, priceColumnWidth + 2);

    printf("| %-*s | %-*s | %-*s | %-*s | %-*s |\n", 
        authorColumnWidth, "Author",
        titleColumnWidth,"Title",
        yearColumnWidth, "Pub. year",
        pageColumnWidth, "Pages",
        priceColumnWidth, "Price");
    
    MAKE_LINE('=','+', authorColumnWidth + 2, titleColumnWidth + 2, yearColumnWidth + 2, pageColumnWidth + 2, priceColumnWidth + 2);

    char fullName[MAX_FULLNAME_LEN];

    for(int i = 0; i < size; i++){
        sprintf(fullName, "%s %s", books[i].author.name, books[i].author.surname);
        printf("| %-*s | %-*s | %-*d | %-*d | %-*.2lf |\n",
            authorColumnWidth, fullName,
            titleColumnWidth, books[i].title,
            yearColumnWidth, books[i].pubYear,
            pageColumnWidth, books[i].pageCount,
            priceColumnWidth, books[i].price
            );
    }

    MAKE_LINE('=','+', authorColumnWidth + 2, titleColumnWidth + 2, yearColumnWidth + 2, pageColumnWidth + 2, priceColumnWidth + 2);
    printf("\n");
}

#pragma endregion

#pragma region FileSystemWork

struct Book strToBook(char str[]){
    struct Book result;

    char *pPart = strtok(str, ",");
    sscanf(pPart, "%s %s", &result.author.name, &result.author.surname);

    pPart = strtok(NULL, ",");
    strcpy(result.title, pPart);

    pPart = strtok(NULL, ",");
    result.pubYear = atoi(pPart);

    pPart = strtok(NULL, ",");
    result.pageCount = atoi(pPart);

    pPart = strtok(NULL, ",");
    result.price = strtod(pPart, NULL);

    return result;
}

int readBooksFromTextFile(char fileName[], struct Book output[], int* output_size){
    char buffer[MAX_LINE_SIZE];

    FILE *fin = fopen(fileName, "r");

    if(fin == NULL) return -1;

    while(fgets(buffer, MAX_LINE_SIZE, fin) != NULL){
        if(strlen(buffer) <= 2) continue;
        output[(*output_size)++] = strToBook(buffer);
    }

    fclose(fin);

    return 0;
}

int readBooksFromBinFile(char fileName[], struct Book output[], int* output_size){
    
    FILE *fin = fopen(fileName, "rb");
    
    if(fin == NULL) return -1;
    
    struct Book temp;

    while(!feof(fin)){
        fread(&temp, sizeof(struct Book), 1, fin);
        if(!feof(fin)){
            output[*output_size] = temp;
            (*output_size)++;
        }
    }

    fclose(fin);

    return 0;
}

void writeBooksToBinFile(char fileName[], struct Book input[], int input_size){
    FILE *fout = fopen(fileName, "wb");

    fwrite(input, sizeof(struct Book), input_size, fout);

    fclose(fout);
}

#pragma endregion

void performActions(struct Book input[], int input_size, struct Book output[], int * output_size, int printMiddleSteps, ...){

    va_list params;
    va_start(params, printMiddleSteps);

    arrcpy(output, input, input_size);
    *output_size = input_size;

    struct Book tmp[MAX_BOOK_COUNT];
    int tmp_size;

    void (*action)(struct Book[], int , struct Book[], int *);
    int first_action = 1;

    while(action = va_arg(params, void (*)(struct Book[], int , struct Book[], int *))){
        if(printMiddleSteps && !first_action){
            formTable(output, *output_size);
        }
        action(output, *output_size, tmp, &tmp_size);
        arrcpy(output, tmp, tmp_size);
        *output_size = tmp_size;
        tmp_size = 0;
        first_action = 0;
    }

    va_end(params);
}