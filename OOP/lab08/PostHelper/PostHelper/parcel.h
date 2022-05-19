#ifndef PARCEL_H
#define PARCEL_H

#include "posting.h"

class Parcel : protected Posting
{
protected:
    const double weight;
public:
    Parcel(const Person& from, const Person& to, const double weight);
    Parcel(const Parcel& other);
    double getCost() const;
    void print(QLabel* label) const;
    std::string getInfoString() const;

};

#endif // PARCEL_H
