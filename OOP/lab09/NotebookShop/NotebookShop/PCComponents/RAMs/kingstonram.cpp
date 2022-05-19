#include "kingstonram.h"

std::string KingstonRAM::getInfoString() const
{
    return "RAM: Kingston; Size: " + std::to_string(this->getRAMCount()) + "GB;\n";
}

double KingstonRAM::getPrice() const
{
    return 300;
}

double KingstonRAM::getRAMCount() const
{
    return 4;
}
