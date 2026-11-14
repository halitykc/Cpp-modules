/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:23:54 by hyakici           #+#    #+#             */
/*   Updated: 2026/11/14 09:22:59 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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

long RPN::doOp(long l, long r, char op)
{
    if (op == '+')
    {
        if ((r > 0 && l > LONG_MAX - r) || (r < 0 && l < LONG_MIN - r))
            throw std::runtime_error("Error");
        return l + r;
    }
    else if (op == '-')
    {
        if ((r < 0 && l > LONG_MAX + r) || (r > 0 && l < LONG_MIN + r))
            throw std::runtime_error("Error");
        return l - r;
    }
    else if (op == '*')
    {
        if (l != 0 && r != 0)
        {
            if (l > 0 && r > 0 && l > LONG_MAX / r)
                throw std::runtime_error("Error");
            if (l < 0 && r < 0 && l < LONG_MAX / r)
                throw std::runtime_error("Error");
            if (l > 0 && r < 0 && r < LONG_MIN / l)
                throw std::runtime_error("Error");
            if (l < 0 && r > 0 && l < LONG_MIN / r)
                throw std::runtime_error("Error");
        }
        return l * r;
    }
    else if (op == '/')
    {
        if (r == 0 || (l == LONG_MIN && r == -1))
            throw std::runtime_error("Error");
        return l / r;
    }
    throw std::runtime_error("Error");
}

long RPN::calculate(const std::string &expr)
{
    std::stack<long, std::list<long> > stack;
    std::istringstream input(expr);
    std::string arg;

    while (input >> arg)
    {
        if (arg.size() != 1)
            throw std::runtime_error("Error");

        char c = arg[0];

        if (std::isdigit(static_cast<unsigned char>(c)))
            stack.push(static_cast<long>(c - '0'));
        else if (isOp(c))
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
            long r = stack.top();
            stack.pop();
            long l = stack.top();
            stack.pop();
            stack.push(doOp(l, r, c));
        }
        else
            throw std::runtime_error("Error");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    return stack.top();
}
