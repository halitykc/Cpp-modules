


#include "Animal.hpp"



Animal::Animal( void ) {

    std::cout << "Animal Default Constructor Called!" << std::endl;
    this->type = "Animal";
}

Animal::Animal( const Animal& copy) {

    *this = copy;
}

Animal& Animal::operator=( const Animal& other ) {

    if (this != &other)
        this->type = other.type;
    
    return (*this);
}

Animal::~Animal( void ) {

    std::cout << "Animal Destructor Called!" << std::endl;
}

void    Animal::makeSound( void ) const {

    std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType( void ) const {
    
    return (this->type);
}