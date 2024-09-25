#include <iostream>
#include "ovector.h"
#include "String.h"


int main(const int argc, const char* const argv[])
{
	srand(time(NULL));

	ostl::vector<ostl::String> v;

	v.push_back("ELEMENT 1");
	v.push_back("ELEMENT 2");
	v.push_back("ELEMENT 3");
	v.push_back("ELEMENT 4");
	v.push_back("ELEMENT 5");

	for(size_t i = 0; i < v.get_length(); i++)
	{
		std::cout << v.operator[](i) << std::endl;
	}
	return 0;
}