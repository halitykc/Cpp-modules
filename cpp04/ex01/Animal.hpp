


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string     type;
    public:
        Animal(void);
        Animal( const Animal& copy );
        Animal& operator=( const Animal& other );
        virtual ~Animal();

        virtual void    makeSound( void ) const = 0;
        std::string getType( void ) const;
        
        virtual Brain&  get_brain( void ) const = 0;

};


#endif