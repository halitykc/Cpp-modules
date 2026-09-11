

#include "iter.hpp"


template <typename K>
void    inc(K& num){
    num++;
}

int main(){


    int number[] = {0,1,2,3};


    std::cout << "Before iter:" << std::endl;
    for (int i = 0; i < 4;i++)
        std::cout << number[i] << std::endl;

    iter(number, 4, inc<int>);

    std::cout << "After iter:" << std::endl;
    for (int i = 0; i < 4;i++)
        std::cout << number[i] << std::endl;

    return 0;
}