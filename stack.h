#pragma once

#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

typedef void* voidp;

typedef struct obj
{
	int data;
	struct obj* next;
} stack;

EXTERNC
voidp pushc(stack* top, int data);
EXTERNC 
voidp popc(stack* top);
EXTERNC 
void prints(const stack* top);


#undef EXTERNC

stack* push(stack* top, int data)
{
	return (stack*)pushc(top, data);
}

stack* pop(stack* top)
{
	return (stack*)popc(top);
}