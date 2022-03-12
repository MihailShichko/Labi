#include "stdbool.h";
#include "stdio.h";
#include "stdlib.h";
#include "string.h";



char* getstr(char* st)
{
	int i = 0;
	while ((*(st + i++) = (char)getchar()) != '\n');
	st[--i] = '\0';
	return st;
}

int FillFile(FILE* f) 
{
	printf("Input string: ");
	char *str = malloc(sizeof(char));
	str = getstr(str);
	fprintf(f,"%s", str);
	return strlen(str);
}

bool IsLetter(char c) 
{
	char splits[] = { ' ', ',', '.', '/', '?', '!', '-', '[', ']', '{', '}', '(', ')', '1', '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  '0',  '@', '#', '$', '%', '^', '*', '+', '\'', '\"', };
	int len = 32;
	for (int i = 0; i < 32; i++) 
	{
		if (c == splits[i]) return false;
	}

	return true;
}

int CountWordsInFileByLen(FILE* f, int len)
{
	rewind(f);
	int num = 0;
	int count;
	while (true) 
	{
		while (fgetc(f) == ' ' && !feof(f));

		if (feof(f)) break;
		fseek(f, -1, 1);
		count = 0;
		while(IsLetter(fgetc(f)) && !feof(f))
		{
			count++;
		}

		if (count == len) num++;
	}

	return num;
}

int FileLen(FILE* f)
{
	rewind(f);
	int len = 0;
	while (!feof(f)) 
	{
		fgetc(f);
		len++;
	}

	return len - 1;
}

int main()
{
	FILE* f;
	if (!(f = fopen("a.txt", "r+")))
	{
		puts("Can not create file");
		return 0;
	}
	
	int size = FileLen(f);
	if(size == 0) 
	{
		printf("File is empty");
		return 0;
	}

	int len = 1;
	int num;
	while (len < size)
	{
		num = CountWordsInFileByLen(f, len);
		if(num != 0) printf("Amount of words with length %d is %d\n", len, num);
		len++;
		num = 0;
	}

	fclose(f);
}

