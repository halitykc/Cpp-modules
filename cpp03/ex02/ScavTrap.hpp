

#define SCAVTRAP_HPP
#ifndef SCATRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    public:

        ScavTrap( std::string name );
        ScavTrap( const ScavTrap &copy );
        ScavTrap& operator=( const ScavTrap &other);
        ~ScavTrap();

        void    guardGate( void );
        void    attack( const std::string& target );

};


#endif