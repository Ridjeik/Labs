#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString
{
    char* c_str = nullptr;
    void resize(size_t size);
    size_t size;

public:
    MyString();
    MyString(const char* c_str);
    MyString(const MyString& other);

    MyString& operator=(const MyString& other);

    char* begin();
    char* end();
    const char* begin() const;
    const char* end() const;

    void debug() const;

    bool operator< (const MyString& other) const;
    bool operator> (const MyString& other) const;
    bool operator== (const MyString& other) const;
};

std::ostream& operator<<(std::ostream& out, const MyString& str);

std::istream& operator>>(std::istream& in, MyString& str);

#endif // MYSTRING_H
