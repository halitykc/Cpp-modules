
#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>


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

    year = std::atoi(date.substr(0, 4).c_str());
    month = std::atoi(date.substr(5, 2).c_str());
    day = std::atoi(date.substr(8, 2).c_str());

    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[12] ={31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    if (month == 2 && leap_year(year))
        daysInMonth[1] = 29;
    
    return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::leap_year(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool    BitcoinExchange::value_control(const std::string &value, double &result) const
{
    const char *num = value.c_str();
    
    if (*num == '\0')
    return false;
    
    char *endptr = NULL;
    result = std::strtod(num, &endptr);
    if (endptr == num)
        return false;

    while ( *endptr == ' ' || *endptr == '\t')
        ++endptr;
    if (*endptr != '\0')
        return false;
    if (result < 0.0 || result > 1000.0)
        return false;

    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {

    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open database file: " << filename << std::endl;
        return;
    }
    int line_num = 0;
    while (std::getline(file, line)) {
        if (line_num == 0) {
            line_num++;
            continue;
        }
        std::string::size_type comma_pos = line.find(',');
        if (comma_pos == std::string::npos)
            continue;
        std::string date = rm_spaces(line.substr(0, comma_pos));
        std::string value_str = rm_spaces(line.substr(comma_pos + 1));
        double coin_value = 0.0;

        if(!date_control(date))
            continue;
        if(!value_control(value_str, coin_value))
            continue;
        _database[date] = coin_value;

        if (_database.empty())
            throw std::runtime_error("Error: Database is empty or invalid.");
    }

}

std::string BitcoinExchange::rm_spaces(const std::string& text) const
{
    std::string::size_type start = 0;
    std::string::size_type end = text.size();

    while (start < end && (text[start] == ' ' || text[start] == '\t'))
        ++start;
    while (end > start && (text[end - 1] == ' ' || text[end - 1] == '\t'))
        --end;
    return text.substr(start, end - start);
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
        std::cerr << "Error: bad input =>" << date << std::endl;
        return;
    }
    if (!value_control(value_str, coin_value))
    {
        char *endptr = NULL;
        double value = std::strtod(value_str.c_str(), &endptr);
        while (*endptr == ' ' || *endptr == '\t')
            ++endptr;
        if (endptr != value_str.c_str() && value > 1000.0)
            std::cerr << "Error: too large a number." << std::endl;
        else if (value < 0.0)
            std::cerr << "Error: not a positive number." << std::endl;
        else
            std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
    if (it == _database.end() || (it->first != date && it == _database.begin()))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    if (it->first != date)
        --it;
    std::cout << date << " => " << coin_value << " = " << (coin_value * it->second) << std::endl;

}

void BitcoinExchange::execute(const std::string& inputFile) {

    std::ifstream file(inputFile.c_str());
    std::string line;

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    
    loadDatabase("data.csv");

    if (!std::getline(file, line) || rm_spaces(line) != "date | value") {
        throw std::runtime_error("Error: Invalid header in input file.");
    }

    while (std::getline(file, line)) {
        if (!line.empty())
            processLine(line);
    }
}

