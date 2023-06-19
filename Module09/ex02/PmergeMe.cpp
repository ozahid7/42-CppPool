#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_mr_lonly = -1;
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	*this = other;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	_mr_lonly = other._mr_lonly;
	_vec = other._vec;
	return (*this);
}

ConVec PmergeMe::get_vec() const
{
	return _vec;
}

void PmergeMe::set_vec(ConVec vec)
{
	_vec = vec;
}

int PmergeMe::get_mr_lonly() const
{
	return _mr_lonly;
}


int is_it_digits(std::string str)
{
	for (size_t j = 0; j < str.size(); j++){
		if (!std::isdigit(str[j]))
			return (1);
	}
	return (0);
}

std::string trim_spaces(std::string str){
	while(1){
		if (std::isspace(str.front()))
			str.erase(0, 1);
		if (std::isspace(str.back()))
			str.erase(str.length() - 2, str.length() - 1);
		else if(!std::isspace(str.front()) && !std::isspace(str.back()))
			break;
	}
	return (str);
}

void PmergeMe::pair_me(int ac, char **av){
	std::string first;
	std::string second;
	int fst;
	int sec = -1;
	bool mode = false;

	std::stringstream ss;
	if (ac == 1)
			throw std::invalid_argument("Invalid Arguments");
	if (ac % 2 == 0)
		mode = true;
	for (int i = 1; i < ac; i += 2){
		first = av[i];
		if (av[i + 1])
			second = av[i + 1];
		first = trim_spaces(first);
		second = trim_spaces(second);
		if (is_it_digits(first) || is_it_digits(second))
			throw std::invalid_argument("Invalid Element");
		ss << first;
		ss >> fst;
		if (ss.fail())
			throw std::out_of_range("Invalid Element");
		ss.clear();
		ss << second;
		ss >> sec;
		if (ss.fail() && sec != -1)
			throw std::out_of_range("Invalid Element");
		ss.clear();
		if (sec > fst)
			std::swap(fst, sec);
		if (i != ac - 1)
			_vec.push_back(std::make_pair(fst, sec));
		if (mode)
			_mr_lonly = fst;

	}
}

bool compare_pair(std::pair<int, int> first, std::pair<int, int> second){
	return (first.first > second.first);
}



ConVec PmergeMe::sort_pairs(size_t size)
{
	ConVec::iterator it = _vec.begin();
	int tmp;
	
	if (size == _vec.size())
		return _vec;
	tmp = it->first;
	for (size_t i = 0; i < _vec.size(); i++){
		if (tmp > (it + 1)->first){
			std::swap(*it, *(it + 1));
		}
		else
			it++;
	}
	size++;
	sort_pairs(size);
	return _vec;
}


