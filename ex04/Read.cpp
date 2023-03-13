#include "Read.hpp"

Read::Read(std::string name){
	_name = name;
}

void Read::setbuffer(std::string buffer){
	std::fstream file;
	file.open("main.cpp", std::ios::in);
	if (file.is_open()){
		while (getline(file, buffer, '\0')){
			setbuffer(buffer);
			//getbuffer();
		}
	}else{
		std::cout<<"File Not Opned"<<std::endl;
	}
}

std::string Read::getbuffer(){
	std::cout<<_buffer<<std::endl;
	return _buffer;
}
