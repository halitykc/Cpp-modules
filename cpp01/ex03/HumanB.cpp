

#include "HumanB.hpp"


HumanB::HumanB( std::string name ) {

    this->_name = name;
    this->_weapon = NULL;
}

void    HumanB::attack( void ) {

    if ( this->_weapon )
    {
        std::cout << CYAN << this->_name << RESET " attack with their "
         << YELLOW << this->_weapon->getType() << RESET << std::endl;   
    }
    else
        std::cout << CYAN << this->_name << RESET RED " is unarmed!" << RESET << std::endl;
}
void    HumanB::setWeapon( Weapon &weapon) {

    this->_weapon = &weapon;
}