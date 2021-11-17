#ifndef LAB08
#define LAB08
#define MIDDLE_STEPS

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

#pragma region Macros

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

#pragma endregion

#pragma region Functions

void getBooksFromFile(char fileName[], struct Book output[], int* output_size);
struct Book strToBook(char str[]);
void formTable(struct Book books[], int size);
double averagePrice(struct Book books[], int size);
void getBooksBelowAverage(struct Book input[], int input_size, struct Book output[], int * output_size);
void sortBooksBySurname(struct Book input[], int input_size, struct Book output[], int * output_size);
void performActions(struct Book input[], int input_size, struct Book output[], int * output_size, void (*actions[])(struct Book[], int , struct Book[], int*), int actions_size);

#pragma endregion

#endif