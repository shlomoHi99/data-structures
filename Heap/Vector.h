/**************************************************************************************
    Author: Dudi Kahana.
    Creation date:  28/6/22
    Last modified date: --
    Description: Sequence of elements, Direct access, Grows on demand.
***************************************************************************************/
#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct Vector Vector_t;

/* size      - The initial allocation size.
   blockSize - The extention block size.    */
Vector_t* VectorCreate(size_t _size, size_t blockSize);

void      VectorDestroy(Vector_t* vector);

/* Add item to end. */
ADTErr    VectorAdd(Vector_t* vector, int  item);

/* Delete item from the end. */
ADTErr    VectorDelete(Vector_t* vector, int* item);

/* The Index range in the following functions is : 1..numOfItems */
ADTErr    VectorGet(Vector_t* vector, size_t index, int* item);

ADTErr    VectorSet(Vector_t* vector, size_t index, int  item);

ADTErr    VectorItemsNum(Vector_t* vector, size_t* _numOfItems);


/*  Unit-Test functions  */
void      VectorPrint(Vector_t* vector);

#endif /*__VECTOR_H__*/