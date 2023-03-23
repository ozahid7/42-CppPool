#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
	Fixed	&operator++(int);
	Fixed	&operator--();
	Fixed	&operator--(int);

//###########################################

	static int min(int &a, int &b);
	static int min(int &a, int &b, int);
	static int max(int &a, int &b);
	static int max(int &a, int &b, int);

//###########################################

	Fixed( void );
	Fixed(const float b);
	Fixed(Fixed const & src);
	~Fixed( void );

	Fixed & operator=(Fixed const & other);
	
private:
	int _value;
	static const int _fractional = 8;

};


#endif