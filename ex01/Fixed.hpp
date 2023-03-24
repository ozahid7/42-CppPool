#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <sstream>
#include <cmath>

class Fixed {

public:

	Fixed( void );
	Fixed(const int a);
	Fixed(const float b);
	Fixed(Fixed const & src);
	~Fixed( void );

	Fixed & operator=(Fixed const & rhs);
	float	toFloat( void ) const;
	int		toInt( void ) const;
	
private:
	int _integer;
	static const int _fractional = 8;
	
};
	std::ostream & operator<<(std::ostream & stream, const Fixed &fixed);


#endif