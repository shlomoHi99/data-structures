/**************************************************************************************
    Author: Shlomo salomon.
    Creation date:  31/8/22
    Last modified date: 14/9/22
    Description: Sorting Algorithms.
***************************************************************************************/
#include <assert.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "GenericVector.h"
#include "SortingAlgorithms.h"

//Forward Dclaretion:
void QuickSortImp(GenVector_t* genVec, size_t vecStart, size_t vecEnd, CompareFunc_t compareFunc);
size_t Partition(GenVector_t* genVec, size_t vecStart, size_t vecEnd, CompareFunc_t compareFunc);
void MergeSortImp(GenVector_t* genVec, void** assistenceArr, size_t vecStart, size_t vecEnd, CompareFunc_t compareFunc);
void Merge(GenVector_t* genVec, void** assistenceArr, size_t vecStart, size_t vecEnd, size_t middleIndex, CompareFunc_t compareFunc);

/*                    comparison sorts                     */

/*
*   starting from one side we each iteration bubble the largest item to its place.
*   we do that by comparing each item to the one next to it, if it's smaller we continue 
*   to compare the next item to it's naboure, otherwise we switch between them and compare
*   it to the next item.
*/
void BubbleSort    (GenVector_t* genVec, CompareFunc_t compareFunc)
{
    assert(genVec && compareFunc);

    void* firstItem, * secondItem;
    int didSwap;
    size_t vecLen;

    GenVectorItemsNum(genVec, &vecLen);
    for (size_t timesWentThroughTheVec = 0; timesWentThroughTheVec < vecLen - 1; timesWentThroughTheVec++)
    {
        didSwap = 0;

        //the index of 'vector' starts from 1.
        for (size_t curIndex = 1; curIndex < vecLen - timesWentThroughTheVec; curIndex++)
        {
            GenVectorGet(genVec, curIndex, &firstItem);
            GenVectorGet(genVec, curIndex + 1, &secondItem);
           
            if (compareFunc(firstItem, secondItem) == FIRST_BIGGER)
            {
                GenVectorSet(genVec, curIndex, secondItem);
                GenVectorSet(genVec, curIndex + 1, firstItem);
                didSwap = 1;
            }
        }
        if (!didSwap)
        {
            return;
        }
    }
}

/*
*   we use the same ligic as the bubble sort but each iteration we start from a different
*   side, by doing so, we improve the complexity.
*/
void ShakeSort     (GenVector_t* genVec, CompareFunc_t compareFunc)
{
    assert(genVec && compareFunc);

    void* firstItem, * secondItem;
    int didSwap;
    size_t vecLen;

    GenVectorItemsNum(genVec, &vecLen);
    for (size_t timesWentThroughTheVec = 1; timesWentThroughTheVec < vecLen/2 + 1; timesWentThroughTheVec++)
    {
        didSwap = 0;

        //the index of 'vector' starts from 1.
        for (size_t curIndex = timesWentThroughTheVec; curIndex <= vecLen - timesWentThroughTheVec; curIndex++)
        {
            GenVectorGet(genVec, curIndex, &firstItem);
            GenVectorGet(genVec, curIndex + 1, &secondItem);

            if (compareFunc(firstItem, secondItem) == FIRST_BIGGER)
            {
                GenVectorSet(genVec, curIndex, secondItem);
                GenVectorSet(genVec, curIndex + 1, firstItem);
                didSwap = 1;
            }
        }
        if (!didSwap)
        {
            return;
        }
        for (size_t curIndex = vecLen - timesWentThroughTheVec  ; curIndex > timesWentThroughTheVec; curIndex--)
        {
            GenVectorGet(genVec, curIndex - 1, &firstItem);
            GenVectorGet(genVec, curIndex, &secondItem);

            if (compareFunc(firstItem, secondItem) == FIRST_BIGGER)
            {
                GenVectorSet(genVec, curIndex - 1, secondItem);
                GenVectorSet(genVec, curIndex, firstItem);
                didSwap = 1;
            }
        }
        if (!didSwap)
        {
            return;
        }
    }
}

/*
*     
* 
*/
void InsertionSort (GenVector_t* genVec, CompareFunc_t compareFunc)
{
    assert(genVec && compareFunc);

    void* curItem, * itemToCheck ;
    size_t vecLen;

    GenVectorItemsNum(genVec, &vecLen);
    for (size_t i = 2; i <= vecLen; i++)
    {
        GenVectorGet(genVec, i, &curItem);
        for (size_t j = i - 1; j > 0; j--)
        {
            GenVectorGet(genVec, j, &itemToCheck);
            if (compareFunc(curItem, itemToCheck) == FIRST_SMALLER)
            {
                GenVectorSet(genVec, j + 1, itemToCheck);
                GenVectorSet(genVec, j, curItem);
            }
            else
            {
                break;
            }
        }
    }
}

void SelectionSort (GenVector_t* genVec, CompareFunc_t compareFunc)
{
    assert(genVec && compareFunc);

    void* maxItem, * itemToCheck = NULL;
    size_t vecLen, maxIndex;

    GenVectorItemsNum(genVec, &vecLen);
    for (size_t timesWentThroughTheVec = 0; timesWentThroughTheVec < vecLen - 1; timesWentThroughTheVec++)
    {
        GenVectorGet(genVec, 1, &maxItem);
        maxIndex = 1;
        for (size_t curIndex = 2; curIndex <= vecLen - timesWentThroughTheVec; curIndex++)
        {
            GenVectorGet(genVec, curIndex, &itemToCheck);
            if (compareFunc(itemToCheck, maxItem) == FIRST_BIGGER)
            {
                maxItem = itemToCheck;
                maxIndex = curIndex;
            }
        }
        if (maxIndex != vecLen - timesWentThroughTheVec)
        {
            GenVectorSet(genVec, vecLen - timesWentThroughTheVec, maxItem);
            GenVectorSet(genVec, maxIndex, itemToCheck);
        }
    }
}

void QuickSort(GenVector_t* genVec, CompareFunc_t compareFunc)
{
    assert(genVec && compareFunc);

    size_t vecLen = 0;

    GenVectorItemsNum(genVec, &vecLen);
    QuickSortImp(genVec, 1, vecLen, compareFunc);
}

ADTErr MergeSort     (GenVector_t* genVec, CompareFunc_t compareFunc)
{
    assert(genVec && compareFunc);

    size_t vecLen = 0;

    GenVectorItemsNum(genVec, &vecLen);
    void** assistenceArr = (void**)malloc(sizeof(void*) * vecLen);
    if (!assistenceArr)
    {
        return ERR_ALLOCATION_FAILED;
    }

    MergeSortImp(genVec ,assistenceArr, 1, vecLen, compareFunc);
    free(assistenceArr);

    return ERR_OK;
}

/*                Linear Sorts              */

ADTErr CountingSort(GenVector_t* genVec, ExtractKeyFunc_t extractKeyFunc)
{
    assert(genVec && extractKeyFunc);

    size_t numOfItems, maxKey, curKey;

    GenVectorItemsNum(genVec, &numOfItems);
    if (numOfItems <= 1)
    {
        return ERR_OK;
    }

    void** auxilryArray = (void**)malloc((numOfItems+ 1) * sizeof(void*));
    if (!auxilryArray)
    {
        return ERR_ALLOCATION_FAILED;
    }

    for (size_t curIndex = 1; curIndex <= numOfItems; curIndex++)
    {
        GenVectorGet(genVec, curIndex, &auxilryArray[curIndex]);
    }

    maxKey = extractKeyFunc(auxilryArray[1]);
    for (size_t curIndex = 2; curIndex <= numOfItems; curIndex++)
    {
        curKey = extractKeyFunc(auxilryArray[curIndex]);
        if(maxKey < curKey)
        {
            maxKey = curKey;
        }
    }

    int* countingItemsArray = (int*)calloc((maxKey + 1), sizeof(int));
    if (!countingItemsArray)
    {
        free(auxilryArray);
        return ERR_ALLOCATION_FAILED;
    }

    for (size_t curIndex = 1; curIndex <= numOfItems; curIndex++)
    {
        ++countingItemsArray[extractKeyFunc(auxilryArray[curIndex])];
    }

    for (size_t curIndex = 2; curIndex <= maxKey; curIndex++)
    {
        countingItemsArray[curIndex] += countingItemsArray[curIndex - 1];
    }

    for (size_t curIndex = numOfItems; curIndex > 0 ; curIndex--)
    {
        GenVectorSet(genVec, countingItemsArray[extractKeyFunc(auxilryArray[curIndex])]--, auxilryArray[curIndex]);
    }

    free(auxilryArray);
    free(countingItemsArray);

    return ERR_OK;
}

ADTErr RadixSort(GenVector_t* genVec, ExtractKeyFunc_t extractKeyFunc)
{
    assert(genVec && extractKeyFunc);

    size_t vecLen = 0, divisionFactor = 1, calculatedIndex;
    int maxDigit = 0, curKey;
    void* curItem;
    int digitsArray[10] = {0};

    GenVectorItemsNum(genVec, &vecLen);
    if (vecLen <= 1)
    {
        return ERR_OK;
    }

    void** auxilryArray = (void**)malloc(sizeof(void*) * (vecLen + 1));
    if (!auxilryArray)
    {
        return ERR_ALLOCATION_FAILED;
    }

    for (size_t curIndex = 1; curIndex <= vecLen; curIndex++)
    {
        GenVectorGet(genVec, curIndex, &curItem);
        curKey = extractKeyFunc(curItem);
        if (curKey > maxDigit)
        {
            maxDigit = curKey;
        }
    }

    while (maxDigit)
    {
        for (size_t curIndex = 1; curIndex <= vecLen; curIndex++)
        {
            GenVectorGet(genVec, curIndex, &auxilryArray[curIndex]);
        }

        for (size_t curIndex = 1; curIndex <= vecLen; curIndex++)
        {
            ++digitsArray[extractKeyFunc(auxilryArray[curIndex]) / divisionFactor % 10];
        }

        for (size_t i = 1; i < 10; i++)
        {
            digitsArray[i] += digitsArray[i - 1];
        }

        for (size_t curIndex = vecLen; curIndex >= 1; curIndex--)
        {
            calculatedIndex = digitsArray[extractKeyFunc(auxilryArray[curIndex]) / divisionFactor % 10]--;
            GenVectorSet(genVec, calculatedIndex, auxilryArray[curIndex]);
        }

        divisionFactor *= 10;
        maxDigit /= 10;

        for (size_t i = 0; i < 10; i++)
        {
            digitsArray[i] = 0;
        }

    }

    free(auxilryArray);

    return ERR_OK;
}

/*     sub functions for the comparison sorting functions      */

//  a recursive implementation of quick sort
void QuickSortImp(GenVector_t* genVec, size_t vecStart, size_t vecEnd, CompareFunc_t compareFunc)
{
    if (vecStart >= vecEnd)
    {
        return;
    }

    size_t pivotIndex = Partition(genVec, vecStart, vecEnd, compareFunc);
    QuickSortImp(genVec, vecStart, pivotIndex, compareFunc);
    QuickSortImp(genVec, pivotIndex + 1, vecEnd, compareFunc);
}

//  quick sort uses partition function to split the vector in a way that every item
//  in the left part is smaller than every item in the right part.
size_t Partition(GenVector_t* genVec, size_t vecStart, size_t vecEnd, CompareFunc_t compareFunc)
{
    void* leftItem, * rightItem, *pivot;

    //the pivot is the item to which we compare every item in the vector
    //to know if it belongs in the right half or the left half.
    //we pick the first item in the vector to be the pivot.
    GenVectorGet(genVec, vecStart, &pivot);
    //we need to move the index of the start and end in order to immidietly
    //start working on the right index.
    --vecStart;
    ++vecEnd;

    while ( vecStart < vecEnd)
    {
        do {
            GenVectorGet(genVec, ++vecStart, &leftItem);
        } while (compareFunc(leftItem, pivot) == FIRST_SMALLER);

        do {
            GenVectorGet(genVec, --vecEnd, &rightItem);
        } while (compareFunc(rightItem, pivot) == FIRST_BIGGER);
        
        if (vecStart < vecEnd)
        {
            GenVectorSet(genVec, vecStart, rightItem);
            GenVectorSet(genVec, vecEnd, leftItem);
        }
    }
    return vecEnd;
}

//  a recursive implementation of merge sort.
void MergeSortImp(GenVector_t* genVec, void** assistenceArr, size_t vecStart, size_t vecEnd, CompareFunc_t compareFunc)
{
    if (vecStart >= vecEnd)
    {
        return;
    }

    size_t middleIndex = (vecStart + vecEnd) / 2;
    MergeSortImp(genVec, assistenceArr, vecStart, middleIndex, compareFunc);
    MergeSortImp(genVec, assistenceArr, middleIndex + 1, vecEnd, compareFunc);
    Merge(genVec, assistenceArr, vecStart, vecEnd, middleIndex, compareFunc);
}

//  merge sort uses merge function when given two sorted sub arrays we merge them together into one array.
void Merge(GenVector_t* genVec, void** assistenceArr, size_t vecStart, size_t vecEnd, size_t middleIndex, CompareFunc_t compareFunc)
{
    size_t firstVecIndex, secondVecIndex;

    firstVecIndex = vecStart - 1;
    secondVecIndex = middleIndex;

    //first we copy the two sub arrays to a new array using the same indexes.
    for (size_t curIndex = vecStart; curIndex <= vecEnd; curIndex++)
    {
        GenVectorGet(genVec, curIndex, &assistenceArr[curIndex - 1]);
    }


    //now we compare every current item in the first sub array to the current item
    //in the second sub array and copy the items in order to the vector.
    for (size_t curIndex = vecStart; curIndex <= vecEnd; curIndex++)
    {
        if (firstVecIndex < middleIndex && secondVecIndex < vecEnd &&
            compareFunc(assistenceArr[firstVecIndex], assistenceArr[secondVecIndex]) == FIRST_SMALLER)
        {
            GenVectorSet(genVec, curIndex, assistenceArr[firstVecIndex++]);
        }
        else if (secondVecIndex < vecEnd)
        {
            GenVectorSet(genVec, curIndex, assistenceArr[secondVecIndex++]);
        }
        else
        {
            GenVectorSet(genVec, curIndex, assistenceArr[firstVecIndex++]);
        }
    }
}
