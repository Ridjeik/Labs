#ifndef HARDWARE_H
#define HARDWARE_H

#include <string>

class Hardware
{
public:
    virtual std::string getInfoString() const = 0;
    virtual double getPrice() const = 0;

    virtual ~Hardware() = default;
};

#endif // HARDWARE_H
