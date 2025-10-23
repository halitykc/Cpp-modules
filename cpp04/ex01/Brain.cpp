
#include "Brain.hpp"


Brain::Brain( void ) {

    std::cout << "Brain Constructor" << std::endl;
}

Brain::Brain( const Brain& copy ) {

    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = copy.ideas[i];
    }
    std::cout << "Brain Copied" << std::endl;
    
}

Brain& Brain::operator=( const Brain& other ) {
    
    if (this != &other)
    {
        for (size_t i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    
    return (*this);
}

Brain::~Brain( void ) {

    std::cout << "Brain Destructor" << std::endl;
}

void    Brain::get_idea( int index ) {

    std::cout << this->ideas[index] << std::endl;
}

void    Brain::set_idea( int index, std::string idea ) {

    this->ideas[index] = idea;
}