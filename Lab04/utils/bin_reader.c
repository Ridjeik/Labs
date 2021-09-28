#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    double X;
    fread(&X, sizeof(double), 1, fopen(argv[1], "rb"));
    printf("%lf", X);
}