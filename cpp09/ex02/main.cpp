

#include "PmergeMe.hpp"

#include <iostream>
#include <stdexcept>


int main(int argc, char **argv) {

    try {
        PmergeMe sort;
        sort.parseArgs(argc, argv);
        sort.start();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
