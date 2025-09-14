

#include "HumanA.hpp"


HumanA::HumanA( std::string name, Weapon &weapon ) : _weapon(weapon) {

    this->_name = name;
}

void     HumanA::attack( void ) {

    std::cout << CYAN << this->_name << RESET " attacks with their "
            << YELLOW << _weapon.getType() << RESET << std::endl;

}
