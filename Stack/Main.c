/**************************************************************************************
    Author: Shlomo salomon.
    Creation date:  7/7/22
    Last modified date: 8/7/22
    Description: Last in first out, Grows on demand, No direct access.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "Stack.h"

void StackQuestionsMain();
int UnitTestsMain();

void main()
{
    StackQuestionsMain();
    //UnitTestsMain();
}

int UnitTestsMain()
{
    Stack_t* stk = NULL;
    Stack_t* tmpStk = NULL;
    ADTErr  eErr;
    int temp = 8;

    /* Test-case 1: Create Stack */
    printf("Stack Unit-Test: \n-----------------\n");
    printf("\n\ntest create stack #1\n");
    eErr = StackPush(stk, 7);          /*End-case: Push element to null stack */
    HandleErr(eErr, "Adding value: 7");
    printf("\n\ntest create Stack #2\n");
    stk = StackCreate(10, 2);
    printf("\n\ntest create stack #3\n");
    tmpStk = StackCreate(0, 0);
    printf("initializing tmpStk with size=0, blockSize=0\n\n");
    StackPrint(tmpStk);
    StackDestroy(tmpStk);
    tmpStk = NULL;
    printf("\n\ntest create stack #4\n");
    tmpStk = StackCreate(0, 1);
    printf("initializing tmpStk with size=0, blockSize=1");
    StackPrint(tmpStk);
    StackDestroy(tmpStk);
    tmpStk = NULL;
    printf("\n\ntest create stack #5\n");
    tmpStk = StackCreate(1, 0);
    printf("initializing tmpStk with size=1, blockSize=0");
    StackPrint(tmpStk);
    StackDestroy(tmpStk);

    tmpStk = NULL;

    /* Test-case 2: Push element */
    printf("\n\ntest Push element #1\n"); /*test Push element*/
    eErr = StackPush(stk, 7);
    HandleErr(eErr, "Adding value: 7");
    printf("\n\ntest Push element #2\n"); /*test Push element*/
    eErr = StackPush(stk, 8);
    HandleErr(eErr, "Adding value: 8");
    printf("\n\ntest Push element #3\n"); /*test Push element*/
    eErr = StackPush(stk, 70);
    HandleErr(eErr, "Adding value: 70");
    printf("\n\ntest Push element #4\n"); /*test Push element*/
    eErr = StackPush(stk, 3);
    HandleErr(eErr, "Adding value: 3");
    StackPrint(stk);
    printf("\n\ntest Push element #5\n"); /*test Push element*/
    StackPush(stk, 3);
    StackPush(stk, 3);
    StackPush(stk, 3);
    StackPush(stk, 3);
    StackPush(stk, 3);
    StackPush(stk, 10);
    HandleErr(eErr, "Adding value: 10");
    printf("\n\ntest Push element #6\n"); /*test Push element*/
    eErr = StackPush(stk, 11);           /*Feature: Grows on demand. */
    HandleErr(eErr, "Adding value: 11");
    StackPrint(stk);
    printf("\n\ntest Push element #7\n"); /*test Push element*/
    tmpStk = StackCreate(0, 0);
    printf("initializing tmpStk with size=0, blockSize=0\n\n");
    eErr = StackPush(tmpStk, temp);
    HandleErr(eErr, "Push to tmpStk ");
    StackPrint(tmpStk);
    StackDestroy(tmpStk);
    tmpStk = NULL;
    printf("\n\ntest Push element #8\n"); /*test Push element*/
    tmpStk = StackCreate(0, 1);
    printf("initializing tmpStk with size=0, blockSize=1");
    eErr = StackPush(tmpStk, temp);
    eErr = StackPush(tmpStk, temp);
    StackPrint(tmpStk);
    HandleErr(eErr, "Push to tmpStk ");
    StackDestroy(tmpStk);
    tmpStk = NULL;
    printf("\n\ntest Push element #9\n"); /*test Push element*/
    tmpStk = StackCreate(1, 0);
    printf("initializing tmpStk with size=1, blockSize=0");
    eErr = StackPush(tmpStk, temp);
    eErr = StackPush(tmpStk, temp);
    StackPrint(tmpStk);
    HandleErr(eErr, "Push 2 items to tmpStk ");
    StackDestroy(tmpStk);
    tmpStk = NULL;

    /* Test-case 3: Pop element */
    printf("\n\ntest Pop element #1\n"); /*test Pop element*/
    StackPrint(stk);
    eErr = StackPop(stk, &temp);
    printf("item deleted : %d\n", temp);
    StackPrint(stk);
    HandleErr(eErr, "deleting item");
    printf("\n\ntest Pop element #2\n"); /*test Pop element*/
    StackPop(stk, &temp);
    StackPop(stk, &temp);
    StackPop(stk, &temp);   /*Feature: Decrease by lack of demand. */
    printf("****after deleting 4 items, the curent size supposed to downsize****\n");
    StackPrint(stk);
    printf("\n\ntest Pop element #3\n"); /*test Pop element*/
    StackPop(stk, &temp);
    StackPop(stk, &temp);
    StackPop(stk, &temp);
    StackPop(stk, &temp);  /*isnt decreased because te original size is 10. */
    printf("****after deleting 4 items, the curent size is NOT supposed to downsize****\n");
    StackPrint(stk);
    printf("\n\ntest Pop element #4\n"); /*test Pop element*/
    tmpStk = StackCreate(0, 0);
    printf("initializing tmpStk with size=0, blockSize=0\n\n");
    eErr = StackPop(tmpStk, &temp);
    HandleErr(eErr, "Pop from tmpStk (a NULL pointer)");
    if (!eErr)
    {
        printf("item deleted: %d", temp);
    }
    StackPrint(tmpStk);
    StackDestroy(tmpStk);
    tmpStk = NULL;
    printf("\n\ntest Pop element #5\n"); /*test Pop element*/
    tmpStk = StackCreate(0, 1);
    printf("initializing tmpStk with size=0, blockSize=1");
    StackPrint(tmpStk);
    eErr = StackPop(tmpStk, &temp);
    if (!eErr)
    {
        printf("item deleted: %d", temp);
    }
    HandleErr(eErr, "Pop from tmpStk");
    StackDestroy(tmpStk);
    tmpStk = NULL;
    printf("\n\ntest Pop element #6\n"); /*test Pop element*/
    tmpStk = StackCreate(1, 0);
    printf("initializing tmpStk with size=1, blockSize=0");
    StackPrint(tmpStk);
    eErr = StackPop(tmpStk, &temp);
    if (!eErr)
    {
        printf("item deleted: %d", temp);
    }
    HandleErr(eErr, "Pop from tmpStk");
    StackDestroy(tmpStk);
    tmpStk = NULL;

    /* Test-case 5: is empty element   */
    printf("\n\ntest is empty element #1\n"); /*test is empty element*/
    temp = StackIsEmpty(stk);
    printf("%d\n", temp);
    printf("\n\ntest is empty element #2\n"); /*test is empty element*/
    StackPop(stk, &temp);
    StackPop(stk, &temp);
    StackPop(stk, &temp);
    temp = StackIsEmpty(stk);
    StackPrint(stk);
    printf("%d\n", temp);
    printf("\n\ntest is empty element #3\n"); /*test is empty element*/
    temp = StackIsEmpty(tmpStk);
    printf("%d\n", temp);

    /* Test-case 5: Top element    */
    printf("\n\ntest Top element #1\n"); /*test Top element*/
    eErr = StackTop(stk, &temp);
    printf("item gotten : %d\n", temp);
    HandleErr(eErr, "getting item");
    printf("\n\ntest Top element #2\n"); /*test Top element*/
    eErr = StackTop(tmpStk, &temp);
    HandleErr(eErr, "getting item from a null stack");

    /* Test-case 6: stack destroy */
    StackDestroy(stk);
    stk = NULL;
    tmpStk = StackCreate(0, 1);
    StackDestroy(tmpStk);
    StackPrint(stk);




    return 0;
}