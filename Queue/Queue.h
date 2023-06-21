/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  20/7/22
    Last modified date: --
    Description : FIFO, No Growth On Demand, No Direct Access.
***************************************************************************************/
#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct Queue Queue_t;

Queue_t* QueueCreate(size_t size);

void QueueDestroy(Queue_t* queue);

ADTErr QueueInsert(Queue_t* queue, int item);

ADTErr QueueDelete(Queue_t* queue, int* item);

int QueueIsEmpty(Queue_t* queue);

/*    Unit test Functions    */
void QueuePrint(Queue_t* queue);

#endif // __QUEUE_H__

