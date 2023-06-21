/**************************************************************************************
    Author: Shlomo salomon.
    Creation date:  20/9/22
    Last modified date: --
    Description: Searching Algorithms.
***************************************************************************************/
#include <assert.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "GenericVector.h"
#include "SortingAlgorithms.h"
#include "SearchingAlgorithms.h"

//Forward Declaretion:
size_t  BinSearchRecImp(GenVector_t* vec, void* item, CompareFunc_t compFunc, size_t startIndex, size_t endIndex);

size_t  BinSearchIter(GenVector_t* vec, void* item, CompareFunc_t compFunc)
{
    assert(vec && item && compFunc);

    size_t vecEnd, vecStart = 1, middleIndex;
    void* curItem;
    int comparisonOutcome;

    GenVectorItemsNum(vec, &vecEnd);
    while (vecStart <= vecEnd)
    {
        middleIndex = (vecEnd + vecStart) / 2;
        GenVectorGet(vec, middleIndex, &curItem);
        comparisonOutcome = compFunc(curItem, item);
        if (comparisonOutcome == FIRST_BIGGER)
        {
            vecEnd = middleIndex - 1;
        }
        else if (comparisonOutcome == FIRST_SMALLER)
        {
            vecStart = middleIndex + 1;
        }
        else
        {
            return middleIndex;
        }
    }
    
    return 0;
}

size_t  BinSearchRec(GenVector_t* vec, void* item, CompareFunc_t compFunc)
{
    assert(vec && item && compFunc);

    size_t vecLen;

    GenVectorItemsNum(vec, &vecLen);

    return BinSearchRecImp(vec, item, compFunc, 1, vecLen);
}

size_t  BinSearchRecImp(GenVector_t* vec, void* item, CompareFunc_t compFunc, size_t startIndex, size_t endIndex)
{
    int comparisonOutcome;
    size_t middleIndex;
    void* curItem;

    if (startIndex > endIndex)
    {
        return 0;
    }

    middleIndex = (startIndex + endIndex) / 2;
    GenVectorGet(vec, middleIndex, &curItem);
    comparisonOutcome = compFunc(curItem, item);
    if (comparisonOutcome == FIRST_BIGGER)
    {
        return BinSearchRecImp(vec, item, compFunc, startIndex, middleIndex - 1);
    }
    else if (comparisonOutcome == FIRST_SMALLER)
    {
        return BinSearchRecImp(vec, item, compFunc, middleIndex + 1, endIndex);
    }
    else
    {
        return middleIndex;
    }
}

