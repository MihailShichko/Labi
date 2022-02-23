#include "stdbool.h";
#include "stdio.h";
#include "stdlib.h";
#include "string.h";

#define numOfChild 2
#define stringSize 128

struct HealthyChild
{
	char* lastSickness;

	char* lastDoctorName;

};

struct SickChild
{
	char lastSickness[stringSize];

	char lastDoctorName[stringSize];

	char hospitalNum[stringSize];

	char hospitalAdress[stringSize];

	char currentDoctorSurname[stringSize];
};

struct Child
{
	bool isSick;

	char* childSurname;

	union Type
	{
		struct SickChild sickChild;
		
		struct HealthyChild healthyChild;

	};

};

char* getstr(char* st)
{
	int i = 0;
	while ((*(st + i++) = (char)getchar()) != '\n');
	st[--i] = '\0';
	return st;
}

char* getName(char str[]) 
{
	while (true)
	{
		rewind(stdin);
		if (!getstr(str)) printf("\nErorr... Try again\n");

		if (str[0] < 65 || str[0] > 90)
		{
			printf("\nError... surname starts with small letter\n");
		}
		else
		{
			break;
		}
	}

	return str;
}

struct Child InputHealthy(struct Child* child)
{
	printf("Input last sickness: ");
	child->healthyChild.lastSickness = malloc(sizeof(char));
	while (!getstr(child->healthyChild.lastSickness)) printf("\nErorr... Try again\n");

	printf("Input last doctor name: ");
	child->healthyChild.lastDoctorName = malloc(sizeof(char));
	while (!getName(child->healthyChild.lastDoctorName)) printf("\nErorr... Try again\n");
}

struct Child InputSick(struct Child* child)
{
	printf("Input last sickness: ");
	while (!getstr(child->sickChild.lastSickness)) printf("\nErorr... Try again\n");

	printf("Input last doctor name: ");
	while (!getName(child->sickChild.lastDoctorName)) printf("\nErorr... Try again\n");

	printf("Input hospital number: ");
	while (!fgets(child->sickChild.hospitalNum, stringSize, stdin)) printf("\nErorr... Try again\n");

	printf("Input hospital adress: ");
	while (!fgets(child->sickChild.hospitalAdress, stringSize, stdin)) printf("\nErorr... Try again\n");

	printf("Input current doctor surname: ");
	while (!getName(child->sickChild.currentDoctorSurname)) printf("\nErorr... Try again\n");
}

struct Child* childBuilder() 
{
	struct Child *child;
	child = malloc(sizeof(struct Child));
	printf("Input childs surname: ");
	child->childSurname = malloc(sizeof(char));
	while(!getName(child->childSurname)) printf("\nErorr... Try again\n");

	char sick;
	while (true) 
	{
		printf("Is child ill at the moment(y/n)?: ");
		sick = getchar();
		getchar();
		if (sick != 'y' && sick != 'n') 
		{
			printf("\nError try again...\n");
		}
		else
		{
			child->isSick = sick == 'y';
			break;
		}
	}

	if (child->isSick)
	{
		InputSick(child);
	}
	else
	{
		InputHealthy(child);
	}
	
	return child;

}

void outputChildrenByCondition(struct Child children[], char sickness[], int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = num - 1; j > i; j--)
		{
			if (children[j - 1].childSurname[0] > children[j].childSurname[0])
			{
				struct Child temp = children[j - 1];
				children[j - 1] = children[j];
				children[j] = temp;
			}
		}
	}

	printf("\nNeeded childern:\n");
	for (int i = 0; i < num; i++)
	{
		if (children[i].isSick)
		{
			if (!strcmp(children[i].sickChild.lastSickness, sickness))
			{
				printf("Child surname: ");
				puts(children[i].childSurname);
				printf("\n");
			}
		}
		else
		{
			if (!strcmp(children[i].healthyChild.lastSickness, sickness))
			{
				printf("Child surname: ");
				puts(children[i].childSurname);
				printf("\n");
			}
		}
	}
	
}

int main(int argc, char* argv[])
{
	int num;
	printf("Num: \n");
	while(!scanf_s("%d", &num)) printf("\nYou have to input int\n");
	struct Child *children = malloc(num * sizeof(struct Child));
	for (int i = 0; i < num; i++)
	{
		printf("#%d\n", i + 1);
		children[i] = *childBuilder();
	}
	
	outputChildrenByCondition(children, argv[1], num);	
}
