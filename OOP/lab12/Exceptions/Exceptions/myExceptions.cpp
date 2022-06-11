#include "myExceptions.h"

const char *TooBigException::what() const noexcept
{
    return "Entered number was too big";
}

const char *TooSmallException::what() const noexcept
{
    return "Entered number was too small";
}

const char *OverflowException::what() const noexcept
{
    return "Integer overflow occured";
}
const char *InvalidFormatException::what() const noexcept
{
    return "Invalid format of entered number!";
}

const char *DivideByZeroException::what() const noexcept
{
    return "Tried to divide by zero";
}
