#include "lowpricenotebookbuilder.h"
#include "../includes.h"

void LowPriceNotebookBuilder::addCPU()
{
    cpu = new IntelPentium();
}

void LowPriceNotebookBuilder::addMotherboard()
{
    motherboard = new AsusMotherboard();
}

void LowPriceNotebookBuilder::addDisplay()
{
    display = new TianmaDisplay();
}

void LowPriceNotebookBuilder::addRAM()
{
    ram = new SamsungRAM();
}

void LowPriceNotebookBuilder::addStorage()
{
    storage = new SeagateHDD();
}

LowPriceNotebookBuilder::~LowPriceNotebookBuilder()
{
    qDebug() << __PRETTY_FUNCTION__ << " - derived class";
}





