#ifndef ASUSMOTHERBOARD_H
#define ASUSMOTHERBOARD_H

#include "../motherboard.h"

class AsusMotherboard : public Motherboard
{
public:
    AsusMotherboard() = default;
    virtual ~AsusMotherboard() = default;
    // Hardware interface
public:
    std::string getInfoString() const;
    double getPrice() const;

    // Motherboard interface
public:
    std::string getSocket() const;
};

#endif // ASUSMOTHERBOARD_H
