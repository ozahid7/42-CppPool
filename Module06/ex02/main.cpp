#include "Base.hpp"

int main(){
	Base *base = new Base;
	base = generate();
	identify(base);
	identify(*base);
}