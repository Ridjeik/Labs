#ifndef LOWPRICENOTEBOOKBUILDER_H
#define LOWPRICENOTEBOOKBUILDER_H

#include "notebookbuilder.h"

class LowPriceNotebookBuilder : public NotebookBuilder
{
public:
    LowPriceNotebookBuilder() = default;

    // NotebookBuilder interface
public:
    void addCPU() override;
    void addMotherboard() override;
    void addDisplay() override;
    void addRAM() override;
    void addStorage() override;
};

#endif // LOWPRICENOTEBOOKBUILDER_H
