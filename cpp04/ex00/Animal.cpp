
#include "Animal.hpp"

Animal::Animal(void)
{
    this->type = "Animal";
    std::cout << "Animal Constructor" << std::endl;
}

Animal::Animal( const Animal& copy)
{
    *this = copy;
}

Animal& Animal::operator= ( const Animal& other )
{
    if (this != &other)
    {
        this->type = other.type;
    }

    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor" << std::endl;
}

void Animal::makeSound( void ) const {

    std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType( void ) const {

    return (this->type);
}
