#include "seagatehdd.h"

std::string SeagateHDD::getInfoString() const
{
    return "Storage: Seagate HDD; Volume: " + std::to_string(this->getStoragevolume()) + "GB;\n";
}

double SeagateHDD::getPrice() const
{
    return 275;
}

double SeagateHDD::getStoragevolume() const
{
    return 512;
}

