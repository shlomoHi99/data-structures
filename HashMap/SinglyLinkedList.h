/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  2/8/22
    Last modified date: 3/8/22
    Description : Grows on Demand, Dinamic Memory Allocation, No Direct Access.
***************************************************************************************/

#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

typedef struct Pair {
    size_t key;//Primary Key
    char name[10];
    int item;
    struct Pair*  next;
}Pair_t;

typedef struct Person {
    size_t key;//Primary Key
    char name[10];
    char gender[7];
    struct Person* next;
}Person_t;

Pair_t* ListInsertHead(Pair_t* head, Pair_t* item);

Person_t* ListInsertPersonHead(Person_t* head, Person_t* item);

Pair_t* ListRemoveHead(Pair_t* head, Pair_t** item);

Pair_t* ListInsertByKey(Pair_t* head, int key, Pair_t* item);

Pair_t* ListRemoveByKey(Pair_t* head, size_t key, Pair_t** item);

Person_t* ListRemovePersonByKey(Person_t* head, size_t key, Person_t** item);

void ListDestroy(Pair_t* head);

void ListPersonDestroy(Person_t* head);

void ListPrint(Pair_t* head);

//recursive dubplication functuions:
Pair_t* ListInsertByKeyRecursive(Pair_t* head, int key, Pair_t* item);

Pair_t* ListRemoveByKeyRecursive(Pair_t* head, int key, Pair_t** item);

Pair_t* ListFlipIter(Pair_t* head);

Pair_t* ListFlipRec(Pair_t* head);


#endif // __SINGLY_LINKED_LIST_H__