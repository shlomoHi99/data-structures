/**************************************************************************************
    Author: Dudi Kahana
    Creation date :  28/6/22
    Last modified date: 10/8/22
    Description : ADT General definitions.
***************************************************************************************/
#include <stdio.h>

#include "ADTDefs.h"

const char* ErrDescription[] =
{
    /* General ADT Errors - Description */
    "OK",
    "General Error",
    "Initialization error",
    "Allocation error",
    "ReAllocation error",
    "Underflow error",
    "Overflow error",
    "Wrong index",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    /* Vector Errors */

    /* Stack  Errors */
    "BLABLABLA",
    "",
    "",
    "",
    "",

    /*Binary Search Tree Errors*/
    "node exist already in the tree"

    /* LinkedList  Errors */


    /* Bit Vector*/


};

void HandleErr(ADTErr errNum, char* msg)
{
    if (errNum)
    {
        printf("ErrNum=%d, ErrDescription=%s, msg=%s\n",
            errNum, ErrDescription[errNum], msg);
    }

}
