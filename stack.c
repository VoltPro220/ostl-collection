#include "stack.h"


voidp pushc(stack* top, int data)
{
	stack* ptr = (stack*)malloc(sizeof(stack));
	ptr->next = top;
	ptr->data = data;
	return ptr;
}

void prints(const stack* top)
{
	const stack* current = top;
	while(current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}

}

voidp popc(stack* top)
{
	if(top == NULL)
		return top;

	printf("Deleted: %d\n", top->data);
	stack* ptr_next = top->next;
	free(top);
	return ptr_next;
}