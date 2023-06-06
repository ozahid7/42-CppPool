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

	T &operator=(Array const &other);
	T &operator[](unsigned int index);

};
#endif

template <typename T>
Array<T>::Array()
{
	T _array = new T;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	T * a = new T[n];
}

template <typename T>
Array<T>::Array(Array &other)
{
	*this = other;
}

template <typename T>
T &Array<T>::operator=(Array const &other)
{
	for(int i = 0; i < _size; i++){
		_array[i] == other._array[i];
	}
	_size = other._size;
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range();
	else
		_array = new T[index];
}