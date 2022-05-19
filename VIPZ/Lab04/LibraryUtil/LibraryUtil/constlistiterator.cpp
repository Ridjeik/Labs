#include "constlistiterator.h"

ConstListIterator::ConstListIterator(ListItem *item) : current(item)
{}

ConstListIterator& ConstListIterator::operator++()
{
    current = current->next;
    return *this;
}

const Book& ConstListIterator::operator*() const
{
    return current->data;
}

bool ConstListIterator::operator!=(const ConstListIterator &other) const
{
    return this->current != other.current;
}

