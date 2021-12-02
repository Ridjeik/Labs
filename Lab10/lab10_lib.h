#ifndef LAB10
#define LAB10

#define max(a, b) a > b ? a : b

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


#define MAX_NAME_LEN 20
#define MAX_SURNAME_LEN 20
#define MAX_COMMAND_LEN 20
#define MAX_ARGS_COUNT 20
#define MAX_DESCRIPTION_LEN 512
#define MAX_LISTNAME_LEN 20
#define MAX_TITLE_LEN 50
#define MAX_LINE_LEN 256

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

typedef struct ListItem{
    Book data;
    struct ListItem *next;
} ListItem;

typedef struct List{
    char name[MAX_LISTNAME_LEN];
    ListItem *head;
} List;

typedef struct CLArgs{
    int argc;
    char *argv[MAX_ARGS_COUNT];
} CLArgs;

typedef struct Command{
    char commandName[MAX_COMMAND_LEN];
    char commandDesc[MAX_DESCRIPTION_LEN];
    void (*commandAction)(const CLArgs *const args);
} Command;

typedef int (*BookComparer)(Book a, Book b);

CLArgs* parseCommandLine(char *str, char **command);
void executeLine(char *line);
void launchConsole();

#endif