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
	uintptr_t t = 4;
	ptr = reinterpret_cast<Data*>(t);
	return (t);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *data = new Data;
	raw = reinterpret_cast<uintptr_t>(data);
	return (data);
}
