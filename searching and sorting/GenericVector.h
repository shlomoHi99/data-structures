/**************************************************************************************
    Author: Shlomo salomon.
    Creation date:  13/7/22
    Last modified date: 30/8/22
    Description: Sequence of elements, Ditect access, Grows on demand, Generic.
***************************************************************************************/
#ifndef __GEN_VECTOR_H__
#define __GEN_VECTOR_H__

typedef struct GenVector GenVector_t;

typedef void (*GenPrintFunc_t)(const void*);

/* size      - The initial allocation size.
   blockSize - The extention block size.    */
GenVector_t* GenVectorCreate(size_t size, size_t blockSize);

void        GenVectorDestroy(GenVector_t* genVector);

/* Add item to end. */
ADTErr      GenVectorAdd(GenVector_t* genVector, void*  item);

/* Delete item from the end. */
ADTErr    GenVectorDelete(GenVector_t* genVector, void** item);

/* The Index range in the following functions is : 1..numOfItems */
ADTErr    GenVectorGet(GenVector_t* genVector, size_t index, void** item);

ADTErr    GenVectorSet(GenVector_t* vector, size_t index, void*  item);

ADTErr    GenVectorItemsNum(GenVector_t* vector, size_t* _numOfItems);


/*  Unit-Test functions  */
void GenVectorPrint(GenVector_t* genVector, GenPrintFunc_t printFunc);

#endif /*__GEN_VECTOR_H__*/