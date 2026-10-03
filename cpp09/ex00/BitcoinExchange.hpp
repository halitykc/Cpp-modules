

#ifndef BTCOINEXCHANGE_HPP
#define BTCOINEXCHANGE_HPP


#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;

        bool date_control(const std::string& date) const;
        bool leap_year(int year) const;
        bool value_control(const std::string &value, double &result) const;
        std::string rm_spaces(const std::string &str) const;
        void loadDatabase(const std::string& filename);
        void processLine(const std::string& line) const;

     public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void run(const std::string& inputFile);

};


#endif
