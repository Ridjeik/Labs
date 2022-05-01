#include "posting.h"


Posting::Posting(const Person &from, const Person &to) : from(from), to(to)
{}

void Posting::print(QLabel *label) const
{
    label->setText("Used class: Posting");
}
