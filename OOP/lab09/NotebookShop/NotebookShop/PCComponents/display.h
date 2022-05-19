#ifndef DISPLAY_H
#define DISPLAY_H

#include "hardware.h"

class Display : public Hardware
{
public:
    virtual double getSize() const = 0;

    virtual ~Display() = default;
};

#endif // DISPLAY_H
