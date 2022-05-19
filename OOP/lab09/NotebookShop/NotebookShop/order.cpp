#include "order.h"
#include <fstream>

void Order::add(Notebook *notebook)
{
    if(lastIndex == 5)
        return;
    notebooks[lastIndex++] = notebook;
}

std::string Order::getOrderInfo() const
{
    std::string totalInfo = "Order: \n";
    for(size_t i = 0; i < lastIndex; i++)
        totalInfo += notebooks[i]->getInfoString();
    totalInfo += "Total order price: " + std::to_string(this->getTotalPrice()) + ";\n";
    return totalInfo;
}

double Order::getTotalPrice() const
{
    double totalSum = 0;
    for(size_t i = 0; i < lastIndex; i++)
        totalSum += notebooks[i]->getPrice();
    return totalSum;
}

void Order::writeToFile(const std::string &filename)
{
    std::ofstream fout(filename, std::ios::app);
    fout << getOrderInfo();
    fout.close();
}

size_t Order::size() const
{
    return lastIndex;
}

Order::~Order()
{
    for(size_t i = 0; i < lastIndex; i++)
        delete notebooks[i];
}
