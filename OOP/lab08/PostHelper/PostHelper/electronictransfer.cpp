#include "electronictransfer.h"

ElectronicTransfer::ElectronicTransfer(const Person &from, const Person &to, const double sum) : Posting(from, to), sum(sum)
{}

ElectronicTransfer::ElectronicTransfer(const ElectronicTransfer &other) : Posting(other.from, other.to), sum(other.sum)
{}

double ElectronicTransfer::getCost() const
{
    if(sum < 2000) return (0.02 * sum) * (1 + tax);
    else return (0.015 * sum) * (1 + tax);
}

void ElectronicTransfer::print(QLabel *label) const
{
    label->setText("Used class: ParcelWithDefinedValue");
}

std::string ElectronicTransfer::getInfoString() const
{
    return "Electronic transfer from " + from.getName() + " " + from.getSurname() + " to " + to.getName() + " " + to.getSurname() + " with the price " + std::to_string(getCost()) + " UAH";
}


