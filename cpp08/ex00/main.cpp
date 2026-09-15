#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {

    std::cout << "========== Vector ==========" << std::endl;
    std::vector<int> myVector;
    
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);
    myVector.push_back(42);

    try {
        std::vector<int>::iterator it = easyfind(myVector, 42);
        std::cout << "-> FOUND: " << *it << "\n" << std::endl;

        it = easyfind(myVector, 99);
        std::cout << "-> FOUND: " << *it << std::endl;
    }
    catch (const std::exception& e) { 
        std::cerr << e.what() << std::endl;
    }

    std::cout << "========== LIST ==========" << std::endl;
    std::list<int> myList;
    
    myList.push_back(100);
    myList.push_back(200);
    myList.push_back(300);

    try {
        std::list<int>::iterator it2 = easyfind(myList, 200);
        std::cout << "-> FOUND: " << *it2 << "\n" << std::endl;

        it2 = easyfind(myList, 5);
        std::cout << "-> FOUND: " << *it2 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

