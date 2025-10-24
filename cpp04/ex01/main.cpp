
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    int arraySize = 4;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    Dog originalDog;
    
    originalDog.get_brain().set_idea(0,"Original Dog Idea");


    Dog copyDog = originalDog; 
    originalDog.get_brain().set_idea(0,"Copied Dog Idea");

    std::cout << "================= Deep Copy Test =================" << std::endl;
    copyDog.get_brain().get_idea(0);
    originalDog.get_brain().get_idea(0);
    std::cout << "==================================================" << std::endl;

    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }

    return 0;
}
