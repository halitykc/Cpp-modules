
#include "Cat.hpp"

Cat::Cat( void ) {

    this->type = "Cat";
    std::cout << "Cat Constructer" << std::endl;
}

Cat::Cat( const Cat& copy ) : Animal(copy) {

    this->type = copy.type;
}

Cat& Cat::operator= ( const Cat& other ) {

    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Cat::~Cat( void ) {

    std::cout << "Cat Destructor" << std::endl;
}

void    Cat::makeSound( void ) const {

    std::cout << "Miyaw." << std::endl;
}


std::string Cat::getType( void ) const {

    return (this->type);
}
