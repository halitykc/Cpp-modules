

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{

    Brain *brain  = new Brain();
    

    brain->set_idea(0, "I want to play");
    brain->set_idea(1, "I want to eat");
    brain->get_idea(0);
    brain->get_idea(1);
    
    Brain *brain2 = brain;

    brain->set_idea(1, "I want to sleep");
    brain->get_idea(1);
    brain2->get_idea(1);
    
    delete brain;
	return (0);
}
    