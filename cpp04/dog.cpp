

#include "Dog.hpp"


Dog::Dog( void ) {

    std::cout << "Dog Constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog( const Dog& copy ) : Animal(copy) {

    *this = copy;

}

Dog& Dog::operator=( const Dog& other) {

    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

Dog::~Dog() {

    std::cout << "Dog Destructor called!" << std::endl;

}

void    Dog::makeSound( void ) const {

    std::cout << "Dog haw haw!" << std::endl;
    
}