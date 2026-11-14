/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:23:57 by hyakici           #+#    #+#             */
/*   Updated: 2026/11/14 09:04:34 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <stack>
#include <sstream>
#include <climits>

class RPN
{
    public: 
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

    bool isOp(char c) const;
    long doOp(long l, long r, char op);

    long calculate( const std::string &expr);

};
#endif
