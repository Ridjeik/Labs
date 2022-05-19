#ifndef LISTMODEL_H
#define LISTMODEL_H
#include "lab10_lib.h"
#include "constlistiterator.h"
#include <QTableWidget>

class ListModel
{
    List *list;
public:
    ListModel(List* list);

    ConstListIterator begin() const;
    ConstListIterator end() const;

    size_t size() const;
    QString listName() const;

    QTableWidget* toTableView() const;
};

#endif // LISTMODEL_H
