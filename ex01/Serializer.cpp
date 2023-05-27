#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &other)
{
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(Serializer const &other)
{
	// TODO: insert return statement here
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return uintptr_t();
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return nullptr;
}
