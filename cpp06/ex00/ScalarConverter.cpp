#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}



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

static bool isInt(const std::string &text) {

    size_t i = 0;

    if (text[0] == '-' || text[0] == '+')
        i++;

    if (text.length() == i)
        return false;

    while (i < text.length())
    {
        if (!isdigit(text[i]))
            return false;
        i++;
    }
    return true;
}

static bool isFloat(const std::string &text) {
    if (text[text.length() - 1] != 'f')
        return false;

    char *end;
    std::strtod(text.c_str(), &end);
    return (end == &text[text.length() - 1]);
}

static bool isDouble(const std::string &text) {

    char *end;
    std::strtod(text.c_str(), &end);
    return (*end == '\0' && end != text.c_str());
}

void ScalarConverter::convert(const std::string &text) {

    if (isSpecialLiteral(text))
        return;

    // Char
    if (isChar(text))
    {
        std::cout << "char: '" << text[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(text[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(text[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(text[0]) << ".0" << std::endl;

        return;
    }

    if (isInt(text))
    {
        long value = std::strtol(text.c_str(), NULL, 10);
        if (value < 0 || value > 127) {
            std::cout << "char: impossible" << std::endl;
        }
        else if (!isprint(value)) {
            std::cout << "char: Non displayable" << std::endl;
        }
        else {
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        }
        if (value >= INT_MIN && value <= INT_MAX)
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        if (value < 1000000 && value > -1000000) {
            std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
        } else {
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(value) << std::endl;
        }
        return;
    }

    if (isFloat(text))
    {
        float value = static_cast<float>(std::strtod(text.c_str(), NULL));

        if (value < 0 || value > 127) {
            std::cout << "char: impossible" << std::endl;
        }
        else if (!isprint(static_cast<int>(value))) {
            std::cout << "char: Non displayable" << std::endl;
        }
        else {
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        }
        if (value >= INT_MIN && value <= INT_MAX)
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;


        if (std::fmod(value, 1.0) == 0.0 && value < 1000000.0 && value > -1000000.0)
            std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

        if (std::fmod(value, 1.0) == 0.0 && value < 1000000.0 && value > -1000000.0)
            std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(value) << std::endl;

        return;
    }

    if (isDouble(text))
    {
        double value = std::strtod(text.c_str(), NULL);

        if (value < 0 || value > 127) {
            std::cout << "char: impossible" << std::endl;
        }
        else if (!isprint(static_cast<int>(value))) {
            std::cout << "char: Non displayable" << std::endl;
        }
        else {
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        }
        if (value >= INT_MIN && value <= INT_MAX)
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;

        if (std::fmod(value, 1.0) == 0.0 && value < 1000000.0 && value > -1000000.0)
            std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        if (std::fmod(value, 1.0) == 0.0 && value < 1000000.0 && value > -1000000.0)
            std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(value) << std::endl;

        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}