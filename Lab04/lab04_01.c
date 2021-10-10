#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LIMIT 50
int main()
{
    char sentence[MAX_LIMIT], keyword[MAX_LIMIT];

    printf("Enter sentence: ");
    fgets(sentence, MAX_LIMIT, stdin); 
    sentence[strlen(sentence)-1] = '\0';
    
    char* delptr = strchr(sentence, '.');
    if(delptr) *delptr = '\0';

    printf("Enter keyword: ");
    fgets(keyword, MAX_LIMIT, stdin); 
    keyword[strlen(keyword)-1] = '\0';

    char key_chars[MAX_LIMIT] = { 0 };
    int key_point = 0;

    for(char* p = keyword; *p != '\0'; ++p){
        if(strchr(key_chars, tolower(*p)) == NULL){
            key_chars[key_point] = tolower(*p);
            ++key_point;
        }
    }


    char* word = strtok(sentence, " ,\n");

    int match = 1;
    int word_point = 0;
    while(word != NULL){

        char word_chars[MAX_LIMIT] = { 0 };
        word_point = 0;

        for(char* p = word; *p != '\0'; ++p){
            if(strchr(word_chars, tolower(*p)) == NULL){
                word_chars[word_point] = tolower(*p);
                ++word_point;
            }
        }

        if(strlen(word_chars) == strlen(key_chars)){
            match = 1;
            for(char *c = key_chars; *c != '\0'; c++){
                if(strchr(word_chars, *c) == NULL){
                    match = 0;
                    break;
                }
            }
            if(match){
                printf("Match! Word: %s", word);
                break;
            }
            
        }
        word = strtok(NULL, " ,\n");
    }
    if(!match){
        printf("No match");
    }
    
    return 0;

}