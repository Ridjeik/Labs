#include "notebookbuilder.h"

Notebook *NotebookBuilder::getNotebook()
{
    Notebook* res = new Notebook(cpu, motherboard, display, ram, storage);
    cpu = nullptr;
    motherboard = nullptr;
    display = nullptr;
    ram = nullptr;
    storage = nullptr;
    return res;
}

NotebookBuilder::~NotebookBuilder()
{
    qDebug() << __PRETTY_FUNCTION__ << " - base class";
}
