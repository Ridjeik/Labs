#include "asusmotherboard.h"


std::string AsusMotherboard::getInfoString() const
{
    return "Motherboard: Asus; Socket: " + this->getSocket() + ";\n";
}

double AsusMotherboard::getPrice() const
{
    return 200;
}

std::string AsusMotherboard::getSocket() const
{
    return "G2";
}
