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

	Fixed & operator=(Fixed const & other);
	Fixed & operator<<(Fixed const & other);
	
	float toFloat( void ) const;
	int toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	
private:
	int _value;
	static const int _fractional = 8;

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
};


#endif