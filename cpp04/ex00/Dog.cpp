
#include "Dog.hpp"

Dog::Dog( void ) {

    this->type = "Dog";
    std::cout << "Dog Constructer" << std::endl;
}

Dog::Dog( const Dog& copy ) : Animal(copy) {

    this->type = copy.type;
}

Dog& Dog::operator= ( const Dog& other ) {

    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Dog::~Dog( void ) {

    std::cout << "Dog Destructor" << std::endl;
}

void    Dog::makeSound( void ) const {

    std::cout << "Haw." << std::endl;
}

std::string Dog::getType( void ) const{

    return (this->type);
}
