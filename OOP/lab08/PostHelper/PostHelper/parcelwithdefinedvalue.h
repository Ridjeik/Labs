#ifndef PARCELWITHDEFINEDVALUE_H
#define PARCELWITHDEFINEDVALUE_H

#include "parcel.h"

class ParcelWithDefinedValue : public Parcel
{
    const double value;
public:
    ParcelWithDefinedValue(const Person &from, const Person &to, const double weight, const double value);
    ParcelWithDefinedValue(const ParcelWithDefinedValue& other);
    double getCost() const;
    void print(QLabel* label) const;
    std::string getInfoString() const;
};

#endif // PARCELWITHDEFINEDVALUE_H
