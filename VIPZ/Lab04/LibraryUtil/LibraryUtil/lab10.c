#include "lab10_lib.h"

//Головна функція програми.
int main(int argc, char *argv[])
{
    cls();

    if (argc == 2)
    {
        executeFile(argv[1]);
    }

    launchConsole();
    return 0;
}