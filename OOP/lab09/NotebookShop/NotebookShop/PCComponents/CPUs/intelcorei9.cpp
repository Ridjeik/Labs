#include "intelcorei9.h"

std::string IntelCoreI9::getInfoString() const
{
    return "CPU: Intel core i9; Frequency: " + std::to_string(this->getCpuFrequency()) + "Hz;\n";
}

double IntelCoreI9::getPrice() const
{
    return 500;
}

double IntelCoreI9::getCpuFrequency() const
{
    return 4.4;
}
