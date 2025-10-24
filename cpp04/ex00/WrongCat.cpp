
#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {

    this->type = "WrongCat";
    std::cout << "WrongCat Constructer" << std::endl;
}

WrongCat::WrongCat( const WrongCat& copy ) : WrongAnimal(copy) {

    this->type = copy.type;
}

WrongCat& WrongCat::operator= ( const WrongCat& other ) {

    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongCat::~WrongCat( void ) {

    std::cout << "WrongCat Destructor" << std::endl;
}

void    WrongCat::makeSound( void ) const {

    std::cout << "Wrong Miyaw." << std::endl;
}


std::string WrongCat::getType( void ) const {

    return (this->type);
}
