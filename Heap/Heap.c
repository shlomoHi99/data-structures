/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  17/8/22
    Last modified date: --
    Description : Heap using vector Implementation: 
                                -Every node is bigger or equal to it's decendents.
                                -All the leaves are on the n level or n-1 level.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ADTDefs.h"
#include "Vector.h"
#include "Heap.h"

struct Heap
{
    Vector_t* vec;
    size_t heapSize;
};

//Forward declaretions:
void Heapify(Heap_t* heap, size_t index);
void VectorSwap(Vector_t* vec, size_t index1, size_t index2, int item1, int item2);
void BringUpToPlace(Heap_t* heap, size_t index);

Heap_t* BinHeapBuild(Vector_t* vec)
{
    assert(vec);

    Heap_t* heap = (Heap_t*)calloc(1, sizeof(Heap_t));
    if (!heap)
    {
        return NULL;
    }

    heap->vec = vec;
    VectorItemsNum(vec, &heap->heapSize);

    for (size_t i = heap->heapSize / 2; i > 0; i--)
    {
        Heapify(heap, i);
    }
    return heap;
}

//a sub function serving HeapBuild.
void Heapify(Heap_t* heap, size_t index)
{
    //If the function got to the point where item in index
    //has no sons, it means we got to the bottom of the heap.
    if (2 * index > heap->heapSize)
    {
        return;
    }

    int item, left, right = INT_MIN;

    VectorGet(heap->vec, index, &item);
    VectorGet(heap->vec, 2 * index, &left);
    if (2 * index + 1 <= heap->heapSize)
    {
        VectorGet(heap->vec, 2 * index + 1, &right);
    }

    if (left > item && left >= right)
    {
        VectorSwap(heap->vec, index, 2 * index, item, left);
        Heapify(heap, 2 * index);
    }
    else if (right > item)
    {
        VectorSwap(heap->vec, index, 2 * index + 1, item, right);
        Heapify(heap, 2 * index + 1);
    }
}

//a sub function for swaping items inside a vector.
void VectorSwap(Vector_t* vec, size_t index1, size_t index2, int item1, int item2)
{
    VectorSet(vec, index1, item2);
    VectorSet(vec, index2, item1);
}

void BinHeapDestroy(Heap_t* heap)
{
    assert(heap);

    free(heap);
}

ADTErr BinHeapInsert(Heap_t* heap, int item)
{
    assert(heap);

    ADTErr errCode = VectorAdd(heap->vec, item);
    if (errCode)
    {
        return errCode;
    }
    ++heap->heapSize;
    BringUpToPlace(heap, heap->heapSize);

    return ERR_OK;
}

void BringUpToPlace(Heap_t* heap, size_t index)
{
    if (index/2 <= 0)
    {
        return;
    }

    int item, father;
    VectorGet(heap->vec, index, &item);
    VectorGet(heap->vec, index / 2, &father);

    if (item > father)
    {
        VectorSwap(heap->vec, index, index / 2, item, father);
        BringUpToPlace(heap, index / 2);
    }
}

ADTErr BinHeapMax(Heap_t* heap, int* item)
{
    assert(heap && item);

    if (heap->heapSize == 0)
    {
        return ERR_NOT_INITIALIZED;
    }

    VectorGet(heap->vec, 1, item);
    return ERR_OK;
}

ADTErr BinHeapRemove(Heap_t* heap, int* item)
{
    assert(heap && item);

    if (heap->heapSize == 0)
    {
        return ERR_UNDERFLOW;
    }

    int lastItem;
    VectorGet(heap->vec, 1, item);
    VectorDelete(heap->vec, &lastItem);
    if (heap->heapSize > 1)
    {
        VectorSet(heap->vec, 1, lastItem);
    }
    Heapify(heap, 1);
    --heap->heapSize;

    return ERR_OK;
}

ADTErr BinHeapItemsNum(Heap_t* heap, size_t* heapSize)
{
    assert(heap && heapSize);

    *heapSize = heap->heapSize;
    return ERR_OK;
}