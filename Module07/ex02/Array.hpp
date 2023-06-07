#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array{
	private:
		T				*_array;
		unsigned int	_size;
	public:
	Array();
	Array(unsigned int n);
	Array (Array &other);

	Array &operator=(Array const &other);
	T &operator[](unsigned int index);

};
#endif

template <typename T>
Array<T>::Array()
{
	_array = new T;
	_size = 1;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_array = new T[n];
}

template <typename T>
Array<T>::Array(Array &other)
{
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	_array = new T[other._size];
	_size = other._size;
	for(unsigned int i = 0; i < _size; i++){
		_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return (_array[index]);
}