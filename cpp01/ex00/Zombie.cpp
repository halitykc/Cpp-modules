

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {

    this->_name = name;
    std::cout << GREEN "Construtor of " << this->_name << " is called." RESET << std::endl;
}

Zombie::~Zombie( void ) {

    std::cout << RED "Destructor of " << this->_name << " is called." RESET<< std::endl;
}

void    Zombie::announce ( void ) {

    std::cout << CYAN << this->_name << " BraiiiiiiinnnzzzZ..." RESET << std::endl;

}