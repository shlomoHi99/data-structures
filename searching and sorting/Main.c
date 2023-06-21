/**************************************************************************************
    Author: Shlomo salomon.
    Creation date:  31/8/22
    Last modified date: 20/9/22
    Description: Sorting Algorithms.
***************************************************************************************/
#include <stdio.h>
#include <string.h>

#include "ADTDefs.h"
#include "GenericVector.h"
#include "SortingAlgorithms.h"
#include "SearchingAlgorithms.h"

typedef struct Person {
    char name[10];
    size_t age;
    size_t ID;
}Person_t;

//forward declaretion
void UnitTestForBubbleSort();
void UnitTestForShakeSort();
void UnitTestForInsertionSort();
void UnitTestForSelectionSort();
void UnitTestForQuickSort();
void UnitTestForMergeSort();
void UnitTestForCountingSort();
void UnitTestForRadixSort();
void UnitTestForBinSearchIter();
void UnitTestForBinSearchRec();
int CompareInt(const void* item1, const void* item2);
int CompareIntOpposite(const void* item1, const void* item2);
void PrintInt(const void* n);
void PrintPerson(const void* p);
int ComparePerson(const void* item1, const void* item2);
int GetKeyInt(const void* item);
int GetKeyPersonAge(const void* item);
int GetKeyPersonID(const void* item);

void main()
{
    //UnitTestForBubbleSort();
    
    //UnitTestForShakeSort();

    //UnitTestForInsertionSort();

    //UnitTestForSelectionSort();

    //UnitTestForQuickSort();
    
    //UnitTestForMergeSort();

    //UnitTestForCountingSort();

    //UnitTestForRadixSort();

    UnitTestForBinSearchIter();

    UnitTestForBinSearchRec();
}

void UnitTestForBubbleSort()
{
    int n1 = 3546, n2 = 62273, n3 = 4231, n4 = 112, n5 = 334, n6 = 4388, n7 = 394, n8 = 474;

    GenVector_t* vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &n1);
    GenVectorAdd(vec, &n2);
    GenVectorAdd(vec, &n3);
    GenVectorAdd(vec, &n4);
    GenVectorAdd(vec, &n5);
    GenVectorAdd(vec, &n6);

    BubbleSort(vec, CompareInt);
    GenVectorPrint(vec, PrintInt);
    BubbleSort(vec, CompareIntOpposite);
    GenVectorPrint(vec, PrintInt);

    GenVectorDestroy(vec);


    Person_t p1 = { "shlomo", 23 };
    Person_t p2 = { "chaim", 27 };
    Person_t p3 = { "yoel", 19 };
    Person_t p4 = { "yechiel", 29 };
    Person_t p5 = { "menachem", 27 };
    Person_t p6 = { "shlomo", 22 };

    vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &p1);
    GenVectorAdd(vec, &p2);
    GenVectorAdd(vec, &p3);
    GenVectorAdd(vec, &p4);
    GenVectorAdd(vec, &p5);
    GenVectorAdd(vec, &p6);

    BubbleSort(vec, ComparePerson);
    GenVectorPrint(vec, PrintPerson);

    GenVectorDestroy(vec);

}

void UnitTestForShakeSort()
{
    int n1 = 46, n2 = 7, n3 = 19, n4 = 16, n5 = 37, n6 = 9;

    GenVector_t* vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &n1);
    GenVectorAdd(vec, &n2);
    GenVectorAdd(vec, &n3);
    GenVectorAdd(vec, &n4);
    GenVectorAdd(vec, &n5);
    GenVectorAdd(vec, &n6);

    ShakeSort(vec, CompareInt);
    GenVectorPrint(vec, PrintInt);
    ShakeSort(vec, CompareIntOpposite);
    GenVectorPrint(vec, PrintInt);

    GenVectorDestroy(vec);

    Person_t p1 = { "shlomo", 23 };
    Person_t p2 = { "chaim", 27 };
    Person_t p3 = { "yoel", 19 };
    Person_t p4 = { "yechiel", 29 };
    Person_t p5 = { "menachem", 27 };
    Person_t p6 = { "shlomo", 22 };

    vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &p1);
    GenVectorAdd(vec, &p2);
    GenVectorAdd(vec, &p3);
    GenVectorAdd(vec, &p4);
    GenVectorAdd(vec, &p5);
    GenVectorAdd(vec, &p6);

    ShakeSort(vec, ComparePerson);
    GenVectorPrint(vec, PrintPerson);

    GenVectorDestroy(vec);

    
}

void UnitTestForInsertionSort()
{
    int n1 = 46, n2 = 7, n3 = 19, n4 = 16, n5 = 37, n6 = 9;

    GenVector_t* vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &n1);
    GenVectorAdd(vec, &n2);
    GenVectorAdd(vec, &n3);
    GenVectorAdd(vec, &n4);
    GenVectorAdd(vec, &n5);
    GenVectorAdd(vec, &n6);

    InsertionSort(vec, CompareInt);
    GenVectorPrint(vec, PrintInt);
    InsertionSort(vec, CompareIntOpposite);
    GenVectorPrint(vec, PrintInt);

    GenVectorDestroy(vec);

    Person_t p1 = { "shlomo", 23 };
    Person_t p2 = { "chaim", 27 };
    Person_t p3 = { "yoel", 19 };
    Person_t p4 = { "yechiel", 29 };
    Person_t p5 = { "menachem", 27 };
    Person_t p6 = { "shlomo", 22 };

    vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &p1);
    GenVectorAdd(vec, &p2);
    GenVectorAdd(vec, &p3);
    GenVectorAdd(vec, &p4);
    GenVectorAdd(vec, &p5);
    GenVectorAdd(vec, &p6);

    InsertionSort(vec, ComparePerson);
    GenVectorPrint(vec, PrintPerson);

    GenVectorDestroy(vec);


}

void UnitTestForSelectionSort()
{
    int n1 = 5, n2 = 7, n3 = 3, n4 = 8, n5 = 6, n6 = 9;

    GenVector_t* vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &n1);
    GenVectorAdd(vec, &n2);
    GenVectorAdd(vec, &n3);
    GenVectorAdd(vec, &n4);
    GenVectorAdd(vec, &n5);
    GenVectorAdd(vec, &n6);

    SelectionSort(vec, CompareInt);
    GenVectorPrint(vec, PrintInt);
    SelectionSort(vec, CompareIntOpposite);
    GenVectorPrint(vec, PrintInt);

    GenVectorDestroy(vec);

    Person_t p1 = { "shlomo", 23 };
    Person_t p2 = { "chaim", 27 };
    Person_t p3 = { "yoel", 19 };
    Person_t p4 = { "yechiel", 29 };
    Person_t p5 = { "menachem", 27 };
    Person_t p6 = { "shlomo", 22 };

    vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &p1);
    GenVectorAdd(vec, &p2);
    GenVectorAdd(vec, &p3);
    GenVectorAdd(vec, &p4);
    GenVectorAdd(vec, &p5);
    GenVectorAdd(vec, &p6);

    SelectionSort(vec, ComparePerson);
    GenVectorPrint(vec, PrintPerson);

    GenVectorDestroy(vec);


}

void UnitTestForQuickSort()
{
    int n1 = 8, n2 = 3, n3 = 8, n4 = 11, n5 = 5, n6 = 3;

    GenVector_t* vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &n1);
    GenVectorAdd(vec, &n2);
    GenVectorAdd(vec, &n3);
    GenVectorAdd(vec, &n4);
    GenVectorAdd(vec, &n5);
    GenVectorAdd(vec, &n6);

    QuickSort(vec, CompareInt);
    GenVectorPrint(vec, PrintInt);
    QuickSort(vec, CompareIntOpposite);
    GenVectorPrint(vec, PrintInt);

    GenVectorDestroy(vec);

    Person_t p1 = { "shlomo", 23 };
    Person_t p2 = { "chaim", 27 };
    Person_t p3 = { "yoel", 19 };
    Person_t p4 = { "yechiel", 29 };
    Person_t p5 = { "menachem", 27 };
    Person_t p6 = { "shlomo", 22 };

    vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &p1);
    GenVectorAdd(vec, &p2);
    GenVectorAdd(vec, &p3);
    GenVectorAdd(vec, &p4);
    GenVectorAdd(vec, &p5);
    GenVectorAdd(vec, &p6);

    QuickSort(vec, ComparePerson);
    GenVectorPrint(vec, PrintPerson);

    GenVectorDestroy(vec);


}

void UnitTestForMergeSort()
{
    int n1 = 8, n2 = 3, n3 = 8, n4 = 11, n5 = 5, n6 = 3;

    GenVector_t* vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &n1);
    GenVectorAdd(vec, &n2);
    GenVectorAdd(vec, &n3);
    GenVectorAdd(vec, &n4);
    GenVectorAdd(vec, &n5);
    GenVectorAdd(vec, &n6);

    MergeSort(vec, CompareInt);
    GenVectorPrint(vec, PrintInt);
    MergeSort(vec, CompareIntOpposite);
    GenVectorPrint(vec, PrintInt);

    GenVectorDestroy(vec);

    
}

void UnitTestForCountingSort()
{
    int n1 = 3, n2 = 6, n3 = 4, n4 = 1, n5 = 3, n6 = 4, n7 = 1, n8 = 4;

    GenVector_t* vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &n1);
    GenVectorAdd(vec, &n2);
    GenVectorAdd(vec, &n3);
    GenVectorAdd(vec, &n4);
    GenVectorAdd(vec, &n5);
    GenVectorAdd(vec, &n6);
    GenVectorAdd(vec, &n7);
    GenVectorAdd(vec, &n8);

    CountingSort(vec, GetKeyInt);
    GenVectorPrint(vec, PrintInt);

    GenVectorDestroy(vec);

    Person_t p1 = { "shlomo", 23, 4 };
    Person_t p2 = { "chaim", 27, 7 };
    Person_t p3 = { "yoel", 19, 3 };
    Person_t p4 = { "yechiel", 29, 1 };
    Person_t p5 = { "menachem", 27, 9 };
    Person_t p6 = { "shlomo", 22, 4 };

    vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &p1);
    GenVectorAdd(vec, &p2);
    GenVectorAdd(vec, &p3);
    GenVectorAdd(vec, &p4);
    GenVectorAdd(vec, &p5);
    GenVectorAdd(vec, &p6);

    CountingSort(vec, GetKeyPersonAge);
    GenVectorPrint(vec, PrintPerson);

    CountingSort(vec, GetKeyPersonID);
    GenVectorPrint(vec, PrintPerson);
    
    GenVectorDestroy(vec);
}

void UnitTestForRadixSort()
{
    int n1 = 3546, n2 = 62273, n3 = 4231, n4 = 112, n5 = 334, n6 = 4388, n7 = 394, n8 = 474;

    GenVector_t* vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &n1);
    GenVectorAdd(vec, &n2);
    GenVectorAdd(vec, &n3);
    GenVectorAdd(vec, &n4);
    GenVectorAdd(vec, &n5);
    GenVectorAdd(vec, &n6);
    GenVectorAdd(vec, &n7);
    GenVectorAdd(vec, &n8);

    RadixSort(vec, GetKeyInt);
    GenVectorPrint(vec, PrintInt);

    GenVectorDestroy(vec);

    Person_t p1 = { "shlomo", 23, 356789 };
    Person_t p2 = { "chaim", 27, 78765 };
    Person_t p3 = { "yoel", 19, 30987 };
    Person_t p4 = { "yechiel", 29, 132456 };
    Person_t p5 = { "menachem", 27, 9234 };
    Person_t p6 = { "shlomo", 22, 49876 };

    vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &p1);
    GenVectorAdd(vec, &p2);
    GenVectorAdd(vec, &p3);
    GenVectorAdd(vec, &p4);
    GenVectorAdd(vec, &p5);
    GenVectorAdd(vec, &p6);

    RadixSort(vec, GetKeyPersonAge);
    GenVectorPrint(vec, PrintPerson);

    RadixSort(vec, GetKeyPersonID);
    GenVectorPrint(vec, PrintPerson);

    GenVectorDestroy(vec);
}

void UnitTestForBinSearchIter()
{
    int n1 = 8, n2 = 3, n3 = -8, n4 = 11, n5 = 5, n6 = 3, n7 = 4, n8 = 9, n9 = 13, n10 = 1;

    GenVector_t* vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &n1);
    GenVectorAdd(vec, &n2);
    GenVectorAdd(vec, &n3);
    GenVectorAdd(vec, &n4);
    GenVectorAdd(vec, &n5);
    GenVectorAdd(vec, &n6);

    QuickSort(vec, CompareInt);
    printf("/********************************************/\n");
    printf("           binary search iterative\n");
    printf("/********************************************/\n");
    GenVectorPrint(vec, PrintInt); 
    printf("%d is at index %zu\n", n1, BinSearchIter(vec, &n1, CompareInt));
    printf("%d is at index %zu\n", n2, BinSearchIter(vec, &n2, CompareInt));
    printf("%d is at index %zu\n", n3, BinSearchIter(vec, &n3, CompareInt));
    printf("%d is at index %zu\n", n4, BinSearchIter(vec, &n4, CompareInt));
    printf("%d is at index %zu\n", n5, BinSearchIter(vec, &n5, CompareInt));
    printf("%d is at index %zu\n", n6, BinSearchIter(vec, &n6, CompareInt));
    printf("%d is at index %zu\n", n7, BinSearchIter(vec, &n7, CompareInt));
    printf("%d is at index %zu\n", n8, BinSearchIter(vec, &n8, CompareInt));
    printf("%d is at index %zu\n", n9, BinSearchIter(vec, &n9, CompareInt));
    printf("%d is at index %zu\n", n10, BinSearchIter(vec, &n10, CompareInt));
}

void UnitTestForBinSearchRec()
{
    int n1 = 8, n2 = 3, n3 = 8, n4 = 11, n5 = 5, n6 = 3, n7 = 4, n8 = 9, n9 = 13, n10 = 1;

    GenVector_t* vec = GenVectorCreate(10, 2);
    GenVectorAdd(vec, &n1);
    GenVectorAdd(vec, &n2);
    GenVectorAdd(vec, &n3);
    GenVectorAdd(vec, &n4);
    GenVectorAdd(vec, &n5);
    GenVectorAdd(vec, &n6);

    CountingSort(vec, GetKeyInt);
    printf("\n\n/********************************************/\n");
    printf("           binary search recursive\n");
    printf("/********************************************/\n");
    GenVectorPrint(vec, PrintInt);
    printf("%d is at index %zu\n", n1, BinSearchRec(vec, &n1, CompareInt));
    printf("%d is at index %zu\n", n2, BinSearchRec(vec, &n2, CompareInt));
    printf("%d is at index %zu\n", n3, BinSearchRec(vec, &n3, CompareInt));
    printf("%d is at index %zu\n", n4, BinSearchRec(vec, &n4, CompareInt));
    printf("%d is at index %zu\n", n5, BinSearchRec(vec, &n5, CompareInt));
    printf("%d is at index %zu\n", n6, BinSearchRec(vec, &n6, CompareInt));
    printf("%d is at index %zu\n", n7, BinSearchRec(vec, &n7, CompareInt));
    printf("%d is at index %zu\n", n8, BinSearchRec(vec, &n8, CompareInt));
    printf("%d is at index %zu\n", n9, BinSearchRec(vec, &n9, CompareInt));
    printf("%d is at index %zu\n", n10, BinSearchRec(vec, &n10, CompareInt));
}

int CompareInt(const void* item1, const void* item2)
{
    int* num1 = (int*)item1;
    int* num2 = (int*)item2;

    if (*num1 > *num2)
    {
        return FIRST_BIGGER;
    }
    else if (*num1 < *num2)
    {
        return FIRST_SMALLER;
    }
    else
    {
        return EQUAL;
    }
}

int CompareIntOpposite(const void* item1, const void* item2)
{
    int* num1 = (int*)item1;
    int* num2 = (int*)item2;

    if (*num1 < *num2)
    {
        return FIRST_BIGGER;
    }
    else if (*num1 > *num2)
    {
        return FIRST_SMALLER;
    }
    else
    {
        return EQUAL;
    }
}

void PrintInt(const void* n)
{
    int* num = (int*)n;
    printf("%d", *num);
}

void PrintPerson(const void* p)
{
    Person_t* person = (Person_t*)p;
    printf("\n\t\t\tname: %s, age: %zu, id: %zu", person->name, person->age, person->ID);
}

int ComparePerson(const void* item1, const void* item2)
{
    Person_t* person1 = (Person_t*)item1;
    Person_t* person2 = (Person_t*)item2;

    return strcmp(person1->name, person2->name);
}

int GetKeyInt(const void* item)
{
    return  * (int*)item;
}

int GetKeyPersonAge(const void* item)
{
    return (int)((Person_t*)item)->age;
}

int GetKeyPersonID(const void* item)
{
    return (int)((Person_t*)item)->ID;
}

