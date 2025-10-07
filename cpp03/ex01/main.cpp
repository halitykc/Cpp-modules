

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main(void)
{
    std::cout << "\n" << "=== ClapTrap ===" << "\n\n";
    ClapTrap clap("Clappy");

    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n";

    clap.attack("Target2");
    clap.takeDamage(6);
    clap.beRepaired(2);

    std::cout << "\n" << "=== ScavTrap ==="  << "\n\n";
    ScavTrap scav("Scavy");

    scav.attack("Enemy1");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n"  << "=== Destructor Çağrıları ===" << "\n\n";
    return (0);
}
