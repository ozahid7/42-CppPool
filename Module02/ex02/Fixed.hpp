#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed {

public:

//comparison operators

	bool	operator==(Fixed const & other);
	bool	operator<=(Fixed const & other);
	bool	operator>=(Fixed const & other);
	bool	operator>(Fixed const & other);
	bool	operator<(Fixed const & other);
	bool	operator!=(Fixed const & other);

//arithmetic operators

	Fixed	&operator+(Fixed const &other);
	Fixed	&operator-(Fixed const &other);
	Fixed	&operator*(Fixed const &other);
	Fixed	&operator/(Fixed const &other);

//increment operators

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

//###########################################

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);

//###########################################

	Fixed( void );
	Fixed(const int a);
	Fixed(const float b);
	Fixed(Fixed const & src);
	~Fixed( void );

	Fixed & operator=(Fixed const & other);

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	
private:
	int _integer;
	static const int _fractional = 8;

};
	std::ostream & operator<<(std::ostream & stream, const Fixed &fixed);

#endif