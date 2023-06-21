#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "Vector.h"
#include "Stack.h"

void UnitTestForCheckParentheses();
int CheckParentheses(char* expression);
void UnitTestForStackReverse();
Stack_t* StackReverse(Stack_t* stack);
void UnitTestForStackMaxToTop();
Stack_t* StackMaxToTop(Stack_t* stack);
void UnitTestForStackAllMaxToTop();
Stack_t* StackAllMaxToTop(Stack_t* stack);
void UnitTestForCalcPostfixExpression();
int CalcPostfixExpression(char* expression);


void StackQuestionsMain()
{
	//UnitTestForCheckParentheses();
	//UnitTestForStackReverse();
	//UnitTestForStackMaxToTop();
	//UnitTestForStackAllMaxToTop();
	UnitTestForCalcPostfixExpression();
}

void UnitTestForCheckParentheses()
{
	int i = 1;
	char expr[20];
	/*    Unit test for Check Parentheses    */
	printf("\nUnit test for Check Parentheses\n");
	printf("\nunit test number %d\n", i++);
	strcpy(expr ,"({2}(3+[9]))");
	CheckParentheses(expr) ? printf("%s -> valid\n", expr) : printf("%s -> invalid\n", expr);
	printf("\nunit test number %d\n", i++);
	strcpy(expr, ")({2}(3+[9]))");
	CheckParentheses(expr) ? printf("%s -> valid\n", expr) : printf("%s -> invalid\n", expr);
	printf("\nunit test number %d\n", i++);
	strcpy(expr, "({)}");
	CheckParentheses(expr) ? printf("%s -> valid\n", expr) : printf("%s -> invalid\n", expr);
	printf("\nunit test number %d\n", i++);
	strcpy(expr, "]");
	CheckParentheses(expr) ? printf("%s -> valid\n", expr) : printf("%s -> invalid\n", expr);
}

int CheckParentheses(char* expression)
{
	Stack_t* prenthesesStack = StackCreate(10, 2);
	if (!prenthesesStack)
	{
		printf("ERROR: not enough memory!");
		exit(1);
	}
	int prenthesesType, cmpType,  isValid = 1;
	ADTErr errCode;

	while (*expression)
	{	
		if (*expression == '{' || *expression == '[' || *expression == '(')
		{
			StackPush(prenthesesStack, (int) * expression);
		}
		else if  (*expression == '}' || *expression == ']' || *expression == ')')
		{
			switch (*expression)
			{
			case('}'):
				cmpType = '{';
				break;
			case(']'):
				cmpType = '[';
				break;
			case(')'):
				cmpType = '(';
				break;
			}
			errCode = StackPop(prenthesesStack, &prenthesesType);
			if (prenthesesType != cmpType || errCode)
			{
				isValid = 0;
			}
		}
		++expression;
	}
	if (!StackIsEmpty(prenthesesStack))
	{
		isValid = 0;
	}
	return isValid;
}

void UnitTestForStackReverse()
{
	Stack_t* stack = StackCreate(10, 4);
	if (!stack)
	{
		printf("ERROR: not enough memory!");
		exit(1);
	}
	for (int i = 0; i < 10; i++)
	{
		StackPush(stack, (i + 1) * 6);
	}
	StackPrint(stack);
	stack = StackReverse(stack);
	StackPrint(stack);
	StackDestroy(stack);
	stack = NULL;
}

Stack_t* StackReverse(Stack_t* stack)
{
	Stack_t* reversedStack = StackCreate(10, 4);
	if (!reversedStack)
	{
		printf("ERROR: not enough memory!");
		exit(1);
	}
	int curNum;

	while (!StackIsEmpty(stack))
	{
		StackPop(stack, &curNum);
		StackPush(reversedStack, curNum);
	}
	StackDestroy(stack);
	stack = NULL;
	return reversedStack;
}

void UnitTestForStackMaxToTop()
{
	Stack_t* s1, * s2;
	s1 = StackCreate(14, 0);
	StackPush(s1, 987);
	StackPush(s1, 537);
	StackPush(s1, 2);
	StackPush(s1, 234);
	StackPush(s1, 1543);
	StackPush(s1, 67);
	StackPush(s1, 231);
	StackPrint(s1);
	s2 = StackMaxToTop(s1);
	StackPrint(s2);
	StackDestroy(s1);
	StackDestroy(s2);
}

Stack_t* StackMaxToTop(Stack_t* stack)
{
	if (!stack)
	{
		return stack;
	}
	
	int  arrIndex = 0, maxNum = INT_MIN, maxNumIndex, temp;
	Stack_t* newStack;
	Vector_t* tempArr = VectorCreate(10, 10);
	if (!tempArr)
	{

	}	

	while (!StackIsEmpty(stack))
	{
		StackPop(stack, &temp);
		VectorAdd(tempArr, temp);
		++arrIndex;
		if (temp > maxNum)
		{
			maxNum = temp;
			maxNumIndex = arrIndex;
		}
	}
	newStack = StackCreate(arrIndex, 4);
	if (!newStack)
	{
		printf("ERROR: not enough memory!");
		exit(1);
	}
	for (int i = arrIndex; i > 0; i--)
	{	
		VectorDelete(tempArr, &temp);
		if (i != maxNumIndex)
		{	
			StackPush(newStack, temp);
		}
	}
	StackPush(newStack, maxNum);
	VectorDestroy(tempArr);
	return newStack;
}

void UnitTestForStackAllMaxToTop()
{
	Stack_t* s1, * s2;
	s1 = StackCreate(14, 0);
	StackPush(s1, 1543);
	StackPush(s1, 987);
	StackPush(s1, 537);
	StackPush(s1, 2);
	StackPush(s1, 1543);
	StackPush(s1, 234);
	StackPush(s1, 1543);
	StackPush(s1, 67);
	StackPush(s1, 231);
	StackPush(s1, 231);
	StackPrint(s1);
	s2 = StackAllMaxToTop(s1);
	StackPrint(s2);
	StackDestroy(s1);
	StackDestroy(s2);
}

Stack_t* StackAllMaxToTop(Stack_t* stack)
{
	if (!stack)
	{
		return stack;
	}
	
	int  arrIndex = 0, maxNum = INT_MIN, maxNumCounter = 0, temp;
	Stack_t* newStack;
	Vector_t* tempArr = VectorCreate(10, 10);
	if (!tempArr)
	{

	}
	
	while (!StackIsEmpty(stack))
	{
		StackPop(stack, &temp);
		VectorAdd(tempArr, temp);
		++arrIndex;
		if (temp > maxNum)
		{
			maxNum = temp;
			maxNumCounter = 1;
		}
		else if (temp == maxNum)
		{
			++maxNumCounter;
		}
	}
	newStack = StackCreate(arrIndex, 4);
	if (!newStack)
	{
		printf("ERROR: not enough memory!");
		exit(1);
	}
	for (int i = arrIndex; i > 0; i--)
	{
		VectorDelete(tempArr, &temp);
		if (temp != maxNum)
		{
			StackPush(newStack, temp);
		}
	}
	VectorDestroy(tempArr);
	for (int i = 0; i < maxNumCounter; i++)
	{
		StackPush(newStack, maxNum);
	}
	
	return newStack;
}

void UnitTestForCalcPostfixExpression()
{
	int i = 1;

	char* exp1 = "234+-";
	printf("%d: %s = %d\n",i++, exp1, CalcPostfixExpression(exp1));
	char* exp2 = "23+45*+";
	printf("%d: %s = %d\n", i++, exp2, CalcPostfixExpression(exp2));
	char* exp3 = "23+0/";
	printf("%d: %s = %d\n", i++, exp3, CalcPostfixExpression(exp3));
	char* exp4 = "23+**";
	printf("%d: %s = %d\n", i++, exp4, CalcPostfixExpression(exp4));
}

int CalcPostfixExpression(char* expression)
{
	int expLen = (int)strlen(expression), operand1, operand2, result;
	ADTErr errCode;
	Stack_t* expStack = StackCreate(expLen, 1);
	if (!expStack)
	{
		printf("ERROR: not enough memory!");
		exit(1);
	}

	for (int i = 0; i < expLen; i++)
	{
		
		if (*(expression + i) <= '9' && *(expression + i) >= '0')
		{
			StackPush(expStack, *(expression + i)-'0');
		}
		else 
		if (*(expression + i) == '-' || *(expression + i) == '+' 
				|| *(expression + i) == '/' || *(expression + i) == '*')
		{
			StackPop(expStack, &operand1);
			errCode = StackPop(expStack, &operand2);
			if (errCode)
			{
				HandleErr(errCode, "invalid expression");
				return;
			}
			switch (*(expression + i))
			{
			case '-':
				StackPush(expStack, operand2 - operand1);
				break;
			case '+':
				StackPush(expStack, operand2 + operand1);
				break;
			case '/':
				if (operand1 == 0)
				{
					printf("invalid expression, cannot devide by 0");
					return;
				}
				StackPush(expStack, operand2 / operand1);
				break;
			case '*':
				StackPush(expStack, operand2 * operand1);
				break;
			}
		}
	}
	StackPop(expStack, &result);
	StackDestroy(expStack);
	return result;
}



