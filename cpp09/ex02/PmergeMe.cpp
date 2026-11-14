/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 08:42:33 by hyakici           #+#    #+#             */
/*   Updated: 2026/11/14 08:53:49 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>

PmergeItem::PmergeItem()
    : value(0), id(0)
{
}

PmergeItem::PmergeItem(unsigned int v, unsigned int i)
    : value(v), id(i)
{
}

PmergeItem::PmergeItem(const PmergeItem& other)
    : value(other.value), id(other.id)
{
}

PmergeItem& PmergeItem::operator=(const PmergeItem& other)
{
    if (this != &other)
    {
        value = other.value;
        id = other.id;
    }
    return *this;
}

PmergeItem::~PmergeItem()
{
}

PmergePair::PmergePair(const PmergeItem& s, const PmergeItem& l)
    : small(s), large(l)
{
}

PmergePair::PmergePair(const PmergePair& other)
    : small(other.small), large(other.large)
{
}

PmergePair& PmergePair::operator=(const PmergePair& other)
{
    if (this != &other)
    {
        small = other.small;
        large = other.large;
    }
    return *this;
}

PmergePair::~PmergePair()
{
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _input(other._input)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
        _input = other._input;
    return *this;
}

PmergeMe::~PmergeMe()
{
}

static double elapsedMicroseconds(const struct timespec& start, const struct timespec& end)
{
    return static_cast<double>(end.tv_sec - start.tv_sec) * 1000000.0 + static_cast<double>(end.tv_nsec - start.tv_nsec) / 1000.0;
}

bool PmergeMe::parseNum(const std::string& text, unsigned int& value)
{
    char* end = 0;
    unsigned long num;
    std::string::size_type i = 0;

    if (text.empty())
        return false;
    while (i < text.size())
    {
        if (text[i] < '0' || text[i] > '9')
            return false;
        ++i;
    }

    errno = 0;
    num = std::strtoul(text.c_str(), &end, 10);
    if (errno == ERANGE || end == text.c_str() || *end != '\0')
        return false;
    if (num == 0 || num > static_cast<unsigned long>(UINT_MAX))
        return false;

    value = static_cast<unsigned int>(num);
    return true;
}

std::size_t PmergeMe::binaryPosition(const std::vector<PmergeItem>& chain, const PmergeItem& item, std::size_t end)
{
    std::size_t left = 0;
    std::size_t right = end;

    while (left < right)
    {
        std::size_t middle = left + (right - left) / 2;
        if (chain[middle].value < item.value)
            left = middle + 1;
        else
            right = middle;
    }
    return left;
}

std::size_t PmergeMe::binaryPosition(const std::deque<PmergeItem>& chain, const PmergeItem& item, std::size_t end)
{
    std::size_t left = 0;
    std::size_t right = end;

    while (left < right)
    {
        std::size_t middle = left + (right - left) / 2;
        if (chain[middle].value < item.value)
            left = middle + 1;
        else
            right = middle;
    }
    return left;
}

std::vector<PmergeItem> PmergeMe::fordJohnsonVector(const std::vector<PmergeItem>& items)
{
    if (items.size() <= 1)
        return items;

    std::vector<PmergePair> pairs;
    std::vector<PmergePair> orderedPairs;
    std::vector<PmergeItem> largenums;
    std::vector<PmergeItem> final_lst;
    std::vector<std::size_t> slot;
    std::size_t max_id = 0;
    std::size_t pendings;
    std::size_t previous = 1;
    std::size_t current = 3;
    std::size_t i;

    for (i = 0; i + 1 < items.size(); i += 2)
    {
        if (items[i].value <= items[i + 1].value)
            pairs.push_back(PmergePair(items[i], items[i + 1]));
        else
            pairs.push_back(PmergePair(items[i + 1], items[i]));
        largenums.push_back(pairs.back().large);
        if (pairs.back().large.id > max_id)
            max_id = pairs.back().large.id;
    }

    final_lst = fordJohnsonVector(largenums);

    slot.assign(max_id + 1, 0);
    for (i = 0; i < pairs.size(); ++i)
        slot[pairs[i].large.id] = i;

    for (i = 0; i < final_lst.size(); ++i)
        orderedPairs.push_back(pairs[slot[final_lst[i].id]]);

    final_lst.insert(final_lst.begin(), orderedPairs[0].small);

    pendings = orderedPairs.size() + (items.size() % 2);

    while (previous < pendings)
    {
        std::size_t maxrange = current < pendings ? current : pendings;
        std::size_t index;

        for (index = maxrange; index > previous; --index)
        {
            std::size_t k = index - 1;
            PmergeItem item;
            std::size_t bound;

            if (k < orderedPairs.size())
            {
                item = orderedPairs[k].small;
                bound = k + 1;
                while (final_lst[bound].id != orderedPairs[k].large.id)
                    ++bound;
            }
            else
            {
                item = items.back();
                bound = final_lst.size();
            }
            final_lst.insert(final_lst.begin() + binaryPosition(final_lst, item, bound), item);
        }
        std::size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return final_lst;
}

std::deque<PmergeItem> PmergeMe::fordJohnsonDeque(const std::deque<PmergeItem>& items)
{
    if (items.size() <= 1)
        return items;

    std::deque<PmergePair> pairs;
    std::deque<PmergePair> orderedPairs;
    std::deque<PmergeItem> largenums;
    std::deque<PmergeItem> final_lst;
    std::deque<std::size_t> slot;
    std::size_t max_id = 0;
    std::size_t pendings;
    std::size_t previous = 1;
    std::size_t current = 3;
    std::size_t i;

    for (i = 0; i + 1 < items.size(); i += 2)
    {
        if (items[i].value <= items[i + 1].value)
            pairs.push_back(PmergePair(items[i], items[i + 1]));
        else
            pairs.push_back(PmergePair(items[i + 1], items[i]));
        largenums.push_back(pairs.back().large);
        if (pairs.back().large.id > max_id)
            max_id = pairs.back().large.id;
    }

    final_lst = fordJohnsonDeque(largenums);

    slot.assign(max_id + 1, 0);
    for (i = 0; i < pairs.size(); ++i)
        slot[pairs[i].large.id] = i;

    for (i = 0; i < final_lst.size(); ++i)
        orderedPairs.push_back(pairs[slot[final_lst[i].id]]);

    final_lst.insert(final_lst.begin(), orderedPairs[0].small);

    pendings = orderedPairs.size() + (items.size() % 2);

    while (previous < pendings)
    {
        std::size_t maxrange = current < pendings ? current : pendings;
        std::size_t index;

        for (index = maxrange; index > previous; --index)
        {
            std::size_t k = index - 1;
            PmergeItem item;
            std::size_t bound;

            if (k < orderedPairs.size())
            {
                item = orderedPairs[k].small;
                bound = k + 1;
                while (final_lst[bound].id != orderedPairs[k].large.id)
                    ++bound;
            }
            else
            {
                item = items.back();
                bound = final_lst.size();
            }
            final_lst.insert(final_lst.begin() + binaryPosition(final_lst, item, bound), item);
        }
        std::size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return final_lst;
}

void PmergeMe::displayVector(const std::vector<PmergeItem>& values)
{
    std::size_t i;
    for (i = 0; i < values.size(); ++i)
    {
        if (i != 0)
            std::cout << ' ';
        std::cout << values[i].value;
    }
    std::cout << std::endl;
}

void PmergeMe::parseArgs(int argc, char** argv)
{
    int i;

    if (argc < 2)
        throw std::runtime_error("Error");

    for (i = 1; i < argc; ++i)
    {
        unsigned int value = 0;
        if (!parseNum(argv[i], value))
            throw std::runtime_error("Error");
        _input.push_back(value);
    }
}

void PmergeMe::run() const
{
    std::vector<PmergeItem> vectorInput;
    std::deque<PmergeItem> dequeInput;
    std::vector<PmergeItem> vectorSorted;
    std::deque<PmergeItem> dequeSorted;
    std::size_t i;
    struct timespec start;
    struct timespec end;
    double vectorTime;
    double dequeTime;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < _input.size(); ++i)
        vectorInput.push_back(PmergeItem(_input[i], static_cast<unsigned int>(i)));
    vectorSorted = fordJohnsonVector(vectorInput);
    clock_gettime(CLOCK_MONOTONIC, &end);
    vectorTime = elapsedMicroseconds(start, end);

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < _input.size(); ++i)
        dequeInput.push_back(PmergeItem(_input[i], static_cast<unsigned int>(i)));
    dequeSorted = fordJohnsonDeque(dequeInput);
    clock_gettime(CLOCK_MONOTONIC, &end);
    dequeTime = elapsedMicroseconds(start, end);

    std::cout << "Before: ";
    displayVector(vectorInput);

    std::cout << "After: ";
    displayVector(vectorSorted);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _input.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _input.size() << " elements with std::deque : " << dequeTime << " us" << std::endl;
}
