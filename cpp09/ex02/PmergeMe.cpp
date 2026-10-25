
#include "PmergeMe.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>






void    PmergeMe::start() const {

    std::vector<PmergeItem> vecInput;
    std::vector<PmergeItem> vecSorted;
    std::vector<PmergeItem> dqInput;
    std::vector<PmergeItem> dqSorted;
    std::size_t i;
    struct timespec start;
    struct timespec end;
    double vecTime;
    double dqTime;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < _input.size(); i++)
        vecInput.push_back(PmergeItem(_input[i], static_cast<unsigned int>(i)));
    vecSorted = fordJohnsonVec(vecInput);
    clock_gettime(CLOCK_MONOTONIC, &end);
    


}