#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

public:

	Fixed( void );
	Fixed(const int a);
	Fixed(const float b);
	Fixed(Fixed const & src);
	~Fixed( void );

	Fixed & operator=(Fixed const & rhs);
	Fixed & operator<<(Fixed const & rhs);
	float toFloat( void ) const;
	int toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	
private:
	int _value;
	static const int _fractional = 8;
	
};


#endif