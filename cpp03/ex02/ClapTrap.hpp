


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

    protected:
        std::string          _name;
        unsigned int         _hitpoint;
        unsigned int         _energypoint;
        unsigned int         _attackdamage;
        
    public:
        
        ClapTrap( std::string name );
        ClapTrap( const ClapTrap &copy );
        ClapTrap& operator=( const ClapTrap &other);
        ~ClapTrap();

        void    attack( const std::string& target );
        void    takeDamage( unsigned int amout );
        void    beRepaired( unsigned int amount );

};

#endif