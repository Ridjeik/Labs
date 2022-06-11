#include "middlepricenotebookbuilder.h"
#include "../includes.h"

void MiddlePriceNotebookBuilder::addCPU()
{
    cpu = new IntelCoreI3();
}

void MiddlePriceNotebookBuilder::addMotherboard()
{
    motherboard = new IntelMotherboard();
}

void MiddlePriceNotebookBuilder::addDisplay()
{
    display = new LGDisplay();
}

void MiddlePriceNotebookBuilder::addRAM()
{
    ram = new KingstonRAM();
}

void MiddlePriceNotebookBuilder::addStorage()
{
    storage = new SeagateHDD();
}

MiddlePriceNotebookBuilder::~MiddlePriceNotebookBuilder()
{
    qDebug() << __PRETTY_FUNCTION__ << " - derived class";
}








