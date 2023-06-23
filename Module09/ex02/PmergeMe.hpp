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
typedef std::deque<std::pair<int, int> > Condec;
typedef Condec::iterator iter;
class PmergeMe{
public:
	PmergeMe();
	PmergeMe(PmergeMe const &other);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &other);

	void				v_pair_me(int ac, char **av);
	ConVec				v_get_vec() const;
	void				v_set_vec(ConVec vec);
	std::vector<int>	v_get_pend();
	std::vector<int>	v_get_main();
	ConVec				v_sort_pairs();
	void				v_separate_pair();
	void				v_binary_insert();
	void				v_show(std::string str, std::clock_t start);
	std::vector<size_t>	v_make_jacob();


	std::deque<size_t>	d_make_jacob();
	void				d_pair_me(int ac, char **av);
	Condec				d_get_vec() const;
	void				d_set_vec(Condec vec);
	std::deque<int>		d_get_pend();
	std::deque<int>		d_get_main();
	Condec				d_sort_pairs();
	void				d_separate_pair();
	void				d_binary_insert();
	void				d_show(std::string str, std::clock_t start);

	template<typename T>
	bool is_sorted(T c){
		for(size_t i = 0; i < c.size() - 1; i++){
			if(c[i] > c[i + 1])
				return false;
		}
		return (true);
	}

private:
	ConVec _vec;
	std::vector<int> v_main;
	std::vector<int> v_pend;
	std::vector<int> v_before;
	Condec _dec;
	std::deque<int> d_main;
	std::deque<int> d_pend;
	std::deque<int> d_before;
	int	_mr_lonly;
};
int is_it_digits(std::string str);
std::string trim_spaces(std::string str);

#endif