

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
//#include "Dog.hpp"

int main()
{
    const WrongAnimal * hayvan = new WrongAnimal();
    const WrongAnimal * kedi = new WrongCat();
    //const Animal * kopek = new Dog();

    std::cout << kedi->getType() << " " << std::endl;
    //std::cout << kopek->getType() << " " << std::endl;

    hayvan->makeSound();
    kedi->makeSound();
    //kopek->makeSound();

    delete hayvan;
    delete kedi;
    //delete kopek;

    return 0;
}
