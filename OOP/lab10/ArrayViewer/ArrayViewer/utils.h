#ifndef UTILS_H
#define UTILS_H

namespace utils{
    template <typename T>
    void copy(const T from, const T to, T dest)
    {
        for(const T iter = from; iter != to; iter++)
            *dest = *to;
    }


    template <typename T>
    void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }


    template <typename T>
    void sort(T from, T to)
    {
        T end = to;
        for(T a = from; a != to; a++, end--)
        {
            for(T b = from + 1; b != end; b++)
            {
                if(*b < *(b-1)) swap(*b, *(b-1));
            }
        }
    }

    template <typename T>
    void reverse(T from, T to)
    {

        for(to--; from < to; from++, to--)
            utils::swap(*from, *to);
    }
}
#endif // UTILS_H
