#ifndef SCALARCONVERTE_HPP
#define SCALARCONVERTE_HPP


#include <iostream>
#include <sstream>
#include <iomanip>

class ScalarConverte{
public:
	~ScalarConverte();
	ScalarConverte(ScalarConverte const &other);

	ScalarConverte &operator=(ScalarConverte const &other);

	static void	convert(std::string converted);
	void 	show_results(int j, int i, char c, double d, float f, std::string str);
	bool 	is_zero1(std::string str, int x);
	bool 	is_zero2(std::string str);
	bool 	is_char(std::string str);
	bool 	is_float(std::string str);
	bool 	is_double(std::string str);
	bool 	is_it_digits(std::string str);
	void 	is_pseudo(std::string str);
	void	cast_int(std::string str);
	void	cast_char(std::string str);
	void	cast_float(std::string str);
	void	cast_double(std::string str);

private:
	ScalarConverte();
	static double	d;
	static int		i;
	static float	f;
	static char		c;
};

#endif