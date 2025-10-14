



#include "WrongAnimal.hpp"



WrongAnimal::WrongAnimal( void ) {

    std::cout << "WrongAnimal Default Constructor Called!" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy) {

    *this = copy;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other ) {

    if (this != &other)
        this->type = other.type;
    
    return (*this);
}

WrongAnimal::~WrongAnimal( void ) {

    std::cout << "WrongAnimal Destructor Called!" << std::endl;
}

void    WrongAnimal::makeSound( void ) const {

    std::cout << "WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType( void ) const {
    
    return (this->type);
}