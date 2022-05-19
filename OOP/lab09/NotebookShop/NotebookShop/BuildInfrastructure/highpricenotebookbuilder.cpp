#include "highpricenotebookbuilder.h"
#include "../includes.h"

void HighPriceNotebookBuilder::addCPU()
{
    cpu = new IntelCoreI9();
}

void HighPriceNotebookBuilder::addMotherboard()
{
    motherboard = new IntelMotherboard();
}

void HighPriceNotebookBuilder::addDisplay()
{
    display = new SamsungDisplay();
}

void HighPriceNotebookBuilder::addRAM()
{
    ram = new HyperXRAM();
}

void HighPriceNotebookBuilder::addStorage()
{
    storage = new SamsungSSD();
}






