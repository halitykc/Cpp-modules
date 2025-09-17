



#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed {

    private:

        int                 _fixedpoint;
        static const int    _fractialbits = 8;

    public:

        Fixed( void );
        Fixed( const Fixed &other );
        Fixed& operator=( const Fixed &other );
        ~Fixed( void );

        Fixed( int const value );
        Fixed( float const value);

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float   toFloat( void ) const;
        int     toInt( void ) const;

        //Comparison ops
        Fixed   operator>( const Fixed& other);
        Fixed   operator<( const Fixed& other);
        Fixed   operator>=( const Fixed& other);
        Fixed   operator<=( const Fixed& other);
        Fixed   operator==( const Fixed& other);
        Fixed   operator!=( const Fixed& other);

        //Arithmetic ops
        Fixed   operator+( const Fixed& other );
        Fixed   operator-( const Fixed& other );
        Fixed   operator*( const Fixed& other );
        Fixed   operator/( const Fixed& other );

};

std::ostream &operator<<(std::ostream   &stream, const Fixed &num);

#endif  