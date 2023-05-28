#include "Base.hpp"

Base::~Base()
{
}


Base::Base()
{
}

A::A()
{

}

B::B()
{
}

C::C()
{
}

Base *generate(void)
{
	int r;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	r = std::rand();
	Base *base;
	A a;
	B b;
	C c;
	if (r % 2 == 0)

}

void identify(Base *p)
{
}

void identify(Base &p)
{
}
