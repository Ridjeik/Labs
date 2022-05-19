#ifndef LGDISPLAY_H
#define LGDISPLAY_H

#include "../display.h"

class LGDisplay : public Display
{
public:
    LGDisplay() = default;
    virtual ~LGDisplay() = default;
    // Hardware interface
public:
    std::string getInfoString() const override;
    double getPrice() const override;

    // Display interface
public:
    double getSize() const override;
};

#endif // LGDISPLAY_H
