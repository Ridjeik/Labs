#include "intelpentium.h"

std::string IntelPentium::getInfoString() const
{
    return "CPU: Intel Pentium; Frequency: " + std::to_string(this->getCpuFrequency()) + "Hz;\n";
}

double IntelPentium::getPrice() const
{
    return 200;
}

double IntelPentium::getCpuFrequency() const
{
    return 2.4;
}

