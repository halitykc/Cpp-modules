

#include "Fixed.hpp"


Fixed::Fixed( void ) {

    this->_fixedpoint = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other) {
    
    std::cout << "Copy constructor called" << std::endl;

    this->_fixedpoint = other._fixedpoint;
}

Fixed& Fixed::operator=( const Fixed &other) {

    std::cout << "Copy assignement operator called" << std::endl;

    if (this != &other)
        this->_fixedpoint = other._fixedpoint;
    return (*this);
}

Fixed::~Fixed( void ) {

    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const {

    std::cout << "getRawBits member function called" << std::endl;

    return (this->_fixedpoint);
}

void    Fixed::setRawBits( int const raw ) {

    std::cout << "setRawbits member function called" << std::endl;

    this->_fixedpoint = raw;
}