/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  20/7/22
    Last modified date: --
    Description : FIFO, No Growth On Demand, No Direct Access.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "Queue.h"

struct Queue {
    int* vec;
    size_t size;
    size_t numOfItems;
    size_t head;
    size_t tail;
};

Queue_t* QueueCreate(size_t size)
{
    Queue_t* queue;

    if (size == 0)
    {
        return NULL;
    }

    queue = (Queue_t*)malloc(sizeof(Queue_t));
    if (!queue)
    {
        return NULL;
    }

    queue->vec = (int*)malloc(sizeof(int) * size);
    if (!queue->vec)
    {
        free(queue);
        return NULL;
    }
    queue->size = size;
    queue->numOfItems = 0;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

void QueueDestroy(Queue_t* queue)
{
    if (queue)
    {
        free(queue->vec);
        free(queue);
    }
}

ADTErr QueueInsert(Queue_t* queue, int item)
{
    if (!queue)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (queue->numOfItems == queue->size)
    {
        return ERR_OVERFLOW;
    }

    //the tail is the next index to which we can insert an item.
    queue->vec[queue->tail] = item;    
    //we use module in order to stay in the boundries of our queque.
    queue->tail = (queue->tail + 1) % queue->size;
    ++queue->numOfItems;

    return ERR_OK;
}

ADTErr QueueDelete(Queue_t* queue, int* item)
{
    if (!queue || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (queue->numOfItems == 0)
    {
        return ERR_UNDERFLOW;
    }
    
    //the head is the index of the item that got in last.
    *item = queue->vec[queue->head];
    --queue->numOfItems;
    //we use module in order to stay in the boundries of our queque.
    queue->head = (queue->head + 1) % queue->size;

    return ERR_OK;
}

int QueueIsEmpty(Queue_t* queue)
{
    if (!queue || queue->numOfItems > 0)
    {
        return 0;
    }
    return 1;
}

/*    Unit test Functions    */
void QueuePrint(Queue_t* queue)
{
    if (!queue)
    {
        printf("\nqueue is null.\n");
        return;
    }

    printf("\n\n*****************************");
    printf("\n\nQueue details : \n\tsize: % zu\n\tnumber of items : %zu\n\t",
                queue->size, queue->numOfItems);
    printf("head index : % zu\n\ttail index : % zu\n\titems: ",
                 queue->head, queue->tail);
    //we use the i index in order to not try to print an item that doesn't exist,
    //and the j index to follow the items indexes.
    for (int i = 0, j = queue->head; i < queue->numOfItems; i++)
    {
        //if we got th the end of the vector and we still have items to print.
        if (j == queue->size)
        {
            j = 0;
        }
        printf("%d ", queue->vec[j++]);
    }
    printf("\n\n*****************************\n");
}