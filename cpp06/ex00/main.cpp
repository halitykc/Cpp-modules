

#include "ScalarConverter.hpp"
#include <iostream>


int main() {

    ScalarConverter::convert("nan");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inff");



    
    return 0;
}