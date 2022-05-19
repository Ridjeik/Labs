#include "intelmotherboard.h"

std::string IntelMotherboard::getInfoString() const
{
    return "Motherboard: Intel; Socket: " + this->getSocket() + ";\n";
}

double IntelMotherboard::getPrice() const
{
    return 325;
}

std::string IntelMotherboard::getSocket() const
{
    return "LGA 1356";
}

