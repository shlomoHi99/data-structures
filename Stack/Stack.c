/**************************************************************************************
    Author: Shlomo salomon.
    Creation date:  7/7/22
    Last modified date: 8/7/22
    Description: Last in first out, Grows on demand, No direct access.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "Vector.h"
#include "Stack.h"

//we implemented the stack using a simple vector
//wraped in a way to have LIFO attributes.
struct Stack
{
    Vector_t* vector;
};

Stack_t* StackCreate(size_t size, size_t blockSize)
{
    Stack_t* stack = (Stack_t*)malloc(sizeof(Stack_t));
    if (!stack)
    {
        return NULL;
    }
   
    stack->vector = VectorCreate(size, blockSize);
    if (!stack->vector)
    {
        free(stack);
        return NULL;
    }
    return stack;
}

void StackDestroy(Stack_t* stack)
{
    if (stack)
    {
       VectorDestroy(stack->vector);
        free(stack);
    }    
}

ADTErr   StackPush(Stack_t* stack, int item)
{
    if (!stack)
    {
        return ERR_NOT_INITIALIZED;
    }

    return VectorAdd(stack->vector, item);
}

ADTErr   StackPop(Stack_t* stack, int* item)
{
    if (!stack)
    {
        return ERR_NOT_INITIALIZED;
    }

    return VectorDelete(stack->vector, item);
}

ADTErr   StackTop(Stack_t* stack, int* item)
{   
    size_t index;
    //if the stack does not exist or the VectorItemNum returns an error code different from 0.
    if (!stack || VectorItemsNum(stack->vector, &index))
    {
        return ERR_NOT_INITIALIZED;
    }

    return VectorGet(stack->vector, index, item);
}

int   StackIsEmpty(Stack_t* stack)
{
    size_t nItems;
    ADTErr errCode;

    if (!stack)
    {
        return 0;
    }
    errCode = VectorItemsNum(stack->vector, &nItems);
    //if the the function return an error code different fron 0 
    //or the number of items is different from 0 the stack is not empty.
    if (errCode || nItems)
    {
        return 0;
    }
    return 1;
}

/*    unit test functions    */
void StackPrint(Stack_t* stack)
{
    if (stack)
    {
        VectorPrint(stack->vector, "Stack");
    }
}