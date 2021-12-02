#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "lab10_lib.h"

#pragma region Utils

int numLen(int num){
    int result = 0;
    while(num > 0){
        num /= 10; result++;
    }
    return result;
}

int getAuthorFullNameLen(const Book book){
    return strlen(book.author.name) + strlen(book.author.surname) + 1;
}

int longestAuthorFieldSize(const List *const books){
    if(!books) return 0;
    ListItem *curr = books->head;
    int result = 0;
    while(curr){
        int currLen = getAuthorFullNameLen(curr->data);
        result = currLen > result ? currLen : result;
        curr = curr->next;
    }
    return result;
}

int longestBookTitleSize(const List *const books){
    if(!books) return 0;
    ListItem *curr = books->head;
    int result = 0;
    while(curr){
        int currLen = strlen(curr->data.title);
        if(currLen > result) result = currLen;
        curr = curr->next;
    }
    return result;
}

void longestNumberFieldsSize(const List *const books, int * const yearSize, int * const pageSize, int * const priceSize){
    if(!books){
        *yearSize = 0;
        *pageSize = 0;
        *priceSize = 0;
        return;
    }

    int 
        maxYearLen = 0, 
        maxPageLen = 0,
        maxPriceLen = 0,
        yearLen = 0,
        pageLen = 0,
        priceLen = 0;

    ListItem *curr = books->head;

    while(curr){
        yearLen = numLen(curr->data.pubYear);
        pageLen = numLen(curr->data.pageCount);
        priceLen = numLen((int)(curr->data.price)) + 3;

        if(yearLen > maxYearLen) maxYearLen = yearLen;
        if(pageLen > maxPageLen) maxPageLen = pageLen;
        if(priceLen > maxPriceLen) maxPriceLen = priceLen;
        curr = curr->next;
    }

    *yearSize = maxYearLen;
    *pageSize = maxPageLen;
    *priceSize = maxPriceLen;
}

void getSizes(const List *const books, int *const authorColumnWidth, int *const titleColumnWidth, int *const yearColumnWidth, int *const pageColumnWidth, int *const priceColumnWidth){

    *authorColumnWidth = max(longestAuthorFieldSize(books), strlen("Author"));
    *titleColumnWidth = max(longestBookTitleSize(books), strlen("Title"));
    longestNumberFieldsSize(books, yearColumnWidth, pageColumnWidth, priceColumnWidth);
    *yearColumnWidth = max(*yearColumnWidth, strlen("Pub. year"));
    *pageColumnWidth = max(*pageColumnWidth, strlen("Pages"));
    *priceColumnWidth = max(*priceColumnWidth, strlen("Price"));
    
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *ltrim(char *s){
    while(isspace(*s)) s++;
    return s; 
}

char *trim(char *s){
    return ltrim(rtrim(s));
}

char *qtrim(char *s){
    char *last = s + strlen(s) - 1;
    if(*last == '"') *last = 0;
    return *s == '"' ? s + 1 : s;
}

void prompt(const char const *msg, char * const buffer){
    printf(msg);
    gets(buffer);
    fflush(stdin);
}

int fexists(const char *const fileName){
    FILE *f = fopen(fileName, "r");
    if(f){
        fclose(f);
        return 1;
    }
    return 0;
}

Book strToBook(char str[]){
    Book result;

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

#pragma endregion

#pragma region CommandsDeclarations

void exitProgram(const CLArgs *const args);
void clearConsole(const CLArgs *const args);
void getHelp(const CLArgs *const args);
void createList(const CLArgs *const args);
void getLists(const CLArgs *const args);
void addElement(const CLArgs *const args); //TODO: sort-in-time param
void switchList(const CLArgs *const args);
void formTable(const CLArgs *const args);
void loadFromFile(const CLArgs *const args);
void countList(const CLArgs *const args);
//TODO: delete
//TODO: save
//TODO: sort
//TODO: filter
//TODO: dumpall?
//TODO: restore?


#pragma endregion

#pragma region CommandsAndListsStuff

static int listCount = 0;
static List *lists = NULL;

static int currentListIndex = -1;
static List *currentList = NULL;

static Command commands[] = {
    
    {
        "exit",
        "Closes the console.\n\n"
        "Modifiers:\n\n"
        "\t-s, --success - to set exit code to SUCCESS(default).\n"
        "\t-f, --fail - to set exit code to FAILURE.\n\n",
        exitProgram
    },

    {
        "cls",
        "Clears the console.\n\n",
        clearConsole
    },

    {
        "help",
        "Prints an information about selected command.\n\n"
        "Syntax: help [<command>]\n\n"
        "\t<command> - command we need info about\n\n",
        getHelp
    },

    {
        "create",
        "Creates a new list with specified name.\n\n"
        "Syntax: create [<modifiers>] [<name>]\n\n"
        "\t<name> - name of the list that will be created.\n\n"
        "Modifiers:\n\n"
        "\t-s, --select - selects created list as current.\n\n",
        createList
    },

    {
        "lists",
        "Prints off all available lists.\n\n",
        getLists
    },

    {
        "append",
        "Adds element to the current list.\n\n",
        addElement
    },

    {
        "show",
        "Shows the current list in table view.\n\n",
        formTable
    },

    {
        "switch",
        "Switches the current list to another with specified name.\n\n"
        "Syntax: switch [<name>]\n\n"
        "\t<name> - name of the list to switch to.\n\n",
        switchList
    },

    {
        "load",
        "Loads elements from specified file to the current list.\n\n"
        "Syntax: load [<modifiers>] [<file>]\n\n"
        "\t<file> - name of the file to load data from.\n\n"
        "Modifiers:\n\n"
        "\t-t, --text - to specify that the file type is text(default).\n"
        "\t-b, --binaty - to specify that the file type is binary.\n\n",
        loadFromFile
    },

    {
        "count",
        "Counts the elements in the current list.\n\n",
        countList
    }
};

Command *findCommand(const char *const commandName){
    for(int i = 0; i < sizeof(commands)/sizeof(commands[0]); i++){
        if(strcmp(commands[i].commandName, commandName) == 0) return commands + i;
    }
    return NULL;
}

int findParam(const CLArgs *const args, const char *const param){
    if(!args) return -1;
    for(int i = 0; i < args->argc; i++){
        if(strcmp(args->argv[i], param) == 0) return i;
    }
    return -1;
}

void addElementToList(List *list, ListItem *listItem){
    ListItem *iter = list->head;
    
    if(!iter) list->head = listItem;
    else{
        while(iter->next != NULL) iter = iter->next;
        iter->next = listItem;
    }
}

int findList(const char *const listName){
    for(int i = 0; i < listCount; i++){
        if(strcmp((lists + i)->name, listName) == 0){
            return i;
        }
    }
    return -1;
}

#pragma endregion

#pragma region CommandsRealizations

void exitProgram(const CLArgs *const args){
    printf("Aborting a program..\n");

    if(!args || args->argc == 0 || findParam(args, "-s") != -1 || findParam(args, "--success") != -1) exit(EXIT_SUCCESS);
    else if(findParam(args, "-f") != -1 || findParam(args, "--fail") != -1) exit(EXIT_FAILURE);  
}

void clearConsole(const CLArgs *const args){
    system("cls");
}

void getHelp(const CLArgs *const args){
    if(!args || args->argc == 0){
        printf("There are %d commands available:\n\n", sizeof(commands) / sizeof(commands[0]));
        for(int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++){
            printf("\t%s\n", commands[i].commandName);
        }
        printf("\nTo get the description of the command use \"help <command>\".\n\n");
        return;
    }
    if(args->argc == 1){
        Command *command = findCommand(args->argv[0]);
        if(command){
            printf(command->commandDesc);
            printf("\n");
        }
        else{
            printf("Unknown command \"%s\"\n\n", args->argv[0]);
        }
    }
    else{
        printf("Only 1 parameter needed.\n\n");
    }
}

void createList(const CLArgs *const args){
    if(args && args->argc >= 3){
        printf("Too many parameters.\n\n");
        return;
    }
    List newList;
    newList.head = NULL;
    int selPos = findParam(args, "-s") == -1 ? findParam(args, "--select") : findParam(args, "-s");  
    int select = selPos != -1;
    if(!args || args->argc == 0 || (args->argc == 1 && select)){
        char buffer[MAX_LISTNAME_LEN];
        prompt("Enter list name: ", buffer);
        char *listName = trim(buffer);
        if(strlen(listName) > 0)
            strcpy(newList.name, listName);
        else{
            printf("List name must contain text characters!\n\n");
            return;
        }
    }
    else{
        strcpy(newList.name, selPos == 0 ? args->argv[1] : args->argv[0]);
    }
    
    if(findList(newList.name) != -1){
        printf("List with the name \"%s\" already exists.\n\n");
        return;
    }

    char choice[3];
    printf("Are you sure to create list with name \"%s\"?(Y|N) ", newList.name);
    gets(choice);
    fflush(stdin);
    if(tolower(*trim(choice)) == 'y'){
        listCount++;
        List *newListsArr = (List*)realloc(lists, sizeof(List) * listCount);
        if(!newListsArr){
            printf("Error creating a list.\n");
            return;
        }
        newListsArr[listCount-1] = newList;
        lists = newListsArr;
        printf("List \"%s\" successfully created.\n", newList.name);
        if(select || !currentList){
            printf("Switching to new list.\n");
            currentListIndex = listCount - 1;
        }
        currentList = lists + currentListIndex;
    }
    
    printf("\n");
}

void getLists(const CLArgs *const args){
    if(listCount == 0){
        printf("There are no available lists.\nCreate one by executing \"create\" command.\n\n");
        return;
    }
    printf("There are %d available lists: \n\n", listCount);
    for(int i = 0; i < listCount; i++){
        printf("\t%s\n", lists[i].name);
    }
    printf("\n");
}

void addElement(const CLArgs *const args){

    if(!currentList){
        printf("No list to add element to.\n\n");
        return;
    }

    if(args->argc > 0){
        printf("Unknown modifiers.\n\n");
        return;
    }

    ListItem *newLI = (ListItem*)malloc(sizeof(ListItem));
    if(!newLI){
        printf("Error creating list item.\n\n");
        return;
    }

    char authorsName[MAX_NAME_LEN];
    char authorsSurname[MAX_SURNAME_LEN];
    char title[MAX_TITLE_LEN];
    int pubYear;
    int pageCount;
    double price;

    printf("Enter author(name surname): ");
    scanf("%s %s", authorsName, authorsSurname);
    fflush(stdin);
    printf("Enter book's title: ");
    gets(title);
    printf("Enter publication year: ");
    scanf("%d", &pubYear);
    printf("Enter page count: ");
    scanf("%d", &pageCount);
    printf("Enter price: ");
    scanf("%lf", &price);

    Book newBook;
    strcpy(newBook.title, trim(title));
    strcpy(newBook.author.name, authorsName);
    strcpy(newBook.author.surname, authorsSurname);
    newBook.price = price;
    newBook.pageCount = pageCount;
    newBook.pubYear = pubYear;

    newLI->data = newBook;
    newLI->next = NULL;

    ListItem *iter = currentList->head;
    
    addElementToList(currentList, newLI);

    printf("Element successfuly added to list \"%s\"\n\n", currentList->name);
}

void formTable(const CLArgs *const args){

    if(!currentList){
        printf("There are no list to display. Create one by using \"create\" command.\n\n");
        return;
    }

    ListItem *curr = currentList->head;
    if(!curr){
        printf("No elements in the list \"%s\".\n\n", currentList->name);
        return;
    }

    int authorColumnWidth,
        titleColumnWidth,
        yearColumnWidth,
        pageColumnWidth,
        priceColumnWidth;
    
    getSizes(currentList, &authorColumnWidth, &titleColumnWidth,
             &yearColumnWidth, &pageColumnWidth, &priceColumnWidth);

    printf("\n");

    MAKE_LINE('=','+', authorColumnWidth + 2, titleColumnWidth + 2, yearColumnWidth + 2, pageColumnWidth + 2, priceColumnWidth + 2);

    printf("| %-*s | %-*s | %-*s | %-*s | %-*s |\n", 
        authorColumnWidth, "Author",
        titleColumnWidth,"Title",
        yearColumnWidth, "Pub. year",
        pageColumnWidth, "Pages",
        priceColumnWidth, "Price");
    
    MAKE_LINE('=','+', authorColumnWidth + 2, titleColumnWidth + 2, yearColumnWidth + 2, pageColumnWidth + 2, priceColumnWidth + 2);

    char fullName[MAX_NAME_LEN + MAX_SURNAME_LEN + 1];

    while(curr){
        sprintf(fullName, "%s %s", curr->data.author.name, curr->data.author.surname);
        printf("| %-*s | %-*s | %-*d | %-*d | %-*.2lf |\n",
            authorColumnWidth, fullName,
            titleColumnWidth, curr->data.title,
            yearColumnWidth, curr->data.pubYear,
            pageColumnWidth, curr->data.pageCount,
            priceColumnWidth, curr->data.price
            );

        curr = curr->next;
    }

    MAKE_LINE('=','+', authorColumnWidth + 2, titleColumnWidth + 2, yearColumnWidth + 2, pageColumnWidth + 2, priceColumnWidth + 2);
    printf("\n");
}

void switchList(const CLArgs *const args){
    if(args->argc >= 2){
        printf("Too many parameters.\n\n");
        return;
    }
    char listName[MAX_LISTNAME_LEN];
    if(!args || args->argc == 0){
        prompt("Enter list name to switch on: ", listName);
    }
    else if(args->argc == 1){
        strcpy(listName, args->argv[0]);
    }
    
    int listIndex = -1;

    if((listIndex = findList(listName)) != -1){

            printf("Switching to list \"%s\".\n\n", listName);
            currentListIndex = listIndex;
            currentList = lists + currentListIndex;
            return;
    }
    

    printf("No list with name \"%s\".\n\n", listName);
}

void loadFromFile(const CLArgs *const args){
    if(!currentList){
        printf("No list to load data to.\n\n");
        return;
    }
    char filename[MAX_LINE_LEN];
    int formatPointerPos = -1;
    int textFormat = 1;
    if(!args || args->argc == 0){
        prompt("Enter name of file data will be loaded from: ", filename);
    }
    else if(args->argc >= 3){
        printf("Too many parameters.\n\n");
        return;
    }
    else if(args->argc == 1){
        if( ((formatPointerPos = findParam(args, "-t")) != -1) || ((formatPointerPos = findParam(args, "--text")) != -1) ){
            textFormat = 1;
            prompt("Enter name of file data will be loaded from: ", filename);
        }
        else if( ((formatPointerPos = findParam(args, "-b")) != -1) || ((formatPointerPos = findParam(args, "--binary")) != -1) ){
            textFormat = 0;
            prompt("Enter name of file data will be loaded from: ", filename);
        }
        else{
            strcpy(filename, args->argv[0]);
        }
        
    }
    else{
        
        if( ((formatPointerPos = findParam(args, "-t")) != -1) || ((formatPointerPos = findParam(args, "--text")) != -1) ){
            textFormat = 1;
        }
        else if( ((formatPointerPos = findParam(args, "-b")) != -1) || ((formatPointerPos = findParam(args, "--binary")) != -1) ){
            textFormat = 0;
        }
        else{
            printf("Unknown parameter.\n\n");
            return;
        }

        strcpy(filename, args->argv[formatPointerPos == 0 ? 1 : 0]);
    }
    
    if(fexists(filename)){
        
        FILE *fin = NULL;
        Book data;
        ListItem *newLI = NULL;
        int elemCount = 0;
        if(textFormat){
            fin = fopen(filename, "r");
            char buffer[MAX_LINE_LEN];
            while(fgets(buffer, MAX_LINE_LEN, fin) != NULL){
                if(strlen(buffer) <= 5) continue;
                data = strToBook(buffer);
                newLI = (ListItem*)malloc(sizeof(ListItem));
                newLI->data = data;
                newLI->next = NULL;
                addElementToList(currentList, newLI);
                elemCount++;
            }
        }
        else{
            FILE *fin = fopen(filename, "rb");

            while(!feof(fin)){
                fread(&data, sizeof(Book), 1, fin);
                if(!feof(fin)){
                    newLI = (ListItem*)malloc(sizeof(ListItem));
                    newLI->data = data;
                    newLI->next = NULL;
                    addElementToList(currentList, newLI);
                    elemCount++;
                }
            
            }
        }

        if(elemCount){
            printf("%d elements was successfully read from file \"%s\".\n\n", elemCount, filename);
        }
        else{
            printf("File was opened, but there are no elements to read.\n\n");
        }
        

        if(fin) fclose(fin);
    }
    else{
        printf("File \"%s\" not exists.\n\n", filename);
    }

}

void countList(const CLArgs *const args){
    if(!currentList){
        printf("There are no list. Create one by using \"create\" command.\n\n");
        return;
    }
    int res = 0;
    for(ListItem *iter = currentList->head; iter != NULL; iter = iter->next) res++;
    if(res == 0) printf("There are no elements in list.\n\n");
    else printf("There are %d elements in list.\n\n", res);
}

#pragma endregion

#pragma region Console

CLArgs* parseCommandLine(char *str, char **command){
    
    CLArgs *result = (CLArgs*)malloc(sizeof(CLArgs));
    result->argc = 0;
    
    str = trim(str);

    char *commandArgSepPos = strchr(str, ' ');

    *command = str;
    //if no args(no space after command)
    if(!commandArgSepPos){
        return result;
    }

    *commandArgSepPos = 0;


    int inQuote = 0;
    char *lexemStart = ltrim(commandArgSepPos + 1);
    #ifdef DEBUG
    printf("Args: %s\n", lexemStart);
    #endif
    char *curr = lexemStart;
    while( *curr != 0 ){
        
        if(!inQuote && *curr == '"' && strchr(curr+1, '"')){
            inQuote = 1;
        }
        else if(*curr == '"' && inQuote){
            inQuote = 0;
        } 

        #ifdef DEBUG
        printf("Looking at char '%c' - inQ: %d\n", *curr, inQuote);
        #endif

        if(!inQuote && isspace(*curr)){
            *curr = 0;
            result->argv[result->argc++] = qtrim(lexemStart);

            #ifdef DEBUG
            printf("Found %s\n", result->argv[result->argc - 1]);
            #endif

            curr = ltrim(curr + 1);
            lexemStart = curr; 
        }        
        else{
            curr++;
            if(*curr == 0){
                result->argv[result->argc++] = lexemStart;

                #ifdef DEBUG
                printf("Found %s\n", result->argv[result->argc - 1]);
                #endif
            }
        }
    }
    
    return result;
}

void executeLine(char *line){
    char *commandName;
    CLArgs *args = parseCommandLine(line, &commandName);

    Command *command;

    if(command = findCommand(commandName)){
        command->commandAction(args);
    }
    else{
        printf("Unknown command \"%s\"\nType \"help\" to get list of all available commands.\n\n", commandName);
    }
}

void launchConsole(){
    clearConsole(NULL);
    char buffer[256];
    while(1){
        char consoleText[MAX_LISTNAME_LEN + 2];
        sprintf(consoleText, "%s> ", currentList ? currentList->name : "(no lists)");
        prompt(consoleText, buffer);

        executeLine(buffer);
    }
}

#pragma endregion

int main(){
    launchConsole();
    return 0;
}