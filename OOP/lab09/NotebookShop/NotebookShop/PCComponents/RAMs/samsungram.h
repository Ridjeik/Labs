#ifndef SAMSUNGRAM_H
#define SAMSUNGRAM_H

#include "../ram.h"

class SamsungRAM : public RAM
{
public:
    SamsungRAM() = default;
    virtual ~SamsungRAM() = default;

    // Hardware interface
public:
    std::string getInfoString() const override;
    double getPrice() const override;

    // RAM interface
public:
    double getRAMCount() const override;
};

#endif // SAMSUNGRAM_H
