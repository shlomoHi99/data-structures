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

#include "ADTDefs.h"
#include "Vector.h"
#include "Heap.h"

void UnitTest();

void main()
{
    UnitTest();

    
}

void UnitTest()
{
    int temp = INT_MIN;

    Vector_t* vec = VectorCreate(5, 3);
    VectorAdd(vec, 1);
    VectorAdd(vec, 3);
    /*VectorAdd(vec, 56);
    VectorAdd(vec, 56);*/
    VectorAdd(vec, 2);
    VectorAdd(vec, 4);
    //VectorAdd(vec, 15);
    VectorAdd(vec, 5);
    //VectorAdd(vec, 135);*/

    VectorPrint(vec);
    Heap_t* heap = BinHeapBuild(vec);
    VectorPrint(vec);
    BinHeapRemove(heap, &temp);
    printf("item removed: %d\n", temp);
    BinHeapRemove(heap, &temp);
    printf("item removed: %d\n", temp);
    BinHeapInsert(heap, 120);
    VectorPrint(vec);
    BinHeapMax(heap, &temp);
    printf("the top (max value) item: %d\n", temp);

    BinHeapDestroy(heap);
    VectorDestroy(vec);
}



