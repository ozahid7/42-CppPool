#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>


template<typename T, typename Container=std::vector<T> >
class MutantStack: public std::stack<T, Container>{
public:
	MutantStack();
	~MutantStack();
	MutantStack(MutantStack const &other);
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;
	MutantStack &operator=(MutantStack const &other);
		iterator begin(){
		return this->c.begin();
	}
	iterator end(){
		return (this->c.end());
	}
	reverse_iterator rbegin(){
		return this->c.rbegin();
	}
	reverse_iterator rend(){
		return (this->c.rend());
	}
	const_reverse_iterator rcbegin() const{
		return this->c.rcbegin();
	}
	const_reverse_iterator rcend() const{
		return (this->c.rcend());
	}
	const_iterator cbegin() const{
		return (this->c.cbegin());
	}
	const_iterator cend() const{
		return (this->c.cend());
	}



};

#endif

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{
	
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{

}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack const &other)
{
	*this = other;
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack const &other)
{
	(void)other;
	return(*this);
}
