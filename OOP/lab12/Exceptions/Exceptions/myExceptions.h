#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <exception>
#include <string>

class TooBigException : public std::exception
{
public:
    TooBigException() noexcept {}

    const char *what() const noexcept;
};

class TooSmallException : public std::exception
{
public:
    TooSmallException() noexcept {}

    const char *what() const noexcept;
};

class OverflowException : public std::exception
{
public:
    OverflowException() noexcept {};

    const char *what() const noexcept;
};

class InvalidFormatException : public std::exception
{
public:
    InvalidFormatException() noexcept {}

    const char *what() const noexcept;
};

class DivideByZeroException : public std::exception
{
public:
    DivideByZeroException() noexcept {}

    const char *what() const noexcept;
};

#endif // MYEXCEPTIONS_H
