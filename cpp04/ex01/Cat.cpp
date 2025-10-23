
#include "Cat.hpp"

Cat::Cat( void ) {

    this->type = "Cat";
    std::cout << "Cat Constructer" << std::endl;
    this->brain = new Brain();
}

Cat::Cat( const Cat& copy ) : Animal(copy) {

    this->type = copy.type;
    this->brain = new Brain(*copy.brain);
    std::cout << "Cat Copied" << std::endl;
}

Cat& Cat::operator=( const Cat& other ) {

    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
        std::cout << "Cat Assigned" << std::endl;
    }
    return (*this);
}

Cat::~Cat( void ) {

    std::cout << "Cat Destructor" << std::endl;
    delete this->brain;
}

void    Cat::makeSound( void ) const {

    std::cout << "Miyaw." << std::endl;
}


std::string Cat::getType( void ) const {

    return (this->type);
}

Brain& Cat::get_brain( void ) const {

    return (*this->brain);
}
