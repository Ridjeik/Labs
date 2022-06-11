#include "MyString.h"
#include <cstring>
#include <QDebug>
#include <string>

void MyString::resize(size_t size)
{
    if(this->c_str)
    {
        char *old = this->c_str;
        c_str = new char[size];
        strncpy(c_str, old, this->size);
        delete old;
    }
    else
    {
        c_str = new char[size];
    }
    this->size = size;
}

MyString::MyString()
{
    this->resize(0);
}

MyString::MyString(const char *c_str)
{
    this->resize(strlen(c_str));
    strncpy(this->c_str, c_str, size);
}

MyString::MyString(const MyString &other)
{
    this->resize(other.size);
    strncpy(this->c_str, other.c_str, size);
}

MyString &MyString::operator=(const MyString &other)
{
    this->resize(other.size);
    strncpy(this->c_str, other.c_str, size);
    return *this;
}

char *MyString::begin()
{
    return this->c_str;
}

char *MyString::end()
{
    return this->c_str + size;
}

const char *MyString::begin() const
{
    return this->c_str;
}

const char *MyString::end() const
{
    return this->c_str + size;
}

void MyString::debug() const
{
    qDebug() << this->c_str;
}

bool MyString::operator<(const MyString &other) const
{
    return strcmp(this->c_str, other.c_str) < 0;
}

bool MyString::operator>(const MyString &other) const
{
    return strcmp(this->c_str, other.c_str) > 0;
}

bool MyString::operator==(const MyString &other) const
{
    return strcmp(this->c_str, other.c_str) == 0;
}

std::ostream& operator<<(std::ostream& out, const MyString& str)
{
    for(char ch : str)
        out << ch;
    return out;
}

std::istream& operator>>(std::istream& in, MyString& str)
{
    char buffer[256];
    in >> buffer;
    str = buffer;
    return in;
}


