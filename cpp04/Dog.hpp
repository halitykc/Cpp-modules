



#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal {

    public:
        Dog();
        Dog( const Dog& copy );
        Dog& operator=( const Dog& other);
        ~Dog();
        void    makeSound();
        
};


#endif