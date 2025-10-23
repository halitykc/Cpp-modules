
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class   Brain {

    private:
        std::string ideas[100];
    public:
        Brain();
        Brain( const Brain& copy);
        Brain& operator= ( const Brain& other );
        ~Brain();

        void    set_idea( int index, std::string idea );
        void    get_idea( int index );
};

#endif