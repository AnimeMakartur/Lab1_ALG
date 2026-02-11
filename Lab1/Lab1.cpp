#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int inputNumb();
char* createNumb(int, char[]);
void createArrayOfNums(int, char[], char*[]);
int sumOfDigits(char*);
void printArrayAndSums(int, char* []);

int main()
{
	char num[31];
	char* arr[30];
	int N = inputNumb();
	srand(time(0));
	createArrayOfNums(N, num, arr);
	printArrayAndSums(N, arr);
	return 0;
}

int inputNumb()
{
	int N;
	printf("Enter the number of digits: ");
	label:
	scanf_s("%d", &N);
	if(N < 14 || N > 31)
	{
		printf("Invalid input. Please enter a number between 15 and 30: ");
		goto label;
	}
	return N;
}

char* createNumb(int N, char num[])
{
	char* i = num;
	for (; i < num+N; i++)
		*i = rand() % 10 + '0';
	*i = '\0';
	return num;
}

void createArrayOfNums(int N, char num[], char* arr[])
{
	char** i = arr;
	for(; i < arr+ N; i++)
	{
		*i = _strdup(createNumb(N, num));
	}

}

int sumOfDigits(char* num)
{
	int sum = 0;
	char* i = num;
	while (*i++)
	{
		sum += *i - '0';
	}
	return sum;
}

void printArrayAndSums(int N, char* arr[])
{
	char** i = arr;

	printf("\n%-32s | %s\n", "Generated Number", "Sum of Digits");
	printf("----------------------------------------------------------\n");

	for (; i < arr + N; i++)
	{
		printf("%-32s | %d\n", *i, sumOfDigits(*i));
	}
}

