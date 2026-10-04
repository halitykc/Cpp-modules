

#include "RPN.hpp"


RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
    (void)other;
}

RPN& RPN::operator=(const RPN& other)
{
    (void)other;
    return *this;
}

RPN::~RPN()
{
}

bool RPN::isOp(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

long long RPN::doOp(long long l, long long r, char op) {

    if (op == '+')
        return l + r;
    else if (op == '-')
        return l - r;
    else if (op == '*')
        return l * r;
    else if (op == '/')
    {
        if (r == 0)
            throw std::runtime_error("Error");
        return l / r;
    }
    else
        throw std::runtime_error("Error: Invalid operator");
    
}


long long RPN::calculate(std::string &expr)
{
    std::stack<long long> stack;
    std::istringstream input(expr);
    std::string argument;

    while (input >> argument) {
        if (argument.size() == 1 && isdigit(argument[0]))
            stack.push(static_cast<long long>(argument[0] - '0'));
        else if (argument.size() == 1 && isOp(argument[0]))
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
            long long r = stack.top();
            stack.pop();
            long long l = stack.top();
            stack.pop();
            stack.push(doOp(l, r, argument[0]));
        }
            
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    return stack.top();

}
