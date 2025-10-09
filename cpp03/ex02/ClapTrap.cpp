
#include "ClapTrap.hpp"


ClapTrap::ClapTrap( std::string name ) {

    this->_name = name;
    this->_hitpoint = 10;
    this->_energypoint = 10;
    this->_attackdamage = 0;

    std::cout << "ClapTrap Default Constructor Called!" << std::endl;

}

ClapTrap::ClapTrap( const ClapTrap &copy) {

    std::cout << "ClapTrap Copy Constructor" << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &other) {

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

ClapTrap::~ClapTrap() {

    std::cout << "ClapTrap Destructor Called" << std::endl;
}

void    ClapTrap::attack( const std::string &target) {

    if (!this->_energypoint || !this->_hitpoint)
    {
        std::cout << "Claptrap " << this->_name << " has no energy or hit point to attack" << std::endl;
        return;
    }

    this->_energypoint--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target 
            << ", causing " << this->_attackdamage 
            << " points of damage!" << std::endl; 
    
}

void    ClapTrap::beRepaired( unsigned int amount ) {

    if (!this->_energypoint || !this->_hitpoint)
    {
        std::cout << "Claptrap " << this->_name << " has no energy or hit point to repair itself!" << std::endl;
        return;
    }

    this->_energypoint--;
    this->_hitpoint += amount;
    std::cout << "ClapTrap " << this->_name << " repaired itself with " << amount << " amount of hit points!" << std::endl;

}

void    ClapTrap::takeDamage( unsigned int amount ) {

    if (!this->_hitpoint)
    {
        std::cout << "ClapTrap " << this->_name << " Already Dead!" << std::endl;
        return;
    }
    if (amount >= this->_hitpoint)
    {
        
        this->_hitpoint = 0;
        std::cout << "ClapTrap " << this->_name << " took " << amount << " of damage!" << std::endl;
        std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
        return;
    }
    else
    {
        this->_hitpoint -= amount ;
        std::cout << "ClapTrap " << this->_name << " took " << amount << " of damage!" << std::endl;
    }


}