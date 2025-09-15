


#include "Harl.hpp"

void    Harl::_debug( void ) {

    std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
    "ketchup burger. I really do!" RESET << std::endl;

}

void    Harl::_info( void ) {

    std::cout <<CYAN << "I cannot believe adding extra bacon costs more money. You didn't put "
    "enough bacon in my burger! If you did, I wouldn't be asking for more!" RESET << std::endl;

}

void    Harl::_warning( void ) {

    std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I've been coming for "
    " years, whereas you started working here just last month." RESET << std::endl;

}

void    Harl::_error( void ) {

    std::cout << RED << "This is unacceptable! I want to speak to the manager now." RESET << std::endl;

}

void    Harl::complain( std::string level ) {

    int i = -1;
    std::string comp[4] = {"DEBUG","INFO","WARNING","ERROR"};
    void    (Harl::*funcs[4])() = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

    while (++i < 4)
    {
        if (level == comp[i])
        {
            (this->*funcs[i])();
            return;
        }
        
    }
    std::cout << "Ne diyi la bu" << std::endl;
}
