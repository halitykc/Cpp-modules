

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {

    this->_name = name;
    this->_hitpoint = 100;
    this->_energypoint = 100;
    this->_attackdamage = 30;

    std::cout << "FragTrap Default Constructor Called!" <<  std::endl;

}

FragTrap::FragTrap( const FragTrap &copy ) : ClapTrap(copy) {

    std::cout << "FragTrap Copy Constructor Called!" << std::endl;
    *this = copy;

}

FragTrap& FragTrap::operator=( const FragTrap &other) {

    if (this != &other)
    {
        this->_name         =   other._name;
        this->_hitpoint     =   other._hitpoint;
        this->_energypoint  =   other._energypoint;
        this->_attackdamage =   other._attackdamage;
    }
    
    return (*this);
}

FragTrap::~FragTrap() {

    std::cout << "FragTrap Destructor Called!" << std::endl;
}

void    FragTrap::highFivesGuys( void ) {

    std::cout << "High Five Guys!!!" << std::endl;
}