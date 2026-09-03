

#include "ScalarConverter.hpp"
#include <iostream>


int main(int argc, char **argv) {

    if (argc != 2 || argv[1][0] == '\0')
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    //ScalarConverter::convert(text);

    ScalarConverter::convert(std::string(argv[1]));

    
    return 0;
}