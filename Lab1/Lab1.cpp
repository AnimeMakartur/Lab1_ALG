#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int inputNumb();
char* createNumb(int, char[]);
void createArrayOfNums(int, char[], char*[]);

int main()
{
	char num[31];
	srand(time(0));
	int N= inputNumb();
	createNumb(N, num);
	puts(num);
	return 0;
}

int inputNumb()
{
	int N;
	printf("Enter the number of digits: ");
	label:
	scanf_s("%d", &N);
	if(N < 15 || N > 30)
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
	for(int i = 0; i < N; i++)
	{
		arr[i] = _strdup(createNumb(N, num));
	}

}


