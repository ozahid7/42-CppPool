#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer  &other)
{
	*this = other;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(Serializer &other)
{
	// TODO: insert return statement here
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t t;
	t = reinterpret_cast<uintptr_t>(ptr);
	return (t);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *data;
	data = reinterpret_cast<Data *>(raw);
	return (data);
}
