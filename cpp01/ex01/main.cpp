



#include "Zombie.hpp"


int main( void )
{
    int N = 5;
    Zombie * zumbis = zombieHorde( N, "mahmut" );

    for (int i = 0; i < N; i++)
    {
        zumbis[i].announce();
    }
    
    delete [] zumbis;
    return 0;
}
