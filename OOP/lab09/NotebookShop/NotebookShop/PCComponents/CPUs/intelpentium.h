#ifndef INTELPENTIUM_H
#define INTELPENTIUM_H

#include "../processor.h"

class IntelPentium : public Processor
{
public:
    IntelPentium() = default;
    virtual ~IntelPentium() = default;

    // Hardware interface
public:
    std::string getInfoString() const override;
    double getPrice() const override;

    // Processor interface
public:
    double getCpuFrequency() const override;
};

#endif // INTELPENTIUM_H
