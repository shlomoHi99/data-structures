/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  17/8/22
    Last modified date: --
    Description : Heap using vector Implementation:
                                -Every node is bigger or equal to it's decendents.
                                -All the leaves are on the n level or n-1 level.
***************************************************************************************/
#ifndef __HEAP_H__
#define __HEAP_H__

typedef struct Heap Heap_t;

Heap_t* BinHeapBuild(Vector_t* vec);

void BinHeapDestroy(Heap_t* heap);

ADTErr BinHeapInsert(Heap_t* heap, int item);

ADTErr BinHeapMax(Heap_t* heap, int* item);

ADTErr BinHeapRemove(Heap_t* heap, int* item);

ADTErr BinHeapItemsNum(Heap_t* heap, size_t* heapSize);

#endif // !__HEAP_H__
