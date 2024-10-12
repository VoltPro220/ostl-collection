#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


STACK* push(STACK* top, int data)
{
	STACK* ptr = malloc(sizeof(STACK));
	ptr->data = data;
	ptr->next = top;
	return ptr;
}

void prints(const STACK* top)
{
	const STACK* curr = top;
	while(curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}

}

STACK* pop(STACK* top)
{
	if(top == NULL)
		return top;

	printf("Deleted: %d\n", top->data);
	STACK* ptr_next = top->next;
	free(top);
	return ptr_next;
}

