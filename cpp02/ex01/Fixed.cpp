

#include    "Fixed.hpp"


Fixed::Fixed( void ) {

    this->_fixedpoint = 0;
    std::cout << "Default Constructor called " << std::endl;
}

Fixed::Fixed( const Fixed &other) {

    std::cout << "Copy constructor called " << std::endl;
    this->_fixedpoint = other._fixedpoint;
}

Fixed& Fixed::operator=( const Fixed &other) {

    std::cout << "Copy assignment operator called " << std::endl;
    if (this != &other)
        this->_fixedpoint = other._fixedpoint;
    
    return (*this);
}

Fixed::~Fixed( void ) {

    std::cout << "Destructor called" << std::endl;
}


int     Fixed::getRawBits( void ) const {

    std::cout << "getRawBits member function called" << std::endl;
    return ( this->_fixedpoint );
}

void    Fixed::setRawBits( int const raw ) {

    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedpoint = raw;
}

Fixed::Fixed( int const value ) {

    std::cout << "Int constructor called" << std::endl;
    this->_fixedpoint = value << this->_fractialbits;
}

Fixed::Fixed( float const value) {

    this->_fixedpoint = roundf(value * (1 << this->_fractialbits));
    std::cout << "Float constructor called" << std::endl;
}


float   Fixed::toFloat( void ) const {

    return ( (float)this->_fixedpoint / ( 1 << this->_fractialbits ) );
}

int     Fixed::toInt( void ) const {

    return  ( this->_fixedpoint >> this->_fractialbits );
}

std::ostream &operator<<(std::ostream   &stream, const Fixed &num) {

    stream << num.toFloat();
    return ( stream );
}
