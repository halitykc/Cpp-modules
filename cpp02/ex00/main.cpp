




#include "Fixed.hpp"


#include "Fixed.hpp"
#include <iostream>

int main() {
    Fixed a;                 // Default constructor çağrılır
    Fixed b(a);   
    Fixed c;                 
    c = b;                   // Copy assignment operator çağrılır

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;


    return 0; // Program bitince destructor'lar çağrılır
}
