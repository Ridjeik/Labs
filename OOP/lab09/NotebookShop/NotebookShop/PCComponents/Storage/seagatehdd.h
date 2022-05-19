#ifndef SEAGATEHDD_H
#define SEAGATEHDD_H

#include "../storage.h"

class SeagateHDD : public Storage
{
public:
    SeagateHDD() = default;
    virtual ~SeagateHDD() = default;
    // Hardware interface
public:
    std::string getInfoString() const;
    double getPrice() const;

    // Storage interface
public:
    double getStoragevolume() const;
};

#endif // SEAGATEHDD_H
