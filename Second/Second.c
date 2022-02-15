#include "stdbool.h";
#include "stdio.h";
#include "stdlib.h";

struct Child
{
	union aye
	{
		char* lastSickness;
		char* lastDoctorName;
		char* lastDoctorSurname;
		bool isSick;
		char* hospitalNum;
		char* hospitalAdress;
		char* currentDoctorSurname;
	};

	union aye Ls; //it

	union aye 
};

struct Child childBuilder() 
{
	struct Child child;
	printf("Imput last sickness: ");
	child.lastSickness = malloc(10);
	while(!gets(child.lastSickness)) printf("\nErorr...\n");

	printf("Imput last doctor name: ");
	child.lastDoctorName = malloc(10);
	while(!gets(child.lastDoctorName)) printf("\nErorr...\n");

	printf("Imput last doctor surname: ");
	child.lastDoctorSurname = malloc(10);
	while(!gets(child.lastDoctorSurname)) printf("\nErorr...\n");

	printf("Is child ill at the moment(y/n)?: ");
	char sick;
	while((sick = getchar()) != 'y' && (sick != 'n')) printf("\nErorr...\n");
	
	child.isSick = (sick == 'y');
	if (child.isSick)
	{
		printf("Imput hospital number: ");
		child.hospitalNum = malloc(10);
		while(!gets(child.hospitalNum)) printf("\nErorr...\n");

		printf("Imput hospital adress: ");
		child.hospitalAdress = malloc(10);
		while(!gets(child.hospitalAdress)) printf("\nErorr...\n");

		printf("Imput current doctor surname: ");
		child.currentDoctorSurname = malloc(10);
		while(!gets(child.currentDoctorSurname)) printf("\nErorr...\n");

	}
	return child;

}

int main()
{
	struct Child child = childBuilder();
	
}


