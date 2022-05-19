#ifndef SAMSUNGDISPLAY_H
#define SAMSUNGDISPLAY_H

#include "../display.h"

class SamsungDisplay : public Display
{
public:
    SamsungDisplay() = default;
    virtual ~SamsungDisplay() = default;
    // Hardware interface
public:
    std::string getInfoString() const override;
    double getPrice() const override;

    // Display interface
public:
    double getSize() const override;
};

#endif // SAMSUNGDISPLAY_H
