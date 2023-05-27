#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>

class Serializer{
public:

	Serializer &operator=(Serializer const &other);
	uintptr_t serialize(Data *ptr);
	Data *deserialize(uintptr_t raw);
private:
	Serializer();
	Serializer(Serializer const &other);
	~Serializer();
};

#endif