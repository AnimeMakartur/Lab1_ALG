#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Константи для обмеження кількості цифр у випадковому числі
#define MinN 15
#define MaxN 30
#define MinEl 1
#define MaxEl 100

//Прототипи функцій
void inputNumber(int*, int, int);//Введення кількості цифр
char* createNumb(int, char[]);//Створення випадкового числа у вигляді рядка
void createArrayOfNums(int, char[], char* []);//Створення масиву рядків з випадковими числами
int sumOfDigits(char*);//Підрахунок суми цифр у рядку
void printArrayAndSums(int, char* []);//Виведення масиву рядків та суми цифр у кожному рядку

//Головна функція
int main()
{
	char num[MaxN+1];
	char* arr[MaxEl];
	int N, K;
	printf("Enter the number of digits: ");
	inputNumber(&N, MinN, MaxN);
	srand(time(0));
	printf("Enter the number of elements of array: ");
	inputNumber(&K, MinEl, MaxEl);
	createArrayOfNums(K, num, arr);
	printArrayAndSums(K, arr);
	return 0;
}

void inputNumber(int *Numb, int MinNumb, int MaxNumb)
{
	lable:
	scanf_s("%d", Numb);
	if(*Numb < MinNumb || *Numb > MaxNumb)
	{
		printf("Invalid input. Please enter a number between %d and %d: ", MinNumb, MaxNumb);
		goto lable;
	}
}

char* createNumb(int N, char num[])
{	
	*num = rand() % 9 + 1 + '0';//Генерація першої цифри від 1 до 9, щоб уникнути провідних нулів
	char* pNum = num+1;
	for (; pNum < num+N; pNum++)
		*pNum = rand() % 10 + '0';
	*pNum = '\0';
	return num;
}
void createArrayOfNums(int N, char num[], char* arr[])
{
	for(char** parr = arr+N; arr < parr; arr++)
		*arr = _strdup(createNumb(N, num));//_strdup виділяє пам'ять для рядка та копіює його
}
int sumOfDigits(char* num)
{
	int sum = 0;
	while (*num)
		sum += *num++ - '0';
	return sum;
}
void printArrayAndSums(int N, char* arr[])
{
	printf("\n%-32s | %s\n", "Generated Number", "Sum of Digits");//Виведення заголовку таблиці
	printf("----------------------------------------------------------\n");//Виведення рядків та їх сум у вигляді таблиці
	for (char** parr = arr + N; arr < parr; arr++)
		printf("%-32s | %d\n", *arr, sumOfDigits(*arr));//Виведення рядків та їх сум у вигляді таблиці
}

