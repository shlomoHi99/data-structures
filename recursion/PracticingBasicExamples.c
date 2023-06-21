/**************************************************************************************
	Author: Shlomo Salomon
	Creation date :  28/7/22
	Last modified date: --
	Description : Recursion, practicing basic examples.
***************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

int myStrsub(const char* str1, const char* str2);
size_t FiboncchiThreeExample(size_t n);
char* myToupper(char* str);
char* myTolower(char* str);
unsigned long long SumOfAllSmallerNumbers(size_t n);

void MainInPractice()
{
	//strlike implementation:
	/*char str1[] = "datdno";
	char* str2 = "dan";
	printf("myStrsub( \"%s\" , \"%s\") => ", str1, str2);
	myStrsub(str1, str2);*/

	//Fiboncchi Three Example
	/*size_t n = 5;
	printf("the a%zu item in the fiboncchi seq. is: %zu\n", n, FiboncchiThreeExample(n));*/

	//toupper and to lower example:
	/*char str1[] = "HvgvgGHBn";
	char str2[] = "HvgvgGHBn";
	printf("myToupper( \"%s\" ) => ", str1);
	printf("myToupper( \"%s\" )",myToupper(str1));
	printf("myTolower( \"%s\" ) => ", str2);
	printf("myTolower( \"%s\" )", myTolower(str2));*/
	/*size_t n = 6;
	printf("%uz => %lu", n, SumOfAllSmallerNumbers(n));*/

}

int myStrsub(const char* str1, const char* str2)
{
	assert(str1 && str2);

	if (!*str1 || !*str2)
	{
		return 1;
	}
	int success = 0;

	if (*str1 == *str2)
	{
		putchar(*str1);
		success = myStrsub(str1 + 1, str2 + 1);
	}
	if (!success)
	{
		myStrsub(str1 + 1, str2);
	}
	return 1;
}

size_t FiboncchiThreeExample(size_t n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	
	return FiboncchiThreeExample(n - 1) + FiboncchiThreeExample(n - 2) + FiboncchiThreeExample(n - 3);
}

char* myToupper(char* str)
{
	if (!*str)
	{
		return str;
	}
	
	if (*str > 'a' && *str < 'z')
	{
		*str -= 32;
	}
	myToupper(str + 1);
	return str;
}

char* myTolower(char* str)
{
	if (!*str)
	{
		return str;
	}

	if (*str > 'A' && *str < 'Z')
	{
		*str += 32;
	}
	myTolower(str + 1);
	return str;
}

unsigned long long SumOfAllSmallerNumbers(size_t n)
{
	if (n == 1)
	{
		return 1;
	}

	return n + SumOfAllSmallerNumbers(n - 1);
}