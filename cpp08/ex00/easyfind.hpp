


#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>


class CoulndNotFindException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Value Doesn't Exist.";
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int val ) {

    typename T::iterator iter = std::find(container.begin(), container.end(), val);
    if (iter == container.end())
        throw CoulndNotFindException();
    return iter;
}





#endif