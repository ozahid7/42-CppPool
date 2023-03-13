#ifndef CHANGE_HPP
#define CHANGE_HPP

#include <iostream>

class Change{
private:
	std::string _src;
	std::string _change;
public:
	Change();
	Change(std::string src, std::string change);
	
};

#endif