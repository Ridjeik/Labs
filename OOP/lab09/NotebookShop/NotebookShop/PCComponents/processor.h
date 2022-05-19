#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "hardware.h"

class Processor : public Hardware
{
public:
    virtual double getCpuFrequency() const = 0;

    virtual ~Processor() = default;
};

#endif // PROCESSOR_H
