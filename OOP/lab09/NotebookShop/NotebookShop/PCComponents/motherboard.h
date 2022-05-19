#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H

#include "hardware.h"

class Motherboard : public Hardware
{
public:
    virtual std::string getSocket() const = 0;

    virtual ~Motherboard() = default;
};

#endif // MOTHERBOARD_H
