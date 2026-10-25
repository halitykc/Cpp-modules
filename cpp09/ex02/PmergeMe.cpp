
#include "PmergeMe.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>


PmergeItem::PmergeItem() : value(0), id(0) {}

PmergeItem::PmergeItem(unsigned int value, unsigned int i) : value(v), id(i) {}

PmergeItem::PmergeItem(const PmergeItem& other) : value(other.value), id(other.id) {}

PmergeItem& PmergeItem::operator=(const PmergeItem& other) {
    
    if (this != &other)
    {
        value = other.value;
        id = other.id;
    }
    return *this;
}

PmergeItem::~PmergeItem() {}

PmergePair::PmergePair(const PmergeItem& s, const PmergeItem& l): small(s), large(l) {}

PmergePair::PmergePair(const PmergePair& other): small(other.small), large(other.large) {}

PmergePair& PmergePair::operator=(const PmergePair& other) {
    
    if (this != &other)
    {
        small = other.small;
        large = other.large;
    }
    return *this;
}

PmergePair::~PmergePair() {}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other): _input(other._input) {}

PmergeMe::PmergeMe(const PmergeMe& other) {

    if (this != &other)
        _input = other._input;

    return *this;
}

PmergeMe::~PmergeMe() {}


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