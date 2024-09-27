#include <iostream>
#include "forward_list.h"

int main(const int argc, const char* const argv[])
{
	
	ostl::forward_list<int> fl;
	fl.push_back(5);
	fl.push_back(4);
	fl.push_back(3);
	fl.push_back(2);
	fl.push_back(1);
	fl.pop_front();

	for(ostl::size_t i = 0; i < fl.get_length(); i++) 
		std::cout << fl[i] << std::endl;

	return 0;
}