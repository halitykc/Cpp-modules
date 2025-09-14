


#include "Zombie.hpp"




Zombie*     zombieHorde( int N, std::string name ) {

    if (N <= 0)
        return NULL;
    
    Zombie * zumbi = new Zombie[N];

    for (int i = 0; i < N; i++)
        zumbi[i].give_name(name);
    
    return (zumbi);
}
