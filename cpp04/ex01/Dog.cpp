
#include "Dog.hpp"

Dog::Dog( void ) {

    this->type = "Dog";
    std::cout << "Dog Constructer" << std::endl;
    this->brain = new Brain();
}

Dog::Dog( const Dog& copy ) : Animal(copy) {

    this->type = copy.type;
    this->brain = new Brain(*copy.brain);
    std::cout << "Dog Copied" << std::endl;
}

Dog& Dog::operator= ( const Dog& other ) {

    if (this != &other)
    {
        this->type = other.type;
        this->brain = new Brain(*other.brain);

    }
    return (*this);
}

Dog::~Dog( void ) {

    std::cout << "Dog Destructor" << std::endl;
    delete this->brain;
}

void    Dog::makeSound( void ) const {

    std::cout << "Haw." << std::endl;
}

std::string Dog::getType( void ) const{

    return (this->type);
}

Brain& Dog::get_brain( void ) const {

    return (*this->brain);
}
