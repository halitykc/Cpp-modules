

#include "WrongCat.hpp"


WrongCat::WrongCat( void ) {

    std::cout << "WrongCat Default Constructor Called!" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& copy) : WrongAnimal(copy) {

    *this = copy;
}

WrongCat& WrongCat::operator=( const WrongCat& other ) {

    if (this != &other)
        this->type = other.type;
    
    return (*this);
}

WrongCat::~WrongCat( void ) {

    std::cout << "WrongCat Destructor Called!" << std::endl;
}

void    WrongCat::makeSound( void ) const {

    std::cout << "ONLAR ARKADAN MIYAW MIYAW MIYAW" << std::endl;
}