#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 50
#define LOG_FILE "log.txt"

int main(){

    time_t curr_time;
    FILE *logFile = fopen(LOG_FILE, "a");
    char *errorMessage = "";


    time(&curr_time);
    char* time_str = ctime(&curr_time);
    *(strchr(time_str, '\n')) = '\0';
    fprintf(logFile, "[%s] Program started.\n", time_str);


    double X, Y, Z;
    char inputFileName[MAX_FILE_NAME_LENGTH];


    printf("Input file: ");
    scanf("%s", inputFileName);
    getchar();

    FILE *input = fopen(inputFileName, "rb");

    if(input == NULL){
        errorMessage = "The input file doesn't exist.";
        printf("%s\n",errorMessage);
        time(&curr_time);
        time_str = ctime(&curr_time);
        *(strchr(time_str, '\n')) = '\0';
        fprintf(logFile, "[%s] An error ocurred: %s. Aborting program...\n", time_str, errorMessage);
        return 0;
    }

    time(&curr_time);
    time_str = ctime(&curr_time);
    *(strchr(time_str, '\n')) = '\0';

    fprintf(logFile, "[%s] Parameters file \"%s\" opened.\n", time_str, inputFileName);

    fread(&X, sizeof(double), 1, input);
    fread(&Y, sizeof(double), 1, input);
    fread(&Z, sizeof(double), 1, input);

    fclose(input);

    time(&curr_time);
    time_str = ctime(&curr_time);
    *(strchr(time_str, '\n')) = '\0';

    fprintf(logFile, "[%s] Got values of variables: X = %lf; Y = %lf; Z = %lf;\n", time_str, X, Y, Z);

    if(fabs(Z) > 1){
        errorMessage = "Incorrect values in input file!";
        printf("%s\n",errorMessage);
        time(&curr_time);
        time_str = ctime(&curr_time);
        *(strchr(time_str, '\n')) = '\0';
        fprintf(logFile, "[%s] An error ocurred: %s. Aborting program...\n", time_str, errorMessage);
        fclose(logFile);
        return 0;
    }

    double b = pow(asin(Z), 2) + fabs(X + Y);

    time(&curr_time);
    time_str = ctime(&curr_time);
    *(strchr(time_str, '\n')) = '\0';
    fprintf(logFile, "[%s] Expression calculated: b = %lf;\n", time_str, b);
    
    char outputFileName[MAX_FILE_NAME_LENGTH];

    printf("Output file: ");
    scanf("%s", outputFileName);
    getchar();

    printf("Output format (t|b): ");
    char choice;
    scanf("%c", &choice);

    if(choice == 't' || choice == 'T'){
        FILE *output = fopen(outputFileName, "w");
        time(&curr_time);
        time_str = ctime(&curr_time);
        *(strchr(time_str, '\n')) = '\0';
        fprintf(logFile, "[%s] Text output file \"%s\" opened.\n", time_str, outputFileName);
        fprintf(output, "%lf", b);
        fclose(output);
        time(&curr_time);
        time_str = ctime(&curr_time);
        *(strchr(time_str, '\n')) = '\0';
        fprintf(logFile, "[%s] Text output file \"%s\" saved.\n", time_str, outputFileName);
    }
    else if(choice == 'b' || choice == 'B'){
        FILE *output = fopen(outputFileName, "wb");
        time(&curr_time);
        time_str = ctime(&curr_time);
        *(strchr(time_str, '\n')) = '\0';
        fprintf(logFile, "[%s] Binary output file \"%s\" opened.\n", time_str, outputFileName);
        fwrite(&b, sizeof(double), 1, output);
        fclose(output);
        time(&curr_time);
        time_str = ctime(&curr_time);
        *(strchr(time_str, '\n')) = '\0';
        fprintf(logFile, "[%s] binary output file \"%s\" saved.\n", time_str, outputFileName);
    }

    time(&curr_time);
    time_str = ctime(&curr_time);
    *(strchr(time_str, '\n')) = '\0';
    fprintf(logFile, "[%s] Program finished.\n", time_str);
    fclose(logFile);

    return 0;
}