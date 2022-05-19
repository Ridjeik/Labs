#ifndef STORAGE_H
#define STORAGE_H

#include "hardware.h"

class Storage : public Hardware
{
public:
    virtual double getStoragevolume() const = 0;

    virtual ~Storage() = default;
};

#endif // STORAGE_H
