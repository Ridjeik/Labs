#ifndef LAB08
#define LAB08

#define MAX_NAME_LEN 20
#define MAX_SURNAME_LEN 20
#define MAX_FULLNAME_LEN ((MAX_NAME_LEN) + (MAX_SURNAME_LEN))
#define MAX_BOOK_COUNT 100
#define MAX_LINE_SIZE 256
#define DEFAULT_FILE_PATH "books.txt"
#define MAX_ERROR_LENGTH 50

struct Book
{
    char title[50];
    struct Author
    {
        char name[MAX_NAME_LEN];
        char surname[MAX_SURNAME_LEN];
    }   author;
    double price;
    int pubYear;
    int pageCount;
};

#pragma region Macros

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

void arrcpy(struct Book dest[], struct Book source[], int size);
int readBooksFromTextFile(char fileName[], struct Book output[], int* output_size);
int readBooksFromBinFile(char fileName[], struct Book output[], int* output_size);
void writeBooksToTextFile(char fileName[], struct Book input[], int input_size);
void writeBooksToBinFile(char fileName[], struct Book input[], int input_size);
struct Book strToBook(char str[]);
void formTable(struct Book books[], int size);
void performActions(struct Book input[], int input_size, struct Book output[], int * output_size, int printMiddleSteps, ...);

#pragma endregion

#endif