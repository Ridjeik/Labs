#ifndef POSTING_H
#define POSTING_H

#include "person.h"
#include <QLabel>
class Posting
{
protected:
    static constexpr double tax = 0.14;
    const Person from;
    const Person to;
    Posting(const Person& from, const Person& to);
    void print(QLabel* label) const;
};

#endif // POSTING_H
