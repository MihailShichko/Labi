#include "stdbool.h";
#include "stdio.h";
#include "stdlib.h";

struct Human 
{
	int age;
	char* name;
};

int main()
{
	struct Human man;
	man.name = (char*)malloc(10);
	gets(man.name);
	printf("%s", man.name);
}


