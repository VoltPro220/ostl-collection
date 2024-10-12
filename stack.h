#pragma once
#include "stack.c"

typedef struct OBJ
{
	int data;
	struct OBJ* next;
} STACK;

#ifdef __cplusplus
extern "C" {
#endif
	STACK* push(STACK*, int);
	STACK* pop(STACK*);
	void prints(const STACK* top);
#ifdef __cplusplus
}
#endif