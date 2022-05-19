#ifndef INTELMOTHERBOARD_H
#define INTELMOTHERBOARD_H

#include "../motherboard.h"

class IntelMotherboard : public Motherboard
{
public:
    IntelMotherboard() = default;
    virtual ~IntelMotherboard() = default;
    // Hardware interface
public:
    std::string getInfoString() const;
    double getPrice() const;

    // Motherboard interface
public:
    std::string getSocket() const;
};

#endif // INTELMOTHERBOARD_H
