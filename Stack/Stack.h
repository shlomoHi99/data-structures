/**************************************************************************************
    Author: Shlomo salomon.
    Creation date:  7/7/22
    Last modified date: 8/7/22
    Description: Last in first out, Grows on demand, No direct access.
***************************************************************************************/
#ifndef __STACK_H__
#define __STACK_H__

typedef struct Stack Stack_t;

/* size      - The initial allocation size.
   blockSize - The extention block size.    */
Stack_t*    StackCreate(size_t size, size_t blockSize);

void        StackDestroy(Stack_t* stack);

/*add item to top*/
ADTErr      StackPush(Stack_t* stack, int item);

/*delete item from the top*/
ADTErr      StackPop(Stack_t* stack, int* item);

ADTErr      StackTop(Stack_t* stack, int* item);

int         StackIsEmpty(Stack_t* stack);



/*    unit test functions    */
void        StackPrint(Stack_t* stack);

#endif /*__STACK_H__*/