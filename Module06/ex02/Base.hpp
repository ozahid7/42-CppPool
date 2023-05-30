#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <exception>

class Base{
	public:

	virtual ~Base();
	virtual void whoami(){
		std::cout<<"I swear im Base"<<std::endl;
	}
};
Base  *generate(void);	
void identify(Base* p);
void identify(Base& p);

class A: public Base{
	public:
	void whoami(){
		std::cout<<" I swear im A "<<std::endl;
	}
};

class B: public Base{
	public:
	void whoami(){
		std::cout<<" I swear im B "<<std::endl;
	}
};

class C: public Base{
	public:
	void whoami(){
		std::cout<<" I swear im C "<<std::endl;
	}

};

#endif