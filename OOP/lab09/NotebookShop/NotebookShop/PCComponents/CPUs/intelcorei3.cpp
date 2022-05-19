#include "intelcorei3.h"

std::string IntelCoreI3::getInfoString() const
{
    return "CPU: Intel core i3; Frequency: " + std::to_string(this->getCpuFrequency()) + "Hz; \n";
}

double IntelCoreI3::getPrice() const
{
    return 350;
}

double IntelCoreI3::getCpuFrequency() const
{
    return 3.2;
}
