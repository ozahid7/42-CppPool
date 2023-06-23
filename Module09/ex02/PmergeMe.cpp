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

std::vector<int> PmergeMe::get_pend()
{
	return pend;
}

std::vector<int> PmergeMe::get_main()
{
	return main;
}

ConVec PmergeMe::sort_pairs()
{
	ConVec::iterator it;
	bool 			flag = false;
	for (it = _vec.begin(); it < _vec.end() - 1; it++)
	{
		if (it->first > (it + 1)->first){
			std::swap(*it, *(it + 1));
			flag = true;
		}
	}
	if (flag == false)
		return (_vec);
	sort_pairs();
	return (_vec);
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
	int tmp;
	bool mode = false;

	std::stringstream ss;
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
		tmp = fst;
		if (sec > fst)
			std::swap(fst, sec);
		if (i != ac - 1){
			before.push_back(fst);
			before.push_back(sec);
			_vec.push_back(std::make_pair(fst, sec));
		}
		if (mode)
			_mr_lonly = tmp;
	}
}

int jacobsthal(int n) {
    int a = 0;
    int b = 1;

    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    }

    int result;

    for (int i = 2; i <= n; ++i) {
        result = 2 * a + b;
        a = b;
        b = result;
    }

    return result;
}

void PmergeMe::separate_pair()
{
	ConVec::iterator it;
	for (it = _vec.begin(); it < _vec.end(); it++){
		main.push_back(it->first);
		pend.push_back(it->second);
	}
	if (!pend.empty()){
		main.insert(main.begin(), *pend.begin());
	}
}

std::vector<size_t> PmergeMe::make_jacob()
{
	std::vector<size_t> vec;
	std::vector<size_t> tmp;
	size_t jacob = 0;
	size_t i = 3;
	int j = 1;
	size_t a;
	size_t prev = INT64_MAX;
	
	vec.push_back(1);
	tmp.push_back(1);
	while (i <= pend.size()){
		jacob = jacobsthal(i);
		if (jacob > pend.size()){
			vec.push_back(jacob);
			break;
		}
		vec.push_back(jacob);
		tmp.push_back(jacob);
		prev = tmp[j - 1];
		a = jacob;
		while(--a > prev)
			vec.push_back(a);
		i++;
		j++;
	}
	jacob--;
	size_t size = vec.size();
	while(size < pend.size()){
		vec.push_back(jacob);
		jacob--;
		size++;
	}

	return (vec);
}



void PmergeMe::binary_insert()
{
	std::vector<size_t> vec;
	vec = make_jacob();
	std::vector<int>::iterator it;
	std::vector<int>::iterator it1;
	size_t i = 3;
	for (it = pend.begin() + 2; it <= pend.end(); it++)
	{
		it1 = std::lower_bound(main.begin(), main.end(), *(it - 1));
		main.insert(it1, *(it - 1));
		i++;
	}
	if (_mr_lonly != -1){
		it1 = std::lower_bound(main.begin(), main.end(), _mr_lonly);
		main.insert(it1, _mr_lonly);
	}
}

void PmergeMe::show(std::string str, std::clock_t start)
{
	std::cout<<"Before:  ";
	for(std::vector<int>::iterator it = before.begin(); it < before.end(); it++)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	std::cout<<"After :  ";
	for(std::vector<int>::iterator it = main.begin(); it < main.end(); it++)
		std::cout<<*it<<" ";
	std::clock_t end = clock();
	double duration = (double)(end - start);
	std::cout<<std::endl;
	std::cout<<"Time to process a range of 5 elements with std::"<<str<<" : "<< duration <<" us"<<std::endl; 
}
