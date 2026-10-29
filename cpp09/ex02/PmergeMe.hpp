#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <string>
#include <vector>

struct PmergeItem
{
    unsigned int value;
    unsigned int id;

    PmergeItem();
    PmergeItem(unsigned int v, unsigned int i);
    PmergeItem(const PmergeItem& other);
    PmergeItem& operator=(const PmergeItem& other);
    ~PmergeItem();
};

struct PmergePair
{
    PmergeItem small;
    PmergeItem large;

    PmergePair(const PmergeItem& s, const PmergeItem& l);
    PmergePair(const PmergePair& other);
    PmergePair& operator=(const PmergePair& other);
    ~PmergePair();
};

class PmergeMe
{
    private:
        std::vector<unsigned int> _input;

        static bool parseNum(const std::string& text, unsigned int& value);

        static std::size_t binaryPosition(const std::vector<PmergeItem>& chain, const PmergeItem& item, std::size_t end);
        static std::size_t binaryPosition(const std::deque<PmergeItem>& chain, const PmergeItem& item, std::size_t end);

        static std::vector<PmergeItem> fordJohnsonVector(const std::vector<PmergeItem>& items);
        static std::deque<PmergeItem> fordJohnsonDeque(const std::deque<PmergeItem>& items);

        static void displayVector(const std::vector<PmergeItem>& values);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void parseArguments(int argc, char** argv);
        void run() const;
};

#endif