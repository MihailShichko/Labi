#include "stdbool.h";
#include "stdio.h";

struct Child
{
	union
	{
		char* lastSickness;
		char* lastDoctorName;
		char* lastDoctorSurname;
		bool isSick;
		char* hospitalNum;
		char* hospitalAdress;
		char* currentDoctorSurname;
	};
};

struct Child childBuilder() 
{
	struct Child child;
	printf("Imput last sickness: ");
	while(!gets(child.lastSickness)) printf("\nErorr...\n");

	printf("Imput last doctor name: ");
	while(!gets(child.lastDoctorName)) printf("\nErorr...\n");

	printf("Imput last doctor surname: ");
	while(!gets(child.lastDoctorSurname)) printf("\nErorr...\n");

	printf("Is child ill at the moment(y/n)?: ");
	char isSick;
	while(isSick = getchar() != ('y' || 'n')) printf("\nErorr...\n");

	child.isSick = (isSick == 'y');
	if (child.isSick)
	{
		printf("Imput hospital number: ");
		while(!gets(child.hospitalNum)) printf("\nErorr...\n");

		printf("Imput hospital adress: ");
		while(!gets(child.hospitalAdress)) printf("\nErorr...\n");

		printf("Imput current doctor surname: ");
		while(!gets(child.currentDoctorSurname)) printf("\nErorr...\n");

	}
	return child;

}

int main()
{
	printf("ti pidor123");
	struct Child child = childBuilder();
	printf("%s", child.currentDoctorSurname);
	printf("%s", child.lastDoctorName);
	printf("%s", child.lastDoctorSurname);
	printf("%s", child.hospitalNum);
	printf("%s", child.hospitalAdress);
	printf("%s", child.currentDoctorSurname);
}


