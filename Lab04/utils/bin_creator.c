#include <stdio.h>

int main(int argc, char const *argv[])
{

    double X, Y, Z;
    
    sscanf(argv[1], "%lf", &X);
    sscanf(argv[2], "%lf", &Y);
    sscanf(argv[3], "%lf", &Z);
    
    FILE* output = fopen(argv[4], "wb");

    fwrite(&X, sizeof (double), 1, output);
    fwrite(&Y, sizeof (double), 1, output);
    fwrite(&Z, sizeof (double), 1, output);
}
