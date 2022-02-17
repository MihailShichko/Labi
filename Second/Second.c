#include "stdbool.h";
#include "stdio.h";
#include "stdlib.h";

struct Child
{
	union Inf
	{
		char* inf;
		bool isSick;
	};

	union Inf lastSickness;

	union Inf lastDoctorName;

	union Inf lastDoctorSurname;

	union Inf hospitalNum;

	union Inf hospitalAdress;

	union Inf currentDoctorSurname;
};

struct Child childBuilder() 
{
	struct Child child;
	printf("Imput last sickness: ");
	child.lastSickness.inf = malloc(sizeof(union Inf));
	while(!gets(child.lastSickness)) printf("\nErorr... Try again\n");

	printf("Imput last doctor name: ");
	child.lastDoctorName.inf = malloc(sizeof(union Inf));
	while(!gets(child.lastDoctorName.inf)) printf("\nErorr... Try again\n");

	printf("Imput last doctor surname: ");
	child.lastDoctorSurname.inf = malloc(sizeof(union Inf));
	while(!gets(child.lastDoctorSurname.inf)) printf("\nErorr... Try again\n");

	printf("Is child ill at the moment(y/n)?: ");
	char sick;
	while((sick = getchar()) != 'y' && (sick != 'n')) printf("\nErorr... Try again\n");
	
	child.isSick = (sick == 'y');
	if (child.isSick)
	{
		child.hospitalNum.inf = malloc(sizeof(union Inf));
		while(!gets(child.hospitalNum.inf)) printf("\nErorr... Try again\n");

		child.hospitalNum.inf = malloc(sizeof(union Inf));
		printf("Imput hospital number: ");
		while(!gets(child.hospitalNum.inf)) printf("\nErorr... Try again\n");

		printf("Imput hospital adress: ");
		child.hospitalAdress.inf = malloc(sizeof(union Inf));
		while(!gets(child.hospitalAdress.inf)) printf("\nErorr... Try again\n");

		printf("Imput current doctor surname: ");
		child.currentDoctorSurname.inf = malloc(sizeof(union Inf));
		while(!gets(child.currentDoctorSurname.inf)) printf("\nErorr... Try again\n");

	}
	return child;

}

int main()
{
	struct Child child = childBuilder();
	printf("\n%s", child.lastSickness);
	printf("\n%s", child.lastDoctorName);
	printf("\n%s", child.lastDoctorSurname);
	if (child.isSick) {
		printf("\n%s", child.hospitalNum);
		printf("\n%s", child.hospitalNum);
		printf("\n%s", child.currentDoctorSurname);
	}
}


