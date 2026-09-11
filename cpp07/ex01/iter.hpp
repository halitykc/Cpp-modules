

#ifndef ITER_HPP
#define ITER_HPP


template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T &a, const T &b)
{   
    if (a < b)
        return a;
    else if (a == b)
        return b;
    else
        return b;
}

template <typename T>
T max(const T &a, const T &b)
{
    if (a > b)
        return a;
    else if (a == b)
        return b;
    else
        return b;
}

#endif
