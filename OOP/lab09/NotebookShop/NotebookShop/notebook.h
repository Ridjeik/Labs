#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "PCComponents/processor.h"
#include "PCComponents/display.h"
#include "PCComponents/motherboard.h"
#include "PCComponents/ram.h"
#include "PCComponents/storage.h"

class Notebook
{
    Processor* cpu;
    Motherboard* motherboard;
    Display* display;
    RAM* ram;
    Storage* storage;
public:

    Notebook(Processor* cpu, Motherboard* motherboard, Display* display, RAM* ram, Storage* storage);
    double getPrice() const;
    std::string getInfoString() const;
    ~Notebook();
};

#endif // NOTEBOOK_H
