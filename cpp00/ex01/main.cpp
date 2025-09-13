




#include "Classes.hpp"


int main(int argc, char *argv[])
{
    Phonebook phonebook;
    std::string cmd;


    while (1)
    {
        std::cout << CYAN << "=>> " << RESET;
        if(!std::getline(std::cin, cmd))
        {
            std::cout << RED << "\nEOF Quiting program" << RESET << std::endl;
            break;
        }
        if (cmd == "ADD")
        {
            add_contact(&phonebook);
        }
        else if (cmd == "SEARCH")
        {
            search_contact(phonebook);
        }
        else if (cmd == "EXIT")
            break;
    }


    
    return 0;
}
