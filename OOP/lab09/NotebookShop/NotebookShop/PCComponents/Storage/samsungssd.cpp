#include "samsungssd.h"


std::string SamsungSSD::getInfoString() const
{
    return "Storage: Samsung SSD; Volume: " + std::to_string(this->getStoragevolume()) + "GB;\n";;
}

double SamsungSSD::getPrice() const
{
    return 650;
}

double SamsungSSD::getStoragevolume() const
{
    return 1024;
}
