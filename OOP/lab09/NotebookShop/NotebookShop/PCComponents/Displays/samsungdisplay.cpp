#include "samsungdisplay.h"

std::string SamsungDisplay::getInfoString() const
{
    return "Display: Samsung; Diagonal: " + std::to_string(this->getSize()) + "inches;\n";
}

double SamsungDisplay::getPrice() const
{
    return 750;
}

double SamsungDisplay::getSize() const
{
    return 17.8;
}
