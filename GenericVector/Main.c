/**************************************************************************************
    Author: Shlomo salomon.
    Creation date:  13/7/22
    Last modified date: 30/8/22
    Description: Sequence of elements, Ditect access, Grows on demand, Generic.
***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "GenericVector.h"

void PrintInt(void* n);
void PrintChar(void* c);
void PrintFloat(void* f);

void main()
{
    int n1 = 6, n2 = 7, n3 = 9, n4 = 16, n5 = 37, n6 = 9, newNum = 77;
    void* deletedTemp, *itemGot;
    size_t nItems;
    ADTErr errCode;

    /*******************************/
    /*    unit test on generic vector     */
    printf("*******  unit testing of generic vector   *******\n\n");

    /*   unit test for Vector create   */
    printf("/*   unit test for Vector create   */\n");
    GenVector_t* tempVec1 = GenVectorCreate(0, 0);
    if (!tempVec1)
    {
        printf("vector when size = 0 and blocksize = 0 is null\n");
    }
    GenVector_t* tempVec2 = GenVectorCreate(2, 0);
    if (!tempVec2)
    {
        printf("vector when size = 2 and blocksize = 0 is null\n");
    }
    GenVector_t* tempVec3 = GenVectorCreate(0, 2);
    if (!tempVec3)
    {
        printf("vector when size = 0 and blocksize = 2 is null\n");
    }
    GenVector_t* tempVec4 = GenVectorCreate(1, 2);
    if (!tempVec4)
    {
        printf("vector when size = 1 and blocksize = 2 is null\n");
    }
    GenVector_t* intVec = GenVectorCreate(2, 2);
    

    /*   unit test for Vector add   */
    printf("/*   unit test for Vector add   */\n");
    GenVectorAdd(intVec, &n1);
    GenVectorAdd(intVec, &n2);
    GenVectorAdd(intVec, &n3);
    GenVectorAdd(intVec, &n4);
    GenVectorAdd(intVec, &n5);
    GenVectorAdd(intVec, &n6);

    GenVectorPrint(intVec, PrintInt);

    /*   unit test for Vector delete   */
    printf("/*   unit test for Vector delete   */\n");
    GenVectorDelete(intVec, &deletedTemp);
    printf("deleted item = %d\n", *((int*)deletedTemp));
    GenVectorDelete(intVec, &deletedTemp);
    printf("deleted item = %d\n", *((int*)deletedTemp));
    GenVectorDelete(intVec, &deletedTemp);
    printf("deleted item = %d\n", *((int*)deletedTemp));
    GenVectorDelete(intVec, &deletedTemp);
    printf("deleted item = %d\n", *((int*)deletedTemp));
    GenVectorDelete(intVec, &deletedTemp);
    printf("deleted item = %d\n", *((int*)deletedTemp));

    GenVectorPrint(intVec, PrintInt);

    GenVectorDelete(intVec, &deletedTemp);
    printf("deleted item = %d\n", *((int*)deletedTemp));
    errCode = GenVectorDelete(intVec, &deletedTemp);
    if (!errCode)
    {
        printf("deleted item = %d\n", *((int*)deletedTemp));
    }
    HandleErr(errCode, "vector delete from empty vector");

    /*   unit test for Vector Get   */
    printf("/*   unit test for Vector Get   */\n");
    GenVectorAdd(intVec, &n1);
    GenVectorAdd(intVec, &n2);
    GenVectorAdd(intVec, &n3);
    GenVectorAdd(intVec, &n4);
    GenVectorAdd(intVec, &n5);
    GenVectorAdd(intVec, &n6);

    errCode = GenVectorGet(intVec, 3, &itemGot);
    HandleErr(errCode, "vector get");
    if (!errCode)
    {
        printf("item from index 3 = %d\n", *((int*)itemGot));
    }
    errCode = GenVectorGet(intVec, 5, &itemGot);
    HandleErr(errCode, "vector get");
    if (!errCode)
    {
        printf("item from index 5 = %d\n", *((int*)itemGot));
    }
    errCode = GenVectorGet(intVec, 6, &itemGot);
    HandleErr(errCode, "vector get");
    if (!errCode)
    {
        printf("item from index 6 = %d\n", *((int*)itemGot));
    }
    errCode = GenVectorGet(intVec, 9, &itemGot);
    HandleErr(errCode, "vector get");
    if (!errCode)
    {
        printf("item from index 9 = %d\n", *((int*)itemGot));
    }
    GenVectorPrint(intVec, PrintInt);

    /*   unit test for Vector set   */
    printf("/*   unit test for Vector set   */\n");
    errCode = GenVectorSet(intVec, 3, &newNum);
    HandleErr(errCode, "vector set");
    errCode = GenVectorGet(intVec, 3, &itemGot);
    HandleErr(errCode, "vector get");
    if (!errCode)
    {
        printf("item from index 3 = %d\n", *((int*)itemGot));
    }
    errCode = GenVectorSet(intVec, 7, &newNum);
    HandleErr(errCode, "vector set index 7");
    errCode = GenVectorGet(intVec, 7, &itemGot);
    HandleErr(errCode, "vector get index 7");
    if (!errCode)
    {
        printf("item from index 7 = %d\n", *((int*)itemGot));
    }
    GenVectorPrint(intVec, PrintInt);

    /*   unit test for Vector nItems   */
    printf("/*   unit test for Vector nItems   */\n");
    GenVectorItemsNum(intVec, &nItems);
    printf("number of items in vector => %zu\n", nItems);


    /*   unit test for Vector destroy   */
    printf("/*   unit test for Vector destroy   */\n");
    GenVectorDestroy(intVec);
    GenVectorDestroy(tempVec1);
    GenVectorDestroy(tempVec2);
    GenVectorDestroy(tempVec3);
    GenVectorDestroy(tempVec4);

}

void PrintInt(void* n)
{
    int* num = (int*)n;
    printf("%d", *num);
}

void PrintChar(void* c)
{
    char* ch = (char*)c;
    putchar(*ch);
}

void PrintFloat(void* f)
{
    float* flt = (float*)f;
    printf("%f", *flt);
}