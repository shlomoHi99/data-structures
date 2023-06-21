/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  2/8/22
    Last modified date: 3/8/22
    Description : Grows on Demand, Dinamic Memory Allocation, No Direct Access.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ADTDefs.h"
#include "SinglyLinkedList.h"

Pair_t* ListInsertHead(Pair_t* head, Pair_t* item)
{
    assert(item);
   
    item->next = NULL;
    if (head)
    {
        item->next = head;
    }   
    
    return item;
}

Person_t* ListInsertPersonHead(Person_t* head, Person_t* item)
{
    assert(item);

    item->next = NULL;
    if (head)
    {
        item->next = head;
    }

    return item;
}

Pair_t* ListRemoveHead(Pair_t* head, Pair_t** item)
{
    assert(item && head);
    
    Pair_t* curHandle = head->next;
    head->next = NULL;
    *item = head;
    return curHandle;
}

Pair_t* ListInsertByKey(Pair_t* head, int key, Pair_t* item)
{
    assert(item);

    Pair_t* curHandle = head;

    if (!head || head->key < key)
    {   
        item->next = head;
        return item;
    }

    while (curHandle)
    {
        if (!curHandle->next || curHandle->next->key < key)
        {
            break;
        }
        curHandle = curHandle->next;
    }
    item->next = curHandle->next;
    curHandle->next = item;

    return head;
}

Pair_t* ListInsertByKeyRecursive(Pair_t* head, int key, Pair_t* item)
{
    assert(item);

    if (!head || head->key < key)
    {
        item->next = head;
        return item;
    }

    head->next = ListInsertByKeyRecursive(head->next, key, item);
    return head;
}

Pair_t* ListRemoveByKey(Pair_t* head, size_t key, Pair_t** item)
{
    assert(head && item);

    Pair_t* curHandle = head;
    Pair_t* temp;
    if (curHandle->key == key)
    {
        temp = curHandle->next;
        curHandle->next = NULL;
        *item = curHandle;
        return temp;
    }
    while (curHandle->next)
    {
        if (curHandle->next->key == key)
        {
            temp = curHandle->next;
            curHandle->next = curHandle->next->next;
            temp->next = NULL;
            *item = temp;
            return head;
        }
        curHandle = curHandle->next;
    }
    
    return head;
}

Person_t* ListRemovePersonByKey(Person_t* head, size_t key, Person_t** item)
{
    assert(head && item);

    Person_t* curHandle = head;
    Person_t* temp;
    if (curHandle->key == key)
    {
        temp = curHandle->next;
        curHandle->next = NULL;
        *item = curHandle;
        return temp;
    }
    while (curHandle->next)
    {
        if (curHandle->next->key == key)
        {
            temp = curHandle->next;
            curHandle->next = curHandle->next->next;
            temp->next = NULL;
            *item = temp;
            return head;
        }
        curHandle = curHandle->next;
    }

    return head;
}

Pair_t* ListRemoveByKeyRecursive(Pair_t* head, int key, Pair_t** item)
{
    Pair_t* nextInList;
    
    assert(item);

    if (!head)
    {
        return head;
    }
    if (head->key == key)
    {
        nextInList = head->next;
        head->next = NULL;
        *item = head;
        return nextInList;
    }

    head->next = ListRemoveByKeyRecursive(head->next, key, item);
    return head;
}

Pair_t* ListFlipIter(Pair_t* head) 
{
    Pair_t* curPerson = head;
    Pair_t* prev = NULL; 
    Pair_t* tempNext;

    if (!head)
    {
        return head;
    }

    while (curPerson)
    {
        tempNext = curPerson->next;
        curPerson->next = prev;
        prev = curPerson;
        curPerson = tempNext;
    }
   
    return prev;
}

Pair_t* ListFlipRec(Pair_t* head)
{
    Pair_t* temp;

    if (!head || !head->next)
    {
        return head;
    }

    temp = ListFlipRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp;
}

void ListDestroy(Pair_t* head)
{
    if (!head)
    {
        return;
    }

    ListDestroy(head->next);
    free(head);
}

void ListPersonDestroy(Person_t* head)
{
    if (!head)
    {
        return;
    }

    ListDestroy(head->next);
    free(head);
}

void ListPrint(Pair_t* head)
{
    if (!head)
    {
        printf("\nempty list.\n");
        return;
    }
    
    printf("\nThe List:\n");
    while (head){
        printf("key: %zu\tAge: %d\n", head->key, head->item);
        head = head->next;
    } 
}