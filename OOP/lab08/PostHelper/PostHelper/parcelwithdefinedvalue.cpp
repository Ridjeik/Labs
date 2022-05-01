#include "parcelwithdefinedvalue.h"


ParcelWithDefinedValue::ParcelWithDefinedValue(const Person &from, const Person &to, const double weight, const double value) : Parcel(from, to, weight), value(value)
{}

ParcelWithDefinedValue::ParcelWithDefinedValue(const ParcelWithDefinedValue &other) : Parcel(other.from, other.to, other.weight), value(other.value)
{}

double ParcelWithDefinedValue::getCost() const
{
    return Parcel::getCost() + std::min(1.0, 0.01 * value) * (1 + tax);
}

void ParcelWithDefinedValue::print(QLabel *label) const
{
    label->setText("Used class: ParcelWithDefinedValue");
}

std::string ParcelWithDefinedValue::getInfoString() const
{
    return "Parcel with defined value from " + from.getName() + " " + from.getSurname() + " to " + to.getName() + " " + to.getSurname() + " with the price " + std::to_string(getCost()) + " UAH";
}



