#ifndef NOTEBOOKPRODUCER_H
#define NOTEBOOKPRODUCER_H

#include "notebookbuilder.h"

class NotebookProducer
{
    NotebookBuilder* builder;
public:
    NotebookProducer(NotebookBuilder* builder);

    Notebook* produce();
    void changeBuilder(NotebookBuilder* builder);

    ~NotebookProducer();
};

#endif // NOTEBOOKPRODUCER_H
