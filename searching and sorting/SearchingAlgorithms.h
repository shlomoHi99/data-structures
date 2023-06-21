/**************************************************************************************
    Author: Shlomo salomon.
    Creation date:  20/9/22
    Last modified date: --
    Description: Searching Algorithms.
***************************************************************************************/
#ifndef __SEARCHING_ALGORITHMS_H__
#define __SEARCHING_ALGORITHMS_H__

/*     Binary Search     */
size_t  BinSearchIter(GenVector_t* vec, void* item, CompareFunc_t compFunc);

size_t  BinSearchRec(GenVector_t* vec, void* item, CompareFunc_t compFunc);

/*     Jump Search       */

#endif // !__SEARCHING_ALGORITHMS_H__
