

#include "ClapTrap.hpp"


int main()
{
    ClapTrap a = ClapTrap("Mahmut");
	ClapTrap b = ClapTrap("Ismet");

	a.attack("Ismet");
	b.takeDamage(20);
	b.beRepaired(20);
	b.attack("Mahmut");
	a.takeDamage(100);
	a.takeDamage(100);
	b.takeDamage(50);

    return 0;
}

