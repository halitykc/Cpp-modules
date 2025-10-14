

#include "Animal.hpp"


Animal::Animal( void ) {

    std::cout << "Animal Constructor called" << std::endl;

}

Animal::Animal( const Animal& copy ) {

    *this = copy;

}

Animal& Animal::operator=( const Animal& other) {

    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

Animal::~Animal() {

    std::cout << "Animal Destructor called!" << std::endl;

}

void    Animal::makeSound( void ) {

    std::cout << "Animal Sound!" << std::endl;
    
}