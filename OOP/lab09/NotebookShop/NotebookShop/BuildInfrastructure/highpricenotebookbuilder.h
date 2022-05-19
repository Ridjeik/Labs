#ifndef HIGHPRICENOTEBOOKBUILDER_H
#define HIGHPRICENOTEBOOKBUILDER_H

#include "notebookbuilder.h"

class HighPriceNotebookBuilder : public NotebookBuilder
{
public:
    HighPriceNotebookBuilder() = default;

    // NotebookBuilder interface
public:
    void addCPU() override;
    void addMotherboard() override;
    void addDisplay() override;
    void addRAM() override;
    void addStorage() override;
};

#endif // HIGHPRICENOTEBOOKBUILDER_H
