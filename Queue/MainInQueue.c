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

void UnitTestsForQueue();
void UnitTestForGetDiffrence();
Queue_t* GetDifferenceOfEveryTwoItemsInQueue(Queue_t* queue, size_t size);
void UnitTestsForChangeANumber();
void ChangeANumberInQueue(Queue_t* queue, size_t size, int num1, int num2);
void UnitTestForDevideQueue();
void DevideEvenAndOddInQueue(Queue_t* queue, int nItems);

void main()
{
	//UnitTestsForQueue();
	//UnitTestForGetDiffrence();
	//UnitTestsForChangeANumber();
	UnitTestForDevideQueue();
}

void UnitTestsForQueue()
{
	Queue_t* que;
	Queue_t* emptyQue;
	ADTErr err;
	int temp;


	/*   unit tests for create function   */
	que = QueueCreate(5);
	QueuePrint(que);
	emptyQue = QueueCreate(0);
	QueuePrint(emptyQue);

	/*   unit tests for enqueue function   */
	QueueInsert(que, 5);
	QueuePrint(que);
	err = QueueInsert(emptyQue, 7);
	HandleErr(err, "enqueueing an null queue");
	QueuePrint(emptyQue);
	QueueInsert(que, 4);
	QueueInsert(que, 3);
	QueueInsert(que, 2);
	QueueInsert(que, 1);
	err = QueueInsert(que, 6);
	HandleErr(err, "enqueue to a full queue queue");
	QueuePrint(que);

	/*   unit tests for dequeue function   */
	QueueDelete(que, &temp);
	QueuePrint(que);
	printf("item deleted: %d\n", temp);
	err = QueueDelete(emptyQue, &temp);
	HandleErr(err, "dequeue from an null queue");
	QueuePrint(emptyQue);
	printf("item deleted: %d\n", temp);
	QueueDelete(que, &temp);
	QueueDelete(que, &temp);
	QueueDelete(que, &temp);
	QueueDelete(que, &temp);
	err = QueueDelete(que, &temp);
	HandleErr(err, "dequeue from an empty queue");
	QueuePrint(emptyQue);

	/*   unit tests for is empty function   */
	QueuePrint(que);
	QueueIsEmpty(que) ? printf("queue is empty\n") : printf("queue is not empty\n");
	QueueInsert(que, 2);
	printf("adding 2 into queue\n");
	QueueIsEmpty(que) ? printf("queue is empty\n") : printf("queue is not empty\n");
	QueuePrint(emptyQue);
	QueueIsEmpty(emptyQue) ? printf("queue is empty\n") : printf("queue is not empty\n");

	/*   unit tests for destroy function   */
	QueueDestroy(que);
	que = NULL;
	QueueDestroy(emptyQue);
	emptyQue = NULL;
}

void UnitTestForGetDiffrence()
{
	Queue_t* mainQue;
	Queue_t* diffQue;
	size_t size = 6;

	mainQue = QueueCreate(size);
	QueueInsert(mainQue, 17);
	QueueInsert(mainQue, 2);	
	QueueInsert(mainQue, 6);
	QueueInsert(mainQue, 4);
	QueueInsert(mainQue, 15);
	QueueInsert(mainQue, 1);
	diffQue = GetDifferenceOfEveryTwoItemsInQueue(mainQue, size);
	QueuePrint(mainQue);
	QueuePrint(diffQue);
	QueueDestroy(mainQue);
	QueueDestroy(diffQue);

}

Queue_t* GetDifferenceOfEveryTwoItemsInQueue(Queue_t* queue, size_t size)
{
	Queue_t* diffQue;
	int firstNum, secondNum = 0;

	diffQue = QueueCreate(size - 1);
	if (!diffQue)
	{
		printf("ERROR: not enough memory!");
		exit(1);
	}
	QueueDelete(queue, &firstNum);	
	for (int i = 0; i < size - 1; i++)
	{
		secondNum = firstNum;
		QueueInsert(queue, secondNum);
		QueueDelete(queue, &firstNum);
		QueueInsert(diffQue, secondNum - firstNum);
	}
	QueueInsert(queue, firstNum);
	return diffQue;
}

void UnitTestsForChangeANumber()
{
	Queue_t* mainQue;
	size_t size = 9;

	mainQue = QueueCreate(size);
	QueueInsert(mainQue, 1);
	QueueInsert(mainQue, 17);
	QueueInsert(mainQue, 1);
	QueueInsert(mainQue, 2);
	QueueInsert(mainQue, 6);
	QueueInsert(mainQue, 1);
	QueueInsert(mainQue, 4);
	QueueInsert(mainQue, 15);
	QueueInsert(mainQue, 1);
	ChangeANumberInQueue(mainQue, size, 1, 5);
	QueuePrint(mainQue);
	QueueDestroy(mainQue);
}

void ChangeANumberInQueue(Queue_t* queue, size_t size, int num1, int num2)
{
	int temp;

	for (int i = 0; i < size; i++)
	{
		QueueDelete(queue, &temp);
		if (temp == num1)
		{
			QueueInsert(queue, num2);
		}
		else
		{
			QueueInsert(queue, temp);
		}
	}
}

void UnitTestForDevideQueue()
{
	Queue_t* mainQue;
	size_t size = 9;

	mainQue = QueueCreate(size);
	QueueInsert(mainQue, 1);
	QueueInsert(mainQue, 17);
	QueueInsert(mainQue, 1);
	QueueInsert(mainQue, 2);
	QueueInsert(mainQue, 6);
	QueueInsert(mainQue, 1);
	QueueInsert(mainQue, 4);
	QueueInsert(mainQue, 15);
	QueueInsert(mainQue, 1);
	DevideEvenAndOddInQueue(mainQue, size);
	QueuePrint(mainQue);
	QueueDestroy(mainQue);
}

void DevideEvenAndOddInQueue(Queue_t* queue, int nItems)
{
	Queue_t* odds;
	int curNum;

	odds = QueueCreate(nItems);
	if (!odds)
	{
		printf("ERROR: not enough memory!");
		exit(1);
	}

	for (int i = 0; i < nItems; i++)
	{
		QueueDelete(queue, &curNum);
		if (curNum % 2 == 0)
		{
			QueueInsert(queue, curNum);
		}
		else
		{
			QueueInsert(odds, curNum);
		}
	}
	while (!QueueDelete(odds, &curNum))
	{
		QueueInsert(queue, curNum);
	}
}