#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *tab, T len, void print_msg()){
	int i;

	i = 0;
	while (i < len)
	{
		print_msg();
		i++;
	}
}

#endif