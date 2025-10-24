
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {

    this->type = "WrongAnimal";
    std::cout << "WrongAnimal Constructer" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy ) {

    this->type = copy.type;
}

WrongAnimal& WrongAnimal::operator= ( const WrongAnimal& other ) {

    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal( void ) {

    std::cout << "WrongAnimal Destructor" << std::endl;
}

void    WrongAnimal::makeSound( void ) const {

    std::cout << "WrongAnimal Sound." << std::endl;
}


std::string WrongAnimal::getType( void ) const {

    return (this->type);
}
