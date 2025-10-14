

#include "Cat.hpp"



Cat::Cat( void ) {

    std::cout << "Cat Default Constructor Called!" << std::endl;
    this->type = "Cat";
}

Cat::Cat( const Cat& copy) : Animal(copy) {

    *this = copy;
}

Cat& Cat::operator=( const Cat& other ) {

    if (this != &other)
        this->type = other.type;
    
    return (*this);
}

Cat::~Cat( void ) {

    std::cout << "Cat Destructor Called!" << std::endl;
}

void    Cat::makeSound( void ) const {

    std::cout << "ONLAR ARKADAN MIYAW MIYAW MIYAW" << std::endl;
}