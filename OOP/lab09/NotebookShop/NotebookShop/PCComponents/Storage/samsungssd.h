#ifndef SAMSUNGSSD_H
#define SAMSUNGSSD_H

#include "../storage.h"

class SamsungSSD : public Storage
{
public:
    SamsungSSD() = default;
    virtual ~SamsungSSD() = default;
    // Hardware interface
public:
    std::string getInfoString() const;
    double getPrice() const;

    // Storage interface
public:
    double getStoragevolume() const;
};

#endif // SAMSUNGSSD_H
