#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* tab, unsigned int len, void (*func)(T const & x)){
	for (unsigned int i = 0; i < len; i++){
		func(tab[i]);
	}
}

#endif