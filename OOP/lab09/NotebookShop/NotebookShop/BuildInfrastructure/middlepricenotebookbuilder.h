#ifndef MIDDLEPRICENOTEBOOKBUILDER_H
#define MIDDLEPRICENOTEBOOKBUILDER_H

#include "notebookbuilder.h"

class MiddlePriceNotebookBuilder : public NotebookBuilder
{
public:
    MiddlePriceNotebookBuilder() = default;

    // NotebookBuilder interface
public:
    void addCPU() override;
    void addMotherboard() override;
    void addDisplay() override;
    void addRAM() override;
    void addStorage() override;

    virtual ~MiddlePriceNotebookBuilder();
};

#endif // MIDDLEPRICENOTEBOOKBUILDER_H
