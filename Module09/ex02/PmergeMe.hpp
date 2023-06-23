#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <optional>


typedef std::vector<std::pair<int, int> > ConVec;
typedef ConVec::iterator iterator;
class PmergeMe{
public:
	PmergeMe();
	PmergeMe(PmergeMe const &other);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &other);

	void				pair_me(int ac, char **av);
	ConVec				get_vec() const;
	void				set_vec(ConVec vec);
	int					get_mr_lonly() const;
	std::vector<int>	get_pend();
	std::vector<int>	get_main();
	ConVec				sort_pairs();
	void				separate_pair();
	std::vector<size_t>	make_jacob();
	void				binary_insert();
	void				show(std::string str, std::clock_t start);
private:
	ConVec _vec;
	std::vector<int> main;
	std::vector<int> pend;
	std::vector<int> before;
	int	_mr_lonly;
};
int is_it_digits(std::string str);
std::string trim_spaces(std::string str);

#endif