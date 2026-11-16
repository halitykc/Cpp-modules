/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:24:01 by hyakici           #+#    #+#             */
/*   Updated: 2026/11/14 09:47:00 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _database(other._database)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::date_control(const std::string& date) const
{
    int year = 0;
    int month = 0;
    int day = 0;

    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
    month = (date[5] - '0') * 10 + (date[6] - '0');
    day = (date[8] - '0') * 10 + (date[9] - '0');

    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && leap_year(year))
        daysInMonth[1] = 29;

    return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::leap_year(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::parse_number(const std::string& s, double& out) const
{
    if (s.empty() || s.find_first_not_of("0123456789.-+") != std::string::npos)
        return false;

    std::istringstream iss(s);
    iss >> out;
    return !iss.fail() && iss.eof();
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
        throw std::runtime_error("Error: Could not open database file: " + filename);

    bool first_line = true;
    while (std::getline(file, line))
    {
        if (first_line)
        {
            first_line = false;
            continue;
        }
        std::string::size_type comma_pos = line.find(',');
        if (comma_pos == std::string::npos)
            continue;

        std::string date = rm_spaces(line.substr(0, comma_pos));
        std::string value_str = rm_spaces(line.substr(comma_pos + 1));
        double price = 0.0;

        if (!date_control(date))
            continue;
        // Fiyatlar için 1000 sınırı YOK; sadece geçerli ve negatif olmayan sayı.
        if (!parse_number(value_str, price) || price < 0.0)
            continue;
        _database[date] = price;
    }

    if (_database.empty())
        throw std::runtime_error("Error: Database is empty or invalid.");
}

std::string BitcoinExchange::rm_spaces(const std::string& text) const
{
    const std::string ws = " \t\r\n";
    std::string::size_type start = text.find_first_not_of(ws);

    if (start == std::string::npos)
        return "";
    std::string::size_type end = text.find_last_not_of(ws);
    return text.substr(start, end - start + 1);
}

void BitcoinExchange::processLine(const std::string& line) const
{
    std::string::size_type pipe_pos = line.find('|');
    if (pipe_pos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date = rm_spaces(line.substr(0, pipe_pos));
    std::string value_str = rm_spaces(line.substr(pipe_pos + 1));
    double coin_value = 0.0;

    if (!date_control(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }
    if (!parse_number(value_str, coin_value))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    if (coin_value < 0.0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    if (coin_value > 1000.0)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }

    // date'e eşit veya ondan önceki en yakın tarih.
    std::map<std::string, double>::const_iterator it = _database.upper_bound(date);
    if (it == _database.begin())
    {
        // date, veritabanındaki ilk tarihten de önce.
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }
    --it;
    std::cout << date << " => " << coin_value << " = " << (coin_value * it->second) << std::endl;
}

void BitcoinExchange::execute(const std::string& inputFile)
{
    std::ifstream file(inputFile.c_str());
    std::string line;

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    loadDatabase("data.csv");

    if (!std::getline(file, line) || rm_spaces(line) != "date | value")
        throw std::runtime_error("Error: Invalid header in input file.");

    while (std::getline(file, line))
    {
        if (!rm_spaces(line).empty())
            processLine(line);
    }
}