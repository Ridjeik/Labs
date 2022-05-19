#include "samsungram.h"

std::string SamsungRAM::getInfoString() const
{
    return "RAM: Samsung; Size: " + std::to_string(this->getRAMCount()) + "GB; \n";
}

double SamsungRAM::getPrice() const
{
    return 150;
}

double SamsungRAM::getRAMCount() const
{
    return 2;
}
