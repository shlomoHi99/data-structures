/**************************************************************************************
    Author: Shlomo salomon.
    Creation date:  31/8/22
    Last modified date: 14/9/22
    Description: Sorting Algorithms.
***************************************************************************************/
#ifndef __SORTING_ALGORITHMS_H__
#define __SORTING_ALGORITHMS_H__

typedef int (*CompareFunc_t)(const void*, const void*);

typedef int (*ExtractKeyFunc_t)(const void*);

//compare func return int, it returns 0 if equal,
//  1 if first > second and -1 if first < second
typedef enum ComareStatus
{
    FIRST_BIGGER  =  1,
    EQUAL         =  0,
    FIRST_SMALLER = -1
}ComareStatus_t;

/*                    comparison sorts                     */

/*  The Omega(the minimal time complexity) is: O(n log n)  */


/*          Bubble Sort           */
/*
    time complexity : best case  -O(n) - sorted
                      worst case - O(n^2) - randonly built
    memory complexity: in place, O(1)
*/
void BubbleSort(GenVector_t* genVec, CompareFunc_t compareFunc);

/*          Shake Sort            */
/*
    time complexity : best case  -O(n) - sorted
                      worst case - O(n^2) - randonly built
    memory complexity: in place, O(1)
*/
void ShakeSort(GenVector_t* genVec, CompareFunc_t compareFunc);

/*         Insertion Sort         */
/*
    time complexity : best case  -O(n) - sorted
                      worst case - O(n^2) - randonly built
    memory complexity: in place, O(1)
*/
void InsertionSort(GenVector_t* genVec, CompareFunc_t compareFunc);

/*     Selection Sort     */
/*
    time complexity : O(n ^ 2)
    memory complexity: in place, O(1)
*/
void SelectionSort(GenVector_t* genVec, CompareFunc_t compareFunc);

/*       Quick Sort       */
/*
    time complexity : best case  -O(n log n) - randonly built
                       worst case - O(n^2)     - sorted
    memory complexity: sorting wise        - in place, O(1)
                       including recursion - best case  - O(log n) - randonly built
                                           - worst case - O(n)     - sorted
*/
void QuickSort(GenVector_t* genVec, CompareFunc_t compareFunc);

/*       Merge Sort       */
/*
    time complexity : O(n log n)
    memory complexity: sorting wise        - O(n)
                       including recursion - O(n log n)
*/
ADTErr MergeSort(GenVector_t* genVec, CompareFunc_t compareFunc);


/*                Linear Sorts              */

/* When given some type of information we can achive a time complexity of O(n) */

/*          Counting Sort           */
/*
    time complexity :  O(n)
    memory complexity: O(n)
*/
ADTErr CountingSort(GenVector_t* genVec, ExtractKeyFunc_t extractKeyFunc);

/*          Radix Sort           */
/*
    time complexity :  O(n)
    memory complexity: O(n)
*/
ADTErr RadixSort(GenVector_t* genVec, ExtractKeyFunc_t extractKeyFunc);

#endif // !__SORTING_ALGORITHMS_H__
