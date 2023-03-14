#include "Replace.hpp"


Read::Read(std::string name, std::string src, std::string change){
	_name = name;
	_src = src;
	_change = change;
}

void Read::readit(){
	std::fstream file(_name);
	size_t pos;
	std::string buffer;
	if (file.is_open()){
		std::ofstream replaced(_name  + ".replace", std::ios::out);
		getline(file, buffer, '\0');
		pos = buffer.find(_src);
		if (pos != std::string::npos){
			while (pos != std::string::npos){
				buffer.erase(pos, _src.length());
				buffer.insert(pos, _change);
				pos = buffer.find(_src, pos + _change.length());

			}
			if (replaced.is_open()){
				replaced << buffer;
			}else{std::cerr<<"Replaced File Not Opned"<<std::endl;}
		}else{std::cerr<<"Word Not Founded"<<std::endl;}
	}else{
		std::cerr<<"File Not Opned"<<std::endl;
	}
}
