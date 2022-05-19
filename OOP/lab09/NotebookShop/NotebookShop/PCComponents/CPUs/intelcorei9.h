#ifndef INTELCOREI9_H
#define INTELCOREI9_H

#include "../processor.h"

class IntelCoreI9 : public Processor
{
public:
    IntelCoreI9() = default;
    virtual ~IntelCoreI9() = default;

    // Hardware interface
public:
    std::string getInfoString() const override;
    double getPrice() const override;

    // Processor interface
public:
    double getCpuFrequency() const override;
};

#endif // INTELCOREI9_H
