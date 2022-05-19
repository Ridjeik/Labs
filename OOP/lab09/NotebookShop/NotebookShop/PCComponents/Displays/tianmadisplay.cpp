#include "tianmadisplay.h"

std::string TianmaDisplay::getInfoString() const
{
    return "Display: Tianma; Diagonal: " + std::to_string(this->getSize()) + "inches;\n";
}

double TianmaDisplay::getPrice() const
{
    return 350;
}

double TianmaDisplay::getSize() const
{
    return 13.1;
}
