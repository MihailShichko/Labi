#include "stdbool.h";
#include "stdio.h";
#include "stdlib.h";

struct Child
{
	union Inf
	{
		char* lastSickness;
		char* lastDoctorName;
		char* lastDoctorSurname;
		bool isSick;
		char* hospitalNum;
		char* hospitalAdress;
		char* currentDoctorSurname;
	};

	union Inf LS;

	union Inf LDN;

	union Inf LDS;

	union Inf HN;

	union Inf HA;

	union Inf CDS;

};

struct Child childBuilder() 
{
	struct Child child;
	printf("Imput last sickness: ");
	child.LS.lastSickness = malloc(sizeof(union Inf));
	while(!gets(child.LS.lastSickness)) printf("\nErorr... Try again\n");

	printf("Imput last doctor name: ");
	child.LDN.lastDoctorName = malloc(sizeof(union Inf));
	while(!gets(child.LDN.lastDoctorName)) printf("\nErorr... Try again\n");

	printf("Imput last doctor surname: ");
	child.LDS.lastDoctorSurname = malloc(sizeof(union Inf));
	while(!gets(child.LDS.lastDoctorSurname)) printf("\nErorr... Try again\n");

	printf("Is child ill at the moment(y/n)?: ");
	char sick;
	while((sick = getchar()) != 'y' && (sick != 'n')) printf("\nErorr... Try again\n");
	
	child.isSick = (sick == 'y');
	if (child.isSick)
	{
		child.HN.hospitalNum = malloc(sizeof(union Inf));
		while(!gets(child.HN.hospitalNum)) printf("\nErorr... Try again\n");

		printf("Imput hospital number: ");
		child.HN.hospitalNum = malloc(sizeof(union Inf));
		while(!gets(child.HN.hospitalNum)) printf("\nErorr... Try again\n");

		printf("Imput hospital adress: ");
		child.HA.hospitalAdress = malloc(sizeof(union Inf));
		while(!gets(child.HA.hospitalAdress)) printf("\nErorr... Try again\n");

		printf("Imput current doctor surname: ");
		child.CDS.currentDoctorSurname = malloc(sizeof(union Inf));
		while(!gets(child.CDS.currentDoctorSurname)) printf("\nErorr... Try again\n");

	}
	return child;

}

int main()
{
	struct Child child = childBuilder();
	printf("\n%s", child.LS);
	printf("\n%s", child.LDN);
	printf("\n%s", child.LDS);
	if (child.isSick) {
		printf("\n%s", child.HN);
		printf("\n%s", child.HA);
		printf("\n%s", child.CDS);
	}
}


