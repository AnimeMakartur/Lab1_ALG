#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Константи для обмеження кількості цифр у випадковому числі
#define MinN 15
#define MaxN 30

//Прототипи функцій
int inputNumber();//Введення кількості цифр
char* createNumb(int, char[]);//Створення випадкового числа у вигляді рядка
void createArrayOfNums(int, char* []);//Створення масиву рядків з випадковими числами
int sumOfDigits(char*);//Підрахунок суми цифр у рядку
void printArrayAndSums(int, char* []);//Виведення масиву рядків та суми цифр у кожному рядку

//Головна функція
int main()
{
	char* arr[MaxN];
	int N=inputNumber();;
	srand(time(0));
	createArrayOfNums(N, arr);
	printArrayAndSums(N, arr);
	return 0;
}

int inputNumber()
{
	int Numb;
	printf("Enter the number of digits: ");
lable:
	scanf_s("%d",&Numb);
	if (Numb < MinN || Numb > MaxN)
	{
		printf("Invalid input. Please enter a number between 15 and 30:");
		goto lable;
	}
	return Numb;
}
char* createNumb(int N, char num[])
{
	*num = rand() % 9 + 1 + '0';//Генерація першої цифри від 1 до 9, щоб уникнути провідних нулів
	char* pNum = num + 1;
	for (; pNum < num + N; pNum++)
		*pNum = rand() % 10 + '0';
	*pNum = '\0';
	return num;
}
void createArrayOfNums(int N, char* arr[])
{
	char num[MaxN + 1];
	for (char** parr = arr + N; arr < parr; arr++)
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
		printf("%-32s | %d\n", *arr, sumOfDigits(*arr));//Виведення ря-дків та їх сум у вигляді таблиці
}
