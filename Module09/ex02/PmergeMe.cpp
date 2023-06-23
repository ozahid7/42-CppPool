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

ConVec PmergeMe::v_get_vec() const
{
	return _vec;
}

Condec PmergeMe::d_get_vec() const
{
	return _dec;
}

void PmergeMe::v_set_vec(ConVec vec)
{
	_vec = vec;
}

void PmergeMe::d_set_vec(Condec vec)
{
	_dec = vec;
}

std::vector<int> PmergeMe::v_get_pend()
{
	return v_pend;
}

std::deque<int> PmergeMe::d_get_pend()
{
	return d_pend;
}

std::vector<int> PmergeMe::v_get_main()
{
	return v_main;
}
std::deque<int> PmergeMe::d_get_main()
{
	return d_main;
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

void PmergeMe::v_pair_me(int ac, char **av){
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
		if (ac == 2){
			v_main.push_back(fst);
			v_before.push_back(fst);
		}
		if (i != ac - 1)
		{
			v_before.push_back(fst);
			v_before.push_back(sec);
		}
		if (sec > fst)
			std::swap(fst, sec);
		if (i != ac - 1)
			_vec.push_back(std::make_pair(fst, sec));
		if (mode)
			_mr_lonly = tmp;
	}
}

ConVec PmergeMe::v_sort_pairs()
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
	v_sort_pairs();
	return (_vec);
}

void PmergeMe::v_separate_pair()
{
	ConVec::iterator it;
	for (it = _vec.begin(); it < _vec.end(); it++){
		v_main.push_back(it->first);
		v_pend.push_back(it->second);
	}
	if (!v_pend.empty()){
		v_main.insert(v_main.begin(), *v_pend.begin());
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

std::vector<size_t> PmergeMe::v_make_jacob()
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
	while (i <= v_pend.size()){
		jacob = jacobsthal(i);
		if (jacob > v_pend.size()){
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
	while(size < v_pend.size()){
		vec.push_back(jacob);
		jacob--;
		size++;
	}

	return (vec);
}

void PmergeMe::v_binary_insert()
{
	std::vector<size_t> vec;
	vec = v_make_jacob();
	std::vector<int>::iterator it;
	std::vector<int>::iterator it1;
	for (it = v_pend.begin() + 2; it <= v_pend.end(); it++)
	{
		it1 = std::lower_bound(v_main.begin(), v_main.end(), *(it - 1));
		v_main.insert(it1, *(it - 1));
	}
	if (_mr_lonly != -1){
		it1 = std::lower_bound(v_main.begin(), v_main.end(), _mr_lonly);
		v_main.insert(it1, _mr_lonly);
	}
}

void PmergeMe::v_show(std::string str, std::clock_t start)
{
	std::cout<<"Before:  ";
	for(std::vector<int>::iterator it = v_before.begin(); it < v_before.end(); it++)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<"After :  ";
	for(std::vector<int>::iterator it = v_main.begin(); it < v_main.end(); it++)
		std::cout<<*it<<" ";
	std::clock_t end = clock();
	double duration = (double)(end - start);
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Time to process a range of 5 elements with std::"<<str<<" : "<< duration <<" us"<<std::endl;
	// if (is_sorted(v_main))
	// 	std::cout<<"\n###############################################sorted##########################################\n";
}

////////////////////////////////////////////////////deque////////////////////////////////////////////////////

void PmergeMe::d_pair_me(int ac, char **av){
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
		if (ac == 2){
			v_main.push_back(fst);
			d_before.push_back(fst);
		}
		if (i != ac - 1)
		{
			d_before.push_back(fst);
			d_before.push_back(sec);
		}
		if (sec > fst)
			std::swap(fst, sec);
		if (i != ac - 1){
			_dec.push_back(std::make_pair(fst, sec));
		}
		if (mode)
			_mr_lonly = tmp;
	}
}

Condec PmergeMe::d_sort_pairs()
{
	Condec::iterator it;
	bool 			flag = false;
	for (it = _dec.begin(); it < _dec.end() - 1; it++)
	{
		if (it->first > (it + 1)->first){
			std::swap(*it, *(it + 1));
			flag = true;
		}
	}
	if (flag == false)
		return (_dec);
	d_sort_pairs();
	return (_dec);
}

void PmergeMe::d_separate_pair()
{
	Condec::iterator it;
	for (it = _dec.begin(); it < _dec.end(); it++){
		d_main.push_back(it->first);
		d_pend.push_back(it->second);
	}
	if (!d_pend.empty()){
		d_main.insert(d_main.begin(), *d_pend.begin());
	}
}

std::deque<size_t> PmergeMe::d_make_jacob()
{
	std::deque<size_t> vec;
	std::deque<size_t> tmp;
	size_t jacob = 0;
	size_t i = 3;
	int j = 1;
	size_t a;
	size_t prev = INT64_MAX;
	
	vec.push_back(1);
	tmp.push_back(1);
	while (i <= d_pend.size()){
		jacob = jacobsthal(i);
		if (jacob > d_pend.size()){
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
	while(size < d_pend.size()){
		vec.push_back(jacob);
		jacob--;
		size++;
	}

	return (vec);
}

void PmergeMe::d_binary_insert()
{
	std::deque<size_t> vec;
	vec = d_make_jacob();
	std::deque<int>::iterator it;
	std::deque<int>::iterator it1;
	for (it = d_pend.begin() + 2; it <= d_pend.end(); it++)
	{
		it1 = std::lower_bound(d_main.begin(), d_main.end(), *(it - 1));
		d_main.insert(it1, *(it - 1));
	}
	if (_mr_lonly != -1){
		it1 = std::lower_bound(d_main.begin(), d_main.end(), _mr_lonly);
		d_main.insert(it1, _mr_lonly);
	}
}

void PmergeMe::d_show(std::string str, std::clock_t start)
{
	std::cout<<"Before:  ";
	for(std::deque<int>::iterator it = d_before.begin(); it < d_before.end(); it++)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<"After :  ";
	for(std::deque<int>::iterator it = d_main.begin(); it < d_main.end(); it++)
		std::cout<<*it<<" ";
	std::clock_t end = clock();
	double duration = (double)(end - start);
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Time to process a range of 5 elements with std::"<<str<<" : "<< duration <<" us"<<std::endl;
	// if (is_sorted(d_main))
	// 	std::cout<<"\n###############################################sorted##########################################\n";
}