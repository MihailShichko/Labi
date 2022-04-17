#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


struct Stack 
{
	int Value;
	struct Stack* tool;
};

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

void Sort(struct Stack* s) 
{
	struct Stack* s1;
	struct Stack* s2;
	int temp;
	for (; s->tool; s = s->tool)
	{
		s1 = s;
		for (s2 = s->tool; s2; s2 = s2->tool)
		{
			if (s1->Value < s2->Value) s1 = s2;
		}

		if (s1 != s) 
		{
			temp = s1->Value;
			s1->Value = s->Value;
			s->Value = temp;
		}
	}
}

int main() 
{
	struct Stack* stack = NULL;
	char ansver;
	do 
	{
		int a;	
		puts("Input integer value to stack: ");
		while (!scanf_s("%d", &a))
		{
			puts("You picked wrong value fool... Try again");
			rewind(stdin);
		}

		stack = Push(stack, a);
		do
		{
			puts("Wanna continue?(y/n)");
			rewind(stdin); //очистка буфера
			ansver = getchar();
		} while (ansver != 'y' && ansver != 'n');

	} while (ansver == 'y');

	Sort(stack);
	if (!stack)
	{
		puts("stack is empty");
		return;
	}
	do
	{
		printf("%d\n", stack->Value); 
		stack = stack->tool;  
	} while (stack);

}