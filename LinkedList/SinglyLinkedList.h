/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  2/8/22
    Last modified date: 3/8/22
    Description : Grows on Demand, Dinamic Memory Allocation, No Direct Access.
***************************************************************************************/

#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

typedef struct Person {
    int ID;//Primary Key
    char name[10];
    int age;
    struct Person*  next;
}Person_t;

Person_t* ListInsertHead(Person_t* head, Person_t* item);

Person_t* ListRemoveHead(Person_t* head, Person_t** item);

Person_t* ListInsertByKey(Person_t* head, int key, Person_t* item);

Person_t* ListRemoveByKey(Person_t* head, int key, Person_t** item);

void ListPrint(Person_t* head);

//recursive duplication functuions:
Person_t* ListInsertByKeyRecursive(Person_t* head, int key, Person_t* item);

Person_t* ListRemoveByKeyRecursive(Person_t* head, int key, Person_t** item);

Person_t* ListFlipIter(Person_t* head);

Person_t* ListFlipRec(Person_t* head);

Person_t* FindFirstCommon(Person_t* head1, Person_t* head2);
Person_t* FindFirstCommonRec(Person_t* head1, Person_t* head2);

void MultyplyListFirstWay(Person_t* node);
void MultyplyListSecondWay(Person_t* node);

#endif // __SINGLY_LINKED_LIST_H__

