#ifndef ELECTRONICTRANSFER_H
#define ELECTRONICTRANSFER_H

#include "posting.h"

class ElectronicTransfer : protected Posting
{
    const double sum;
public:
    ElectronicTransfer(const Person& from, const Person& to, const double sum);
    ElectronicTransfer(const ElectronicTransfer& other);
    double getCost() const;
    void print(QLabel* label) const;
    std::string getInfoString() const;
};

#endif // ELECTRONICTRANSFER_H
