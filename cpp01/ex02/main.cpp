



#include <iostream>


#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

int main( void )
{
    std::string word = "HI THIS IS BRAIN";
    std::string *stringPTR = &word;
    std::string &stringREF = word;

    std::cout << YELLOW << &word << " " GREEN << word << RESET << std::endl;
    std::cout << YELLOW << stringPTR << " " GREEN << *stringPTR << RESET <<  std::endl;
    std::cout << YELLOW << &stringREF << " " GREEN << stringREF << RESET << std::endl;

    return 0;
}
