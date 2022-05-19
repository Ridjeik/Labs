#ifndef ORDER_H
#define ORDER_H

#include "notebook.h"

class Order
{
    Notebook* notebooks[5];
    size_t lastIndex = 0;
public:
    Order() = default;

    void add(Notebook* notebook);
    std::string getOrderInfo() const;
    double getTotalPrice() const;
    void writeToFile(const std::string& filename);
    size_t size() const;

    ~Order();
};

#endif // ORDER_H
