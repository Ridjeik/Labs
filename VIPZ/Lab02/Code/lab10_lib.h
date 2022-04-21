#ifndef LAB10
#define LAB10

#include <stdarg.h>
#include <stddef.h>

//Макрос для знеаходження максимуму.
#define max(a, b) a > b ? a : b

//Макрос для створення стрічок з певною к-тю однакових симовлів.
#define REPEAT_CHAR(ch, i) \
    for(int z = 0; z < (i); z++){\
        printf("%c", ch);\
    }\

//Макрос, що друкує стрічку за певним правилом.
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


#define MAX_NAME_LEN 20
#define MAX_SURNAME_LEN 20
#define MAX_COMMAND_LEN 20
#define MAX_ARGS_COUNT 20
#define MAX_DESCRIPTION_LEN 1024
#define MAX_LISTNAME_LEN 20
#define MAX_TITLE_LEN 50
#define MAX_LINE_LEN 256

//Структура, що представляє дані про книгу
typedef struct Book
{
    char title[MAX_TITLE_LEN];
    struct Author
    {
        char name[MAX_NAME_LEN];
        char surname[MAX_SURNAME_LEN];
    }   author;
    double price;
    int pubYear;
    int pageCount;
} Book;

//Структура, що представляє дані про елемент списку.
typedef struct ListItem{
    Book data;
    struct ListItem *next;
} ListItem;

//Структура, що представляє дані про список в цілому
typedef struct List{
    char name[MAX_LISTNAME_LEN];
    ListItem *head;
} List;

//Структура, що представляє дані про аргументи команди: їх к-ть та значення.
typedef struct CLArgs{
    int argc;
    char *argv[MAX_ARGS_COUNT];
} CLArgs;

//Структура, що представляє дані про команду.
typedef struct Command{
    char commandName[MAX_COMMAND_LEN];
    char commandDesc[MAX_DESCRIPTION_LEN];
    void (*commandAction)(const CLArgs *const args);
} Command;

typedef int (*BookComparer)(Book a, Book b);
typedef int (*BookPredicate)(Book a, va_list va);
typedef double (*BookSelector)(Book a, va_list va);

CLArgs* parseCommandLine(char *str, char **command);
void executeLine(char *line);
void executeFile(char *fileName);
void launchConsole();
void cls();

#endif