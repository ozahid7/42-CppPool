#include "MutantStack.hpp"
#include <stack>

int main(){
	MutantStack<int> v;
	v.push(5);
	v.push(6);	
	v.push(7);	
	v.push(8);	
	v.push(9);	
	v.push(10);	
	v.push(11);
	v.pop();
	v.pop();
	for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++){
		std::cout<<*it<<std::endl;
	}
}