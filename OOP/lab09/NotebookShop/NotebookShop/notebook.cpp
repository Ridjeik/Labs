#include "notebook.h"

Notebook::Notebook(Processor *cpu, Motherboard *motherboard, Display *display, RAM *ram, Storage *storage)
    : cpu(cpu), motherboard(motherboard), display(display), ram(ram), storage(storage)
{}

double Notebook::getPrice() const
{
    Hardware* components[] = {cpu, motherboard, display, ram, storage};
    double totalSum = 0;
    for(Hardware* component : components)
        totalSum += component->getPrice();
    return totalSum * 1.1;
}

std::string Notebook::getInfoString() const
{
    Hardware* components[] = {cpu, motherboard, display, ram, storage};
    std::string totalInfoString = "Notebook: \n";
    for(Hardware* component : components)
        totalInfoString += component->getInfoString();
    totalInfoString += "Total notebook price: " + std::to_string(this->getPrice()) + ";\n";
    return totalInfoString;
}

Notebook::~Notebook()
{
    Hardware* components[] = {cpu, motherboard, display, ram, storage};
    for(Hardware* component : components)
        delete component;
}
