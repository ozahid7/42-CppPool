#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
struct Data{
	int i;
};
class Serializer{
public:

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
	
	Serializer &operator=(Serializer  &other);
private:
	Serializer();
	Serializer(Serializer  &other);
	~Serializer();
};

#endif