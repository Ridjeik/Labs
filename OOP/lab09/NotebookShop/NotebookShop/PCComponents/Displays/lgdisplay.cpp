#include "lgdisplay.h"


std::string LGDisplay::getInfoString() const
{
    return "Display: LG; Diagonal: " + std::to_string(this->getSize()) + "inches;\n";
}

double LGDisplay::getPrice() const
{
    return 600;
}

double LGDisplay::getSize() const
{
    return 15.6;
}
