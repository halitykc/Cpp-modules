
#include "ScavTrap.hpp"


ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {

    this->_name = name;
    this->_hitpoint = 100;
    this->_energypoint = 50;
    this->_attackdamage = 20;

    std::cout << "ScavTrap Default Constructor Called!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &copy) : ClapTrap(copy) {

    std::cout << "ScavTrap Copy Constructor" << std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &other) {

    std::cout << "ClapTrap Copy Assignement operator called" << std::endl;

    if (this != &other)
    {
        this->_name = other._name;
        this->_attackdamage = other._attackdamage;
        this->_energypoint = other._energypoint;
        this->_hitpoint = other._hitpoint;
    }
    return(*this);
}

ScavTrap::~ScavTrap() {

    std::cout << "ScavTrap Destructor Called" << std::endl;
}

void    ScavTrap::attack( const std::string &target) {

    if (!this->_energypoint || !this->_hitpoint)
    {
        std::cout << "ScavTrap " << this->_name << " has no energy or hit point to attack" << std::endl;
        return;
    }

    this->_energypoint--;
    std::cout << "ScavTrap " << this->_name << " attacks " << target 
            << ", causing " << this->_attackdamage 
            << " points of damage!" << std::endl; 
    
}

void    ScavTrap::guardGate( void ) {

    std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}