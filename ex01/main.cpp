#include "iter.hpp"
#include <functional>


int main() {
    char *array = "oussama";


	std::string str = array;
	iter(array, 9, print_msg);
	// iter1(array, 9,? print_msg);
    
    return 0;
}



// // #include"iter.hpp"
// #include<iostream>

// class Awesome 
// {
//     public: 
//     	Awesome( void ) : _n( 42 ) 
// 		{ 
// 			return; 
// 		} 
//     	int get( void ) const 
// 		{ 
// 			return this->_n; 
// 		} 
//     private: 
// 		int _n; 
// }; 

// std::ostream & operator<<(std::ostream & os, Awesome const & obj)
// {
// 	os << obj.get();
// 	return os;
// } 

// template< typename T > 
// void print(T const &x) 
// {
// 	std::cout << x << std::endl; 
// 	return; 
// } 

// int main() 
// { 
//     int tab[] = { 0, 1, 2, 3, 4 };
//     Awesome tab2[5]; 
//     iter(tab, 5, print); 
//     iter(tab2, 5, print); 
//     return 0; 
// }