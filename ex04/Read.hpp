#ifndef READ_HPP
#define READ_HPP

#include <iostream>
#include <fstream>

class Read{
private:
	std::string _buffer;
	std::string _name;
public:
	Read(std::string name);
	void	setbuffer(std::string buffer);
	std::string	getbuffer();
};

#endif