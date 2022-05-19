#ifndef HYPERXRAM_H
#define HYPERXRAM_H

#include "../ram.h"

class HyperXRAM : public RAM
{
public:
    HyperXRAM() = default;
    virtual ~HyperXRAM() = default;
    // Hardware interface
public:
    std::string getInfoString() const override;
    double getPrice() const override;

    // RAM interface
public:
    double getRAMCount() const override;
};

#endif // HYPERXRAM_H
