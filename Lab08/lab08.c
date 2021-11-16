#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOK_COUNT 100
#define MAX_LINE_SIZE 256
#define FILE_PATH "books.txt"

#define REPEAT_CHAR(ch, i) \
    for(int z = 0; z < (i); z++){\
        printf("%c", ch);\
    }\

#define MAKE_LINE(plainCh, nodeCh, autS, titS, yearS, pageS, priceS)\
    printf("%c", nodeCh);\
    REPEAT_CHAR(plainCh, (autS));\
    printf("%c", nodeCh);\
    REPEAT_CHAR(plainCh, (titS));\
    printf("%c", nodeCh);\
    REPEAT_CHAR(plainCh, (yearS));\
    printf("%c", nodeCh);\
    REPEAT_CHAR(plainCh, (pageS));\
    printf("%c", nodeCh);\
    REPEAT_CHAR(plainCh, (priceS));\
    printf("%c\n", nodeCh);

#define MAX(a, b) a > b ? a : b

struct Book
{
    int pubYear;
    int pageCount;
    double price;
    struct Author
    {
        char name[20];
        char surname[20];
        char fullName[40];
    }   author;
    char title[50];
};

struct Book strToBook(char str[]){
    struct Book result;
    
    char *pPart = strtok(str, ",");
    sscanf(pPart, "%s %s", &result.author.name, &result.author.surname);
    strcpy(result.author.fullName, pPart);

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

int numLen(int num){
    int result = 0;
    while(num > 0){
        num /= 10; result++;
    }
    return result;
}

int longestAuthorFieldSize(struct Book books[], int size){
    int result = strlen(books[0].author.fullName);
    for(int i = 1; i < size; i++){
        int curr = strlen(books[i].author.fullName);
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

    MAKE_LINE('-','+', authorColumnWidth + 2, titleColumnWidth + 2, yearColumnWidth + 2, pageColumnWidth + 2, priceColumnWidth + 2);

    printf("| %-*s | %-*s | %-*s | %-*s | %-*s |\n", 
        authorColumnWidth, "Author",
        titleColumnWidth,"Title",
        yearColumnWidth, "Pub. year",
        pageColumnWidth, "Pages",
        priceColumnWidth, "Price");
    
    MAKE_LINE('-','+', authorColumnWidth + 2, titleColumnWidth + 2, yearColumnWidth + 2, pageColumnWidth + 2, priceColumnWidth + 2);

    for(int i = 0; i < size; i++){
        printf("| %-*s | %-*s | %-*d | %-*d | %-*.2lf |\n",
            authorColumnWidth, books[i].author.fullName,
            titleColumnWidth, books[i].title,
            yearColumnWidth, books[i].pubYear,
            pageColumnWidth, books[i].pageCount,
            priceColumnWidth, books[i].price
            );
    }

    MAKE_LINE('-','+', authorColumnWidth + 2, titleColumnWidth + 2, yearColumnWidth + 2, pageColumnWidth + 2, priceColumnWidth + 2);
    printf("\n");
}

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
}

void swap(struct Book *a, struct Book *b){
    struct Book tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortBooksBySurname(struct Book books[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 1; j < size - i; j++){
            if(strcmp(books[j].author.surname, books[j-1].author.surname) < 0) swap(&books[j], &books[j-1]);
        }
    }
}

int main(){
        
    struct Book books[MAX_BOOK_COUNT];
    char buffer[MAX_LINE_SIZE];
    int book_count = 0;

    FILE *fin = fopen(FILE_PATH, "r");
    
    while(fgets(buffer, 256, fin) != NULL){
        if(strlen(buffer) < 2) continue;
        struct Book book = strToBook(buffer);
        books[book_count] = book;
        book_count++;
    }
    
    formTable(books, book_count);
    printf("%lf", averagePrice(books, book_count));

    struct Book arr[MAX_BOOK_COUNT];
    int arr_size = 0;
    getBooksBelowAverage(books, book_count, arr, &arr_size);
    formTable(arr, arr_size);
    
    sortBooksBySurname(arr, arr_size);
    formTable(arr, arr_size);

}