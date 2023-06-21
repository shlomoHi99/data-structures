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

#define REALLOC_FACTOR 2

struct GenVector
{
    void** items;
    size_t  originalSize;
    size_t  blockSize;
    size_t  currSize;
    size_t  nItems;   
};

GenVector_t* GenVectorCreate(size_t size, size_t blockSize)
{
    GenVector_t* genVector;

    if ((size == 0) && (blockSize == 0) || blockSize > size)
    {
        return NULL;
    }

    genVector = (GenVector_t*)malloc(sizeof(GenVector_t));
    if (!genVector)
    {
        return NULL;
    }

    genVector->items = (void**)malloc(sizeof(void*) * size);
    if (!genVector->items)
    {
        free(genVector);
        return NULL;
    }

    genVector->currSize = size;
    genVector->originalSize = size;
    genVector->blockSize = blockSize;
    genVector->nItems = 0;

    return genVector;
}

void GenVectorDestroy(GenVector_t* genVector)
{
    if (!genVector)
    {
        return;
    }
    free(genVector->items);
    free(genVector);
}

ADTErr    GenVectorAdd(GenVector_t* genVector, void* item)
{
    void** temp;

    if (!genVector)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (genVector->nItems == genVector->currSize)
    {
        if (genVector->blockSize == 0)
        {
            return ERR_OVERFLOW;
        }
        temp = (void**)realloc(genVector->items,
            sizeof(void*) * (genVector->currSize + genVector->blockSize));

        if (!temp)
        {
            return ERR_REALLOCATION_FAILED;
        }
        genVector->items = temp;
        genVector->currSize += genVector->blockSize;
    }

    *(genVector->items + genVector->nItems) = item;
    ++genVector->nItems;

    return ERR_OK;
}

ADTErr    GenVectorDelete(GenVector_t* genVector, void** item)
{
    void** tmp;

    if (!genVector || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (genVector->nItems == 0)
    {
        return ERR_UNDERFLOW;
    }

    if ((genVector->currSize > genVector->originalSize) &&
        (genVector->nItems <= genVector->currSize - (genVector->blockSize * REALLOC_FACTOR)))
    {
        tmp = (void**)realloc(genVector->items,
            sizeof(void*) * (genVector->currSize - genVector->blockSize));
        if (!tmp)
        {
            return (ERR_REALLOCATION_FAILED);
        }
        genVector->items = tmp;
        genVector->currSize -= genVector->blockSize;
    }

    *item = *(genVector->items + genVector->nItems - 1);
    --genVector->nItems;

    return ERR_OK;
}

/* Index from 1 */
ADTErr    GenVectorGet(GenVector_t* genVector, size_t index, void** item)
{
    if (!genVector || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (index > genVector->nItems || index < 1)
    {
        return (ERR_WRONG_INDEX);
    }

    *item = *(genVector->items + index - 1);

    return ERR_OK;
}

/* Index from 1 */
ADTErr    GenVectorSet(GenVector_t* genVector, size_t index, void*  item)
{
    if (!genVector || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    if (index > genVector->nItems || index < 1)
    {
        return ERR_WRONG_INDEX;
    }

    *(genVector->items + index - 1) = item;

    return ERR_OK;
}

ADTErr GenVectorItemsNum(GenVector_t* genVector, size_t* numOfItems)
{
    if (!genVector || !numOfItems)
    {
        return ERR_NOT_INITIALIZED;
    }

    *numOfItems = genVector->nItems;

    return ERR_OK;
}

/*  Unit-Test functions  */

void GenVectorPrint(GenVector_t* genVector, GenPrintFunc_t printFunc)
{
    if (genVector)
    {
        printf("\n********************************************************************************\n");
        printf("genVector details->\n\t\t-original size = %zu\n\t\t-block size = %zu\
                \n\t\t-current size = %zu\n\t\t-number of items = %zu\n\t\t-items:",
                 genVector->originalSize, genVector->blockSize, genVector->currSize, genVector->nItems);
        for (int i = 0; i < genVector->nItems; i++)
        {
            printf(" ");
            printFunc(genVector->items[i]);
        }
        printf("\n\n********************************************************************************\n");
    }
}