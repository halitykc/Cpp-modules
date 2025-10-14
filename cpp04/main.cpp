

#include "Animal.hpp"
#include "Cat.hpp"

int main()
{
    Animal hayvan;
    Cat kedi;

    hayvan.makeSound();
    kedi.makeSound();
    
    std::cout << kedi.getType() << std::endl;

    return 0;
}
