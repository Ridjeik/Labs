#include "parcel.h"


Parcel::Parcel(const Person &from, const Person &to, const double weight) : Posting(from, to), weight(std::max(100.0, weight))
{}

Parcel::Parcel(const Parcel &other) : Posting(other.from, other.to), weight(other.weight)
{}

double Parcel::getCost() const
{
    if(weight <= 250) return 22.5 * (1+tax);
    else if(weight < 1000) return 45 * (1+tax);
    else if(weight < 2000) return 60 * (1+tax);
    else return 75 * (1+tax);
}

void Parcel::print(QLabel *label) const
{
    label->setText("Used class: Parcel");
}

std::string Parcel::getInfoString() const
{
    return "Parcel from " + from.getName() + " " + from.getSurname() + " to " + to.getName() + " " + to.getSurname() + " with the price " + std::to_string(getCost()) + " UAH";
}
