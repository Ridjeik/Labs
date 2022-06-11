#include "notebookproducer.h"

NotebookProducer::NotebookProducer(NotebookBuilder *builder) : builder(builder){}

Notebook *NotebookProducer::produce()
{
    builder->addCPU();
    builder->addDisplay();
    builder->addMotherboard();
    builder->addRAM();
    builder->addStorage();
    return builder->getNotebook();
}

void NotebookProducer::changeBuilder(NotebookBuilder *builder)
{
    this->builder = builder;
}

NotebookProducer::~NotebookProducer()
{
    delete this->builder;
}
