#ifndef READ_HPP
#define READ_HPP

#include <iostream>
#include <fstream>

class Read{
private:
	std::string _buffer;
	std::string _src;
	std::string _change;
	std::string _name;
public:
	Read(std::string name, std::string src, std::string change);
	void	readit();
};

#endif