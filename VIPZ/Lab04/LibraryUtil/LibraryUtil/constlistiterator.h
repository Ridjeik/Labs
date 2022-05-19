#ifndef CONSTLISTITERATOR_H
#define CONSTLISTITERATOR_H
#include "lab10_lib.h"

class ConstListIterator
{
    ListItem* current;
public:

    ConstListIterator(ListItem* item);

    ConstListIterator& operator++();
    const Book& operator*() const;
    bool operator!=(const ConstListIterator& other) const;
};

#endif // CONSTLISTITERATOR_H
