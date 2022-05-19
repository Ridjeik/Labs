#ifndef TIANMADISPLAY_H
#define TIANMADISPLAY_H

#include "../display.h"

class TianmaDisplay : public Display
{
public:
    TianmaDisplay() = default;
    virtual ~TianmaDisplay() = default;
    // Hardware interface
public:
    std::string getInfoString() const override;
    double getPrice() const override;

    // Display interface
public:
    double getSize() const override;
};

#endif // TIANMADISPLAY_H
