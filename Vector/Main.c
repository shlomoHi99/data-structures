/**************************************************************************************
    Author: Dudi Kahana.
    Creation date:  28/6/22
    Last modified date: 7/6/22
    Description: Sequence of elements, Ditect access, Grows on demand.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "Vector.h"

int main()
{
    Vector_t* vec = NULL;
    Vector_t* tmpVec = NULL;
    ADTErr  eErr;
    int temp = 8;

    /* Test-case 1: Create Vector */
    printf("Vector Unit-Test: \n-----------------\n");
    printf("\n\ntest create vector #1\n");
    eErr = VectorAdd(vec, 7);          /*End-case: Add element to null vector */
    HandleErr(eErr, "Adding value: 7");
    printf("\n\ntest create vector #2\n");
    vec = VectorCreate(10, 2);
    printf("\n\ntest create vector #3\n");
    tmpVec = VectorCreate( 0, 0);
    printf("initializing tmpVec with size=0, blockSize=0\n\n");
    VectorPrint(tmpVec);
    VectorDestroy(tmpVec);
    tmpVec = NULL;
    printf("\n\ntest create vector #4\n");
    tmpVec = VectorCreate( 0, 1);
    printf("initializing tmpVec with size=0, blockSize=1");
    VectorPrint(tmpVec);
    VectorDestroy(tmpVec);
    tmpVec = NULL;
    printf("\n\ntest create vector #5\n");
    tmpVec = VectorCreate( 1, 0);
    printf("initializing tmpVec with size=1, blockSize=0");
    VectorPrint(tmpVec);
    VectorDestroy(tmpVec);
    
    tmpVec = NULL;

    /* Test-case 2: Add element */
    printf("\n\ntest Add element #1\n"); /*test add element*/
    eErr = VectorAdd(vec, 7);
    HandleErr(eErr, "Adding value: 7");
    printf("\n\ntest Add element #2\n"); /*test add element*/
    eErr = VectorAdd(vec, 8);
    HandleErr(eErr, "Adding value: 8");
    printf("\n\ntest Add element #3\n"); /*test add element*/
    eErr = VectorAdd(vec, 70);
    HandleErr(eErr, "Adding value: 70");
    printf("\n\ntest Add element #4\n"); /*test add element*/
    eErr = VectorAdd(vec, 3);
    HandleErr(eErr, "Adding value: 3");
    VectorPrint(vec);
    printf("\n\ntest Add element #5\n"); /*test add element*/
    VectorAdd(vec, 3);
    VectorAdd(vec, 3);
    VectorAdd(vec, 3);
    VectorAdd(vec, 3);
    VectorAdd(vec, 3);
    VectorAdd(vec, 10);
    HandleErr(eErr, "Adding value: 10");
    printf("\n\ntest Add element #6\n"); /*test add element*/
    eErr = VectorAdd(vec, 11);           /*Feature: Grows on demand. */
    HandleErr(eErr, "Adding value: 11");
    VectorPrint(vec);
    printf("\n\ntest Add element #7\n"); /*test add element*/
    tmpVec = VectorCreate(0, 0);
    printf("initializing tmpVec with size=0, blockSize=0\n\n");
    eErr = VectorAdd(tmpVec, temp);
    HandleErr(eErr, "add to tmpVec ");
    VectorPrint(tmpVec);
    VectorDestroy(tmpVec);
    tmpVec = NULL;
    printf("\n\ntest Add element #8\n"); /*test add element*/
    tmpVec = VectorCreate(0, 1);
    printf("initializing tmpVec with size=0, blockSize=1");
    eErr = VectorAdd(tmpVec, temp);
    eErr = VectorAdd(tmpVec, temp);
    VectorPrint(tmpVec);
    HandleErr(eErr, "add to tmpVec ");
    VectorDestroy(tmpVec);
    tmpVec = NULL;
    printf("\n\ntest Add element #9\n"); /*test add element*/
    tmpVec = VectorCreate(1, 0);
    printf("initializing tmpVec with size=1, blockSize=0");
    eErr = VectorAdd(tmpVec, temp);
    eErr = VectorAdd(tmpVec, temp);
    VectorPrint(tmpVec); 
    HandleErr(eErr, "add 2 items to tmpVec ");
    VectorDestroy(tmpVec);
    tmpVec = NULL;

    /* Test-case 3: Delete element */
    printf("\n\ntest delete element #1\n"); /*test delete element*/
    eErr = VectorDelete(vec, &temp);
    printf("item deleted : %d\n", temp);
    HandleErr(eErr, "deleting item");
    printf("\n\ntest delete element #2\n"); /*test delete element*/
    VectorDelete(vec, &temp);
    VectorDelete(vec, &temp);
    VectorDelete(vec, &temp);   /*Feature: Decrease by lack of demand. */
    printf("****after deleting 4 items, the curent size supposed to downsize****\n");
    VectorPrint(vec);
    printf("\n\ntest delete element #3\n"); /*test delete element*/
    VectorDelete(vec, &temp);
    VectorDelete(vec, &temp);
    VectorDelete(vec, &temp);
    VectorDelete(vec, &temp);  /*isnt decreased because te original size is 10. */
    printf("****after deleting 4 items, the curent size is NOT supposed to downsize****\n");
    VectorPrint(vec);
    printf("\n\ntest delete element #4\n"); /*test delete element*/
    tmpVec = VectorCreate(0, 0);
    printf("initializing tmpVec with size=0, blockSize=0\n\n");
    eErr = VectorDelete(tmpVec, temp);
    HandleErr(eErr, "delete from tmpVec (a NULL pointer)");
    VectorPrint(tmpVec);
    VectorDestroy(tmpVec);
    tmpVec = NULL;
    printf("\n\ntest delete element #5\n"); /*test delete element*/
    tmpVec = VectorCreate(0, 1);
    printf("initializing tmpVec with size=0, blockSize=1");
    VectorPrint(tmpVec);
    eErr = VectorDelete(tmpVec, temp);
    HandleErr(eErr, "delete from tmpVec (a NULL pointer)");
    VectorDestroy(tmpVec);
    tmpVec = NULL;
    printf("\n\ntest delete element #6\n"); /*test delete element*/
    tmpVec = VectorCreate(1, 0);
    printf("initializing tmpVec with size=1, blockSize=0");
    VectorPrint(tmpVec); 
    eErr = VectorDelete(tmpVec, temp);
    HandleErr(eErr, "delete from tmpVec (a NULL pointer)");
    VectorDestroy(tmpVec);
    tmpVec = NULL;

    
    /* Test-case 4: Set element    */
    printf("\n\ntest set element #1\n"); /*test set element*/
    eErr = VectorSet(vec, 10, INT_MAX);
    HandleErr(eErr, "adding outside of range (10)");
    printf("\n\ntest set element #2\n"); /*test set element*/
    eErr = VectorSet(vec, 0, INT_MAX);
    HandleErr(eErr, "adding outside of range (0)");
    printf("\n\ntest set element #3\n"); /*test set element*/
    eErr = VectorSet(vec, 2, INT_MAX);
    VectorPrint(vec);
    
    /* Test-case 5: Get element    */
    printf("\n\ntest get element #1\n"); /*test get element*/
    eErr = VectorGet(vec, 1, &temp);
    printf("item gotten : %d\n", temp);
    HandleErr(eErr, "getting item");
    printf("\n\ntest get element #2\n"); /*test get element*/
    temp = -1;
    eErr = VectorGet(vec, 5, &temp);
    printf("item gotten : %d\n", temp);
    HandleErr(eErr, "getting item outside of range (5)");
    printf("\n\ntest get element #3\n"); /*test get element*/
    eErr = VectorGet(vec, -1, &temp);
    printf("item gotten : %d\n", temp);
    HandleErr(eErr, "getting item outside of range (0)");
    
    /* Test-case 6: Vector destroy */
    VectorDestroy(vec);
    vec = NULL;
    tmpVec = VectorCreate(0, 1);
    VectorDestroy(tmpVec);
    VectorPrint(vec);
    return 0;
}