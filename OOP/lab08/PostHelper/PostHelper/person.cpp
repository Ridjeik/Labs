#include "person.h"

Person::Person(const std::string &name, const std::string &surname) : name(name), surname(surname)
{}

std::string Person::getName() const {return name;}
std::string Person::getSurname() const {return surname;}

