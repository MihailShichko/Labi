#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


struct Stack 
{
	int Value;
	struct Stack* tool;
};

void BuildStack() 
{

}

struct Stack* Push(struct Stack* stack, int value) 
{
	struct Stack* next;
	next = stack;
	if((stack = malloc(sizeof(struct Stack))) == NULL)
	{
		puts("No free space");
		return 0;
	}

	stack->Value = value;
	stack->tool = next;
	return stack;
}

struct Stack* Pop(struct Stack* stack) 
{
	if (stack == NULL) {
		puts("Stack is empty");
		return 0;
	}

	int result = stack->Value;
	struct Stack* cur = stack;
	stack = stack->tool;
	free(cur);
	return stack;
}

int Peek(struct Stack* stack) 
{
	if (stack == NULL) {
		puts("Stack does not exist");
		return 0;
	}

	return stack->Value;
}

int main() 
{
	struct Stack* stack = NULL;
	stack = Push(stack, 5);
	stack = Push(stack, 7);
	stack = Push(stack, 4);
	stack = Push(stack, 1);
	

}