#include "stdbool.h";
#include "stdio.h";
#include "stdlib.h";
#include "string.h";
#include "io.h";

struct Element 
{
	char Name[40];
	int amount;
};

void print(FILE* f)
{
	rewind(f);
	struct Element elem;
	do
	{              
		fread(&elem, sizeof(struct Element), 1, f);
		if (feof(f)) break;
		printf("%s %d", elem.Name, elem.amount);
		puts("");
	} while (!feof(f));
}

void swap(FILE *f, struct Element elem, fpos_t *pos)
{
	if (!f) return;
	fsetpos(f, pos);// тут
	fwrite(&elem, sizeof(struct Element), 1, f);
	
}

void InputChanges(FILE* inventory, FILE* help) 
{
	rewind(inventory);
	rewind(help);
	struct Element temp;
	struct Element tempHelp;
	fpos_t invPos;
	do 
	{
		fread(&tempHelp, sizeof(struct Element), 1, help);
		if (feof(help))break;
		do 
		{
			fgetpos(inventory, &invPos);
			fread(&temp, sizeof(struct Element), 1, inventory);
			if (strcmp(temp.Name, tempHelp.Name) == 0) 
			{
				temp.amount += tempHelp.amount;
				swap(inventory, temp, &invPos);
				break;
			}

		} while (!feof(inventory));
		rewind(inventory);

	} while (!feof(help));
}

void CountDelta(FILE* help)
{
	rewind(help);
	fpos_t Pos;
	struct Element temp1;
	struct Element temp2;
	do 
	{
		fread(&temp1, sizeof(struct Element), 1, help);
		fgetpos(help, &Pos);
		do 
		{
			fread(&temp2, sizeof(struct Element), 1, help);
			if (strcmp(temp1.Name, temp2.Name) == 0) 
			{
				temp1.amount += temp2.amount;
				fgetpos(help, &Pos);
			}

			
			
		} while (!feof(help));
		
		printf("Chainges in %s - %d", temp1.Name, temp1.amount);
		if (feof(help)) break;
		fsetpos(help, &Pos);
	} while (!feof(help));
}

void WriteIntoFile(FILE* f) 
{
	struct Element* elem;
	if ((elem = calloc(1, sizeof(struct Element))) == NULL)
	{
		puts("Can not pick out memory");
		fclose(f);
		return;
	}

	puts("Input name of the material");
	gets(elem->Name);
	puts("Input amount of the material");
	scanf_s("%d", &elem->amount);
	fwrite(elem, sizeof(struct Element), 1, f);
	getchar();
}

int main() 
{
	FILE* inventory;
	FILE* help;
	if (!(help = fopen("help.bin", "r+b")))
	{
		puts("Can not open help file");
	}
		
	if (!(inventory = fopen("inventory.bin", "r+b")))
	{
		puts("Can not open inventory file");
	}
	
	puts("Content of the warehouse before chainges:");
	print(inventory);
	puts("Changes:");
	print(help);
	InputChanges(inventory, help);
	puts("After changes:");
	print(inventory);
	puts("Delta:");
	CountDelta(help);
	fclose(help);
	fclose(inventory);

}
