#include "stdbool.h";
#include "stdio.h";
#include "stdlib.h";

#define numOfChild 4

struct HealthyChild
{
	char* lastSickness;

	char* lastDoctorName;

	char* lastDoctorSurname;

	bool isSick;
};

struct SickChild
{
	//char* lastSickness;

	//char* lastDoctorName;

	//char* lastDoctorSurname;

	struct HealthyChild CommonInf;

	char* hospitalNum;

	char* hospitalAdress;

	char* currentDoctorSurname;
};


struct Child
{
	union Type
	{
		struct SickChild sickChild;
		
		struct HealthyChild healthyChild;

	};
};

struct Child childBuilder() 
{
	struct Child child;
	printf("Input last sickness: ");
	child.healthyChild.lastSickness = malloc(sizeof(union Type));
	while(!gets(child.healthyChild.lastSickness)) printf("\nErorr... Try again\n");

	printf("Input last doctor name: ");
	child.healthyChild.lastDoctorName = malloc(sizeof(union Type));
	while(!gets(child.healthyChild.lastDoctorName)) printf("\nErorr... Try again\n");

	printf("Input last doctor surname: ");
	child.healthyChild.lastDoctorSurname = malloc(sizeof(union Type));
	while(!gets(child.healthyChild.lastDoctorSurname)) printf("\nErorr... Try again\n");

	printf("Is child ill at the moment(y/n)?: ");
	char sick;
	while((sick = getchar()) != 'y' && (sick != 'n')) printf("\nErorr... Try again\n");
	child.healthyChild.isSick = sick == 'y';

	if (child.healthyChild.isSick) //truble
	{
		child.sickChild.CommonInf = child.healthyChild;

		child.sickChild.hospitalNum = malloc(sizeof(union Type));
		while(!gets(child.sickChild.hospitalNum)) printf("\nErorr... Try again\n");

		child.sickChild.hospitalNum = malloc(sizeof(union Type));
		printf("Input hospital number: ");
		while(!gets(child.sickChild.hospitalNum)) printf("\nErorr... Try again\n");

		printf("Input hospital adress: ");
		child.sickChild.hospitalAdress = malloc(sizeof(union Type));
		while(!gets(child.sickChild.hospitalAdress)) printf("\nErorr... Try again\n");

		printf("Input current doctor surname: ");
		child.sickChild.currentDoctorSurname = malloc(sizeof(union Type));
		while(!gets(child.sickChild.currentDoctorSurname)) printf("\nErorr... Try again\n");

	}
	return child;

}

int main(int argc, char** argv)
{
	struct Child children[numOfChild];
	for (int i = 0; i < numOfChild; i++)
	{
		children[i] = childBuilder();
	}

	for (int i = 0; i < numOfChild; i++) 
	{            
		for (int j = numOfChild - 1; j > i; j--)
		{ 
			if (children[j - 1].healthyChild.lastDoctorName[0] > children[j].healthyChild.lastDoctorName[0])
			{
				struct Child temp = children[j - 1];
				children[j - 1] = children[j];
				children[j] = temp;
			}
		}

	}

	for (int i = 0; i < numOfChild; i++)
	{
		if (children[i].sickChild.CommonInf.lastSickness == argv[1]) 
		{
			printf("%s", children[i].sickChild.CommonInf.lastSickness);
		}
	}

}


