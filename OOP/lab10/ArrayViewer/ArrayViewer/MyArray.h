#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <QDebug>

#include "utils.h"

template <typename T, size_t size>
class Array
{
  T data[size];
public:
  Array()
  {}

  explicit Array(T initial)
  {
      for(T& elem : *this)
        elem = initial;
  }

  Array(const Array<T, size>& other)
  {
     utils::copy(other.begin(), other.end(), this->begin());
  }


  T* begin() {return data;}
  T* end() { return data + size;}
  const T* begin() const {return data;}
  const T* end() const {return data+size;}

  void sort(bool descending = false)
  {
      utils::sort(begin(), end());
      if(descending) utils::reverse(begin(), end());
  }

  T min_elem() const
  {
      T min = this->data[0];
      for(const T& item : *this)
          if(item < min)
              min = item;
      return min;
  }

};

template <typename T, size_t size>
std::ostream& operator<<(std::ostream& out, const Array<T, size>& array)
{
    out << "[ ";
    for(const T& elem : array)
        out << elem << " ";
    out << "]";
    return out;
}

template <typename T, size_t size>
std::istream& operator>>(std::istream& in, Array<T, size>& array)
{
    qDebug() << "Here" << array.begin() << array.end();
    for(T& elem : array)
        in >> elem;
    return in;
}

#endif // ARRAY_H
