


#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>

class RPN
{
    public: 
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

    bool isOp(char c) const;
    long long doOp(long long l, long long r, char op);

    long long calculate(std::string &expr);

};
#endif
