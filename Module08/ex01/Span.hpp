#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span{
public:
	Span();
	~Span();
	Span(unsigned int n);
	Span(Span const &other);

	Span &operator=(Span const &other);
	std::vector<int> get_vec() const;
	void	addNumber(int nb);
	int		shortestSpan();
	int		longestSpan();
	void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
private:
	unsigned int	 N;
	std::vector<int> _vec;
};

#endif