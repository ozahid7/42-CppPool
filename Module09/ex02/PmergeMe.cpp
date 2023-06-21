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
		tmp = fst;
		if (sec > fst)
			std::swap(fst, sec);
		if (i != ac - 1)
			_vec.push_back(std::make_pair(fst, sec));
		if (mode)
			_mr_lonly = tmp;
	}
}

bool compare_pair(std::pair<int, int> first, std::pair<int, int> second){
	return (first.first < second.first);
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
		main.insert(main.begin(), pend[0]);
	}

	// for (it = _vec.begin(); it < _vec.end(); it++)
	// {
	// 	std::cout<<it->first<<" "<<it->second<<std::endl;	
	// }
	// std::cout<<"################################\n";
	// for (size_t i = 0; i < main.size(); i++)
	// {
	// 	std::cout<<main[i]<<std::endl;	
	// }
	// std::cout<<"################################\n";
	// for (size_t i = 0; i < pend.size(); i++)
	// {
	// 	std::cout<<pend[i]<<std::endl;	
	// }
	// std::cout<<"################################\n";
}

std::vector<size_t> PmergeMe::make_jacob()
{
	std::vector<size_t> vec;
	vec.push_back(1);
	size_t jacob = 0;
	size_t i = 3;
	int j = 0;
	size_t a;
	size_t prev;
	size_t last = 1;
	while (i <= pend.size()){
		jacob = jacobsthal(i);
		if (jacob > pend.size())
			break;
		a = jacob;
		last = jacob;
		vec.push_back(jacob);
		prev = vec[j];
		while (1){
			if (a == prev)
				break;
			else if (a > prev)
			{
				a--;
				if(a != prev)
					vec.push_back(a);
			}
		}
		j++;
		i++;
	}
	while (++last <= pend.size())
	{
		vec.push_back(last);
	}
	return (vec);
}



void PmergeMe::binary_insert()
{
	std::vector<size_t> vec;
	vec = make_jacob();
	std::vector<int>::iterator it;

	std::cout<<"\n#########pend############"<<std::endl;
	for (size_t i = 0; i < pend.size(); i++)
	{
		std::cout<<pend[i]<<std::endl;	
	}
	std::cout<<"##########jacob###############"<<std::endl;
	for(size_t i = 0; i < vec.size(); i++)
	{
		std::cout<<vec[i]<<std::endl;
	}
	std::cout<<"##########main###############"<<std::endl;
	for (size_t i = 0; i < main.size(); i++)
	{
		std::cout<<main[i]<<std::endl;	
	}
	std::cout<<"#########.     ##################\n";
	for (size_t i = 0; i < pend.size(); i++)
	{
		std::cout<<vec[i - 1]<<"     ********  "<<std::endl;
		std::cout<<pend[vec[i - 1]]<<"#########"<<std::endl;
		it = std::lower_bound(main.begin(), main.end(), pend[vec[i - 1]]);
		main.insert(it, pend[vec[i - 1]]);	
	}

	for (size_t i = 0; i < main.size(); i++)
	{
		std::cout<<main[i]<<std::endl;	
	}
	
}
