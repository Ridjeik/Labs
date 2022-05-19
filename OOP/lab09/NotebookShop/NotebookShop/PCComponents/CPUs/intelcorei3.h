#ifndef INTELCOREI3_H
#define INTELCOREI3_H

#include "../processor.h"

class IntelCoreI3 : public Processor
{
public:
    IntelCoreI3() = default;
    virtual ~IntelCoreI3() = default;

    // Hardware interface
public:
    std::string getInfoString() const override;
    double getPrice() const override;

    // Processor interface
public:
    double getCpuFrequency() const override;
};

#endif // INTELCOREI3_H
