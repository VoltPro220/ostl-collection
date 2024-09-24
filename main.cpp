#include <iostream>
#include "ovector.h"

int main(const int argc, const char* const argv[])
{
	srand(time(NULL));


	ostl::smpl_ptr<int> px = new int[5]{5,4,5,4,5};
	for(size_t i = 0; i < 5; i++)
	{
		std::cout << (px[i]) << std::endl;

	}

	ostl::vector<int> v;
	v.push_front(5);
	v.push_back(6);
	v.push_front(4);
	v.push_front(2);
	v.push_front(1);
	v.insert(3, 2);



	int var;
	ostl::size_t index = 0;
	while(v.check(index++, var))
	{
		std::cout << var << std::endl;
	}

	return 0;
}