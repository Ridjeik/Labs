#ifndef NOTEBOOKBUILDER_H
#define NOTEBOOKBUILDER_H

#include "PCComponents/processor.h"
#include "PCComponents/display.h"
#include "PCComponents/motherboard.h"
#include "PCComponents/ram.h"
#include "PCComponents/storage.h"
#include "../notebook.h"
#include <QDebug>

class NotebookBuilder
{
protected:
    Processor* cpu;
    Motherboard* motherboard;
    Display* display;
    RAM* ram;
    Storage* storage;
public:
    NotebookBuilder() = default;

    virtual void addCPU() = 0;
    virtual void addMotherboard() = 0;
    virtual void addDisplay() = 0;
    virtual void addRAM() = 0;
    virtual void addStorage() = 0;

    Notebook* getNotebook();

    virtual ~NotebookBuilder();
};

#endif // NOTEBOOKBUILDER_H
