#include <iostream>
#include "ovector.h"
#include "String.h"

int main(const int argc, const char* const argv[])
{
	srand(time(NULL));
	
	ostl::String str = "12345678912345678";
	std::cout << ostl::strlen(str) << std::endl;

	return 0;
}