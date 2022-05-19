#ifndef RAM_H
#define RAM_H

#include "hardware.h"

class RAM : public Hardware
{
public:
    virtual double getRAMCount() const = 0;

    virtual ~RAM() = default;
};

#endif // RAM_H
