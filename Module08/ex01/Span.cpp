#include "Span.hpp"

Span::Span()
{
	N = 0;
}

Span::~Span()
{
}

Span::Span(unsigned int n)
{
	N = n;
}

Span::Span(Span const &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	N = other.N;
	return (*this);	
}

std::vector<int> Span::get_vec() const
{
	return _vec;
}

void Span::addNumber(int nb)
{
	if (_vec.size() >= N)
		throw std::length_error("No more space");
	_vec.push_back(nb);
}

int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw std::length_error("Invalid Size");
	std::sort(_vec.begin(), _vec.end());
	int shortspan = INT_MAX;
	int span = INT_MAX;
	int size = _vec.size() - 1;
	for (; size > 0; size--)
	{
		span = _vec[size] - _vec[size - 1];
		if(span < shortspan)
			shortspan = span;
	}
	return shortspan;
}

int Span::longestSpan()
{
	if (_vec.size() < 2)
		throw std::length_error("Invalid Size");
	std::vector<int>::iterator it;
	it = std::min_element(_vec.begin(), _vec.end());
	int min = *it;
	it = std::max_element(_vec.begin(), _vec.end());
	int max = *it;
	return (max - min);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if ((unsigned long)(end - begin) > (N - _vec.size()))
		throw std::length_error("Invalid Range");
	_vec.insert(_vec.end(), begin, end);
}
