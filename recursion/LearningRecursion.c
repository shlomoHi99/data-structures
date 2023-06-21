/**************************************************************************************
	Author: Shlomo Salomon
	Creation date :  26/7/22
	Last modified date: 27/7/22
	Description : Recursion, basic examples.
***************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

//Forward declaretions:
long FactorialRec(size_t n);
long FactorialIter(size_t n);
size_t FiboncchiRec(size_t n);
size_t FiboncchiIter(size_t n);
int MaxArray(int* arr, size_t arrSize);
int SumArray(int* arr, size_t arrSize);
int IsPalindromRec(char* str, int strLen);
int IsPalindromIter(char* str);
char* StrFlip(char* str);
size_t myStrlenRec(const char* str);
size_t myStrlenIter(const char* str);
int myStrcmpRec(const char* str1, const char* str2);
int myStrcmpIter(const char* str1, const char* str2);
char* myStrcpy(char* destination, const char* source);
void HonoiiTowers(int n, char src, char dest, char aux);

void MainInLearningRecursion()
{
	//Factorial Example:
	/*size_t n = 4500;
	printf("Recursion: %zu! = %d\n", n, FactorialRec(n));
	printf("Iterative: %zu! = %d\n", n, FactorialIter(n));*/

	//Fibboncchi seq. example:
	/*size_t n = 29;
	printf("Recursion: the a%zu item in the fiboncchi seq. is: %zu\n", n, FiboncchiRec(n));
	printf("Iterative: the a%zu item in the fiboncchi seq. is: %zu\n", n, FiboncchiIter(n));*/

	//Array recursion example:
	/*int arr[] = { 10, 1,2,3,7,15,11 };
	printf("the biggest number in the arr is: %d\n", MaxArray(arr, sizeof(arr)/sizeof(arr[0])));
	printf("the sum of the numbers in the arr is: %d\n", SumArray(arr, sizeof(arr) / sizeof(arr[0])));*/

	//Palindrom example:
	/*char* sentence = "step on no pets";
	printf("Recursion: \"%s\" %s a palindrom\n", sentence, IsPalindromRec(sentence, strlen(sentence)) ? "is" : "is not");
	printf("Iterative: \"%s\" %s a palindrom\n", sentence, IsPalindromIter(sentence) ? "is" : "is not");*/

	//str flip example:
	/*char str[] = "abcd";
	printf("\"%s\" => ", str);
	printf("\"%s\"", StrFlip(str));*/

	//string.h functions:
	char str1[] = "datdno";
	char* str2 = "dan";
	//strlen implementation:
	/*printf("Recursion: strlen\t( \"%s\" )\t    => %zu\n", str1, myStrlenRec(str1));
	printf("Iterative: strlen\t( \"%s\" )\t    => %zu\n", str1, myStrlenIter(str1));*/
	//strcmp implementation:
	/*printf("Recursion: strcmp( \"%s\" , \"%s\") => %d\n", str1, str2, myStrcmpRec(str1, str2));
	printf("Iterative: strcmp( \"%s\" , \"%s\") => %d\n", str1, str2, myStrcmpIter(str1, str2));*/
	//strcpy implementation:
	/*printf("strcpy( \"%s\", \"%s\")", str1, str2);
	printf(" => \"%s\"\n", myStrcpy(str1, str2));
	printf("str1 = \"%s\", str2 = \"%s\"", str1, str2);*/
	
	//honoi towers:
	int n = 2;
	HonoiiTowers(n, 'A', 'B', 'C');
}

long FactorialRec(size_t n)
{
	if (n <= 1)
	{
		return (int)n;
	}

	return (int)n * FactorialRec(n - 1);
}

long FactorialIter(size_t n)
{
	long res = (int)n;

	while (n > 1)
	{
		res *= (int)--n;
	}
	return res;
}

size_t FiboncchiRec(size_t n)
{
	if (n <= 1)
	{
		return n;
	}

	return  FiboncchiRec(n - 1) + FiboncchiRec(n - 2);
}

size_t FiboncchiIter(size_t n)
{
	size_t nMinusOne = 1;
	size_t nMinusTwo = 0;
	size_t temp;

	if (n <= 1)
	{
		return n;
	}

	for (int i = 2; i <= n; i++)
	{
		temp = nMinusOne;
		nMinusOne += nMinusTwo;
		nMinusTwo = temp;
	}
	return nMinusOne;
}

int MaxArray(int* arr, size_t arrSize)
{
	if (arrSize == 1)
	{
		return *arr;
	}

	if (*arr < *(arr + arrSize - 1))
	{
		++arr;
	}

	return MaxArray(arr, arrSize - 1);
}

int SumArray(int* arr, size_t arrSize)
{
	if (arrSize == 1)
	{
		return *arr;
	}

	return *arr + SumArray(arr + 1, arrSize - 1);
}

int IsPalindromRec(char* str, int strLen)
{
	if(strLen <= 1)
	{
		return 1;
	}
	
	return (*str == *(str + strLen - 1)) && IsPalindromRec(str + 1, strLen - 2);
}

int IsPalindromIter(char* str)
{
	int strLen = (int)strlen(str);

	for (int i = 0; i < strLen; i++, strLen--)
	{
		if (*(str + i) != *(str + strLen - 1))
		{
			return 0;
		}
	}
	return 1;
}

char* StrFlip(char* str)
{
	char current;
	size_t len;

	if (!str || *str == '\0')
	{
		return str;
	}

	len = (int)strlen(str);
	current = *str;
	strcpy(str,StrFlip(str + 1));
	*(str + len - 1) = current;
	
	return str;
}

size_t myStrlenRec(const char* str)
{
	assert(str);

	return (!*str) ? 0 : myStrlenRec(str + 1) + 1;
}

size_t myStrlenIter(const char* str)
{
	assert(str);

	const char* temp = str;
	while (*str)
	{
		++str;
	}
	return str - temp;
}

int myStrcmpRec(const char* str1, const char* str2)
{
	assert(str1 && str2);

	if (*str1 == '\0' && *str2 == '\0')
	{
		return 0;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	if (*str1 < *str2)
	{
		return -1;
	}

	return myStrcmpRec(str1 + 1, str2 + 1);
}

int myStrcmpIter(const char* str1, const char* str2)
{
	assert(str1 && str2);

	while (*str1 || *str2)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		if (*str1 < *str2)
		{
			return -1;
		}
		str1++;
		str2++;
	}
	return 0;
}

void HonoiiTowers(int n, char src, char aux, char dest)
{
	if (n == 1)
	{
		printf("\nMove from %c to %c", src, dest);
		return;
	}

	HonoiiTowers(n - 1, src, dest, aux);
	printf("\nMove from %c to %c", src, dest);
	HonoiiTowers(n - 1, aux, src, dest);
}

char* myStrcpy(char* destination, const char* source)
{
	assert(destination && source);

	if (!*source)
	{
		*destination = *source;
		return destination;
	}

	*destination = *source;
	myStrcpy(destination + 1, source + 1);
	return destination;
}

