#include <iostream>
#include "stack.h"


int main(const int argc, const char* const argv[])
{
	stack* top = NULL;
	top = push(top, 1);
	top = push(top, 221);
	top = push(top, 4231);
	
	prints(top);

	while(top)
		top = pop(top);

	return 0;
}