#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>


template<typename T>
std::vector<int>::iterator easyfind(T a, int i){
	typename T::iterator it = std::find(a.begin(), a.end(), i);
	if (it != a.end())
		return (it);
	throw (std::runtime_error("Number not found"));
}

#endif