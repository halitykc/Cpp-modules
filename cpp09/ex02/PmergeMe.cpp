
#include "PmergeMe.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>


PmergeItem::PmergeItem() : value(0), id(0) {}

PmergeItem::PmergeItem(unsigned int value, unsigned int i) : value(value), id(i) {}

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

PmergePair::PmergePair(const PmergeItem& s, const PmergeItem& l) : small(s), large(l) {}

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

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {

    if (this != &other)
        _input = other._input;

    return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<PmergeItem> PmergeMe::fordJohnsonVec(const std::vector<PmergeItem>& items) {

    if (items.size() <= 1)
        return items;

    std::vector<PmergePair> pairs;
    std::vector<PmergePair> ordered;
    std::vector<PmergeItem> biggerItems;
    std::vector<PmergeItem> main;
    std::size_t maxid = 0;
    std::size_t pendings;
    std::size_t prev = 1;
    std::size_t curr = 3;
    std::size_t i;

    for (i = 0; i + 1 < items.size(); i += 2)
    {
        if (items[i].value <= items[i+1].value)
            pairs.push_back(PmergePair(items[i], items[i+1]));
        else
            pairs.push_back(PmergePair(items[i+1], items[i]));
        biggerItems.push_back(pairs.back().large);
        if(pairs.back().large.id > maxid)
            maxid = pairs.back().large.id;
    }
    
    main = fordJohnsonVec(biggerItems);

}

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