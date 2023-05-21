#ifndef SCALARCONVERTE_HPP
#define SCALARCONVERTE_HPP


#include <iostream>

class ScalarConverte{
public:
	ScalarConverte();
	~ScalarConverte();
	ScalarConverte(ScalarConverte const &other);

	ScalarConverte &operator=(ScalarConverte const &other);

	void	convert(std::string converted);
private:
};

#endif