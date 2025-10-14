

#include "Dog.hpp"



Dog::Dog( void ) {

    std::cout << "Dog Default Constructor Called!" << std::endl;
    this->type = "Dog";
}

Dog::Dog( const Dog& copy) : Animal(copy)  {

    *this = copy;
}

Dog& Dog::operator=( const Dog& other ) {

    if (this != &other)
        this->type = other.type;
    
    return (*this);
}

Dog::~Dog( void ) {

    std::cout << "Dog Destructor Called!" << std::endl;
}

void    Dog::makeSound( void ) const {

    std::cout << "ONLAR ARKADAN HAV HAV HAV" << std::endl;
}