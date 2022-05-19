#ifndef KINGSTONRAM_H
#define KINGSTONRAM_H

#include "../ram.h"

class KingstonRAM : public RAM
{
public:
    KingstonRAM() = default;
    virtual ~KingstonRAM() = default;
    // Hardware interface
public:
    std::string getInfoString() const override;
    double getPrice() const override;

    // RAM interface
public:
    double getRAMCount() const override;
};

#endif // KINGSTONRAM_H
