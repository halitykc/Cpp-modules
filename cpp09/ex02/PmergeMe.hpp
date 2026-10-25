
#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <cstddef>
#include <deque>
#include <vector>
#include <string>

struct PmergeItem {
    unsigned  int value;
    unsigned  int id;

    PmergeItem();
    PmergeItem(unsigned int value, unsigned int i);
    PmergeItem(const PmergeItem& other);
    PmergeItem& operator=(const PmergeItem& other);
    ~PmergeItem();
};

struct PmergePair {

    PmergeItem small;
    PmergeItem large;

    PmergePair();
    PmergePair(unsigned int s, unsigned int l);
    PmergePair(const PmergePair& other);
    PmergePair& operator=(const PmergePair& other);
    ~PmergePair();
};

class PmergeMe 
{
    private:
        std::vector<unsigned int> _input;
        static bool parseNum(const std::string& text, unsigned int& value);
        static std::size_t binaryPos(const std::vector<PmergeItem>& chain, const PmergeItem& item, std::size_t end);
        static std::vector<PmergeItem> fordJohnsonVec(const std::vector<PmergeItem>& items);
        static std::vector<PmergeItem> fordJohnsonDq(const std::vector<PmergeItem>& items);

        static void dispVec(const std::vector<PmergeItem>& value);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void    parseArgs(int argc, char ** argv);
        void    start() const;
};





#endif