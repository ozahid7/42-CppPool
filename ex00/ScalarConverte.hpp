#ifndef SCALARCONVERTE_HPP
#define SCALARCONVERTE_HPP


#include <iostream>
#include <sstream>
#include <iomanip>

class ScalarConverte{
public:

	ScalarConverte &operator=(ScalarConverte const &other);

	static void	convert(std::string converted);
	static void show_results(int j, int i, char c, double d, float f, std::string str);
	static bool is_zero1(std::string str, int x);
	static bool is_char(std::string str);
	static bool is_float(std::string str);
	static bool is_double(std::string str);
	static bool is_it_digits(std::string str);
	static void is_pseudo(std::string str);
	static void	cast_int(std::string str);
	static void	cast_char(std::string str);
	static void	cast_float(std::string str);
	static void	cast_double(std::string str);

private:
	ScalarConverte();
	~ScalarConverte();
	ScalarConverte(ScalarConverte const &other);
	static double	d;
	static int		i;
	static float	f;
	static char		c;
};

#endif