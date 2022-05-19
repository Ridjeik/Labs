#include "hyperxram.h"

std::string HyperXRAM::getInfoString() const
{
    return "RAM: HyperX; Size: " + std::to_string(this->getRAMCount()) + "GB;\n";
}

double HyperXRAM::getPrice() const
{
    return 500;
}

double HyperXRAM::getRAMCount() const
{
    return 8;
}
