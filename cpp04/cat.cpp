

#include "Cat.hpp"


Cat::Cat( void ) {

    std::cout << "Cat Constructor called" << std::endl;

}

Cat::Cat( const Cat& copy ) : Animal(copy) {

    *this = copy;

}

Cat& Cat::operator=( const Cat& other) {

    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

Cat::~Cat() {

    std::cout << "Cat Destructor called!" << std::endl;

}

void    Cat::makeSound( void ) {

    std::cout << "Meow meow!" << std::endl;
    
}