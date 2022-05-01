#ifndef PERSON_H
#define PERSON_H

#include <string>
class Person
{
    const std::string name;
    const std::string surname;
public:
    Person(const std::string& name, const std::string& surname);
    std::string getName() const;
    std::string getSurname() const;
};

#endif // PERSON_H
