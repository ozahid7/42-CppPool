#include "Base.hpp"

Base::~Base()
{
}

Base *generate(void)
{
	int r;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	r = std::rand();
	Base *base = new Base;
	A *a = new A;
	B *b = new B;
	C *c = new C;
	if (r % 3 == 0)
		base = dynamic_cast<Base *>(a);
	else if (r % 3 == 1)
		base = dynamic_cast<Base *>(b);
	else if (r % 3 == 2)
		base = dynamic_cast<Base *>(c);
	else
		std::cout<<"hhhhhhh\n";
	return (base);
}

void identify(Base *p)
{
	if (dynamic_cast<A *> (p))
		p->whoami();
	else if (dynamic_cast<B *> (p))
		p->whoami();
	else if (dynamic_cast<C *> (p))
		p->whoami();
}

void identify(Base &p)
{
	try{
		C &c = dynamic_cast<C &>(p);
		c.whoami();
	}
	catch(std::exception(&e)){	
		try{
			B &b = dynamic_cast<B &>(p);
			b.whoami();
		}
		catch(std::exception(&e)){
			try{
				A &a = dynamic_cast<A &>(p);
				a.whoami();
			}
			catch(std::exception(&e)){
				std::cout<<e.what()<<std::endl;
			}
		}
	}
}
