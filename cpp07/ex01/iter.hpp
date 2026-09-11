

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename F>
void    iter(T *adress, const unsigned int size, F function) {

    for (unsigned int i = 0; i < size; i++)
        function(adress[i]);

}


#endif
