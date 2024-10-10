#include <iostream>
#include "list.h"
#include "String.h"

int main(const int argc, const char* const argv[])
{
	ostl::list<int> l;
	l.push_front(5);
	l.push_front(4);
	l.push_front(3);
	l.push_front(2);
	l.push_front(1);
	return 0;
}