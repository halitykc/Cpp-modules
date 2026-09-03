

#include "ScalarConverter.hpp"


static bool isSpecialLiteral(const std::string &text) {
    std::string ex_literals[3] = {"nan", "+inf", "-inf"};
    std::string ex_scien_literals[3] = {"nanf", "+inff", "-inff"};
   
    for (int i = 0; i < 3; i++)
    {
        if (text == ex_literals[i] || text == ex_scien_literals[i])
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << ex_scien_literals[i] << std::endl;
            std::cout << "double: " << ex_literals[i] << std::endl;

            return true;
        }
    }
    return false;
}

static bool isChar(const std::string &text) {
    if (text.length() == 1 && !isdigit(text[0]))
        return true;
    return false;
}


void ScalarConverter::convert(std::string &text) {

    if (isSpecialLiteral(text))
        return;

    // Char
    if (isChar(text))
    {
        std::cout << "char: '" << text[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(text[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(text[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(text[0]) << std::endl;
    }
    
    // int
    // float
    // double


}
