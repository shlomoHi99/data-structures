/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  2/8/22
    Last modified date: 3/8/22
    Description : Grows on Demand, Dinamic Memory Allocation, No Direct Access.
***************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "ADTDefs.h"
#include "SinglyLinkedList.h"

//this imlementation is not entirely encapsulated,
//the main can go through the list.
Person_t* ListInsertHead(Person_t* head, Person_t* item)
{
    assert(item);
   
    item->next = NULL;
    if (head)
    {
        item->next = head;
    }   
    
    return item;
}

Person_t* ListRemoveHead(Person_t* head, Person_t** item)
{
    assert(item && head);
    
    Person_t* curHandle = head->next;
    head->next = NULL;
    *item = head;
    return curHandle;
}

Person_t* ListInsertByKey(Person_t* head, int key, Person_t* item)
{
    assert(item);

    Person_t* curHandle = head;

    if (!head || head->ID < key)
    {   
        item->next = head;
        return item;
    }

    while (curHandle)
    {
        if (!curHandle->next || curHandle->next->ID < key)
        {
            break;
        }
        curHandle = curHandle->next;
    }
    item->next = curHandle->next;
    curHandle->next = item;

    return head;
}

Person_t* ListInsertByKeyRecursive(Person_t* head, int key, Person_t* item)
{
    assert(item);

    if (!head || head->ID < key)
    {
        item->next = head;
        return item;
    }

    head->next = ListInsertByKeyRecursive(head->next, key, item);
    return head;
}

Person_t* ListRemoveByKey(Person_t* head, int key, Person_t** item)
{
    assert(head && item);

    Person_t* curHandle = head;
    Person_t* temp;
    if (curHandle->ID == key)
    {
        temp = curHandle->next;
        curHandle->next = NULL;
        *item = curHandle;
        return temp;
    }
    while (curHandle->next)
    {
        if (curHandle->next->ID == key)
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

Person_t* ListRemoveByKeyRecursive(Person_t* head, int key, Person_t** item)
{
    Person_t* nextInList;
    
    assert(item);

    if (!head)
    {
        return head;
    }
    if (head->ID == key)
    {
        nextInList = head->next;
        head->next = NULL;
        *item = head;
        return nextInList;
    }

    head->next = ListRemoveByKeyRecursive(head->next, key, item);
    return head;
}

Person_t* ListFlipIter(Person_t* head) 
{
    Person_t* curPerson = head;
    Person_t* prev = NULL; 
    Person_t* tempNext;

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

Person_t* ListFlipRec(Person_t* head)
{
    Person_t* temp;

    if (!head || !head->next)
    {
        return head;
    }

    temp = ListFlipRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp;
}

Person_t* FindFirstCommonRec(Person_t* head1, Person_t* head2)
{
    if (!head1 || !head2)
    {
        return NULL;
    }

    if (!head1->next && !head2->next)
    {
        if (head1 == head2)
        {
            return head1;
        }
        else
        {
            return NULL;
        }
    }

    if (!head1->next)
    {
        return FindFirstCommon(head1, head2->next);
    }

    if (!head2->next)
    {
        return FindFirstCommon(head1->next, head2);
    }

    Person_t* temp = FindFirstCommon(head1->next, head2->next);
    if (temp && (head1 == head2))
    {
        return head1;
    }
    else
    {
        return temp;
    }
}

Person_t* FindFirstCommon(Person_t* head1, Person_t* head2)
{
    if (!head1 || !head2)
    {
        return NULL;
    }

    int list1Len = 0, list2Len = 0, difference;;
    Person_t* temp1, * temp2;

    temp1 = head1;
    while (temp1)
    {
        ++list1Len;
        temp1 = temp1->next;
    }
    temp2 = head2;
    while (temp2)
    {
        ++list2Len;
        temp2 = temp2->next;
    }
    if (list1Len > list2Len)
    {
        difference = list1Len - list2Len;

        while (difference--)
        {
            head1 = head1->next;
        }
    }
    else if (list1Len < list2Len)
    {
        difference = list2Len - list1Len;

        while (difference--)
        {
            head2 = head2->next;
        }
    }

    while (head1)
    {
        if (head1 == head2)
        {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

void MultyplyListFirstWay(Person_t* node) 
{
    Person_t* original = node;

    while (node)
    {
        Person_t* newNode = calloc(1, sizeof(Person_t));
        if (!newNode)exit(1);

        newNode->age = node->age;
        newNode->ID = node->ID;
        strcpy(newNode->name, node->name);

        newNode->next = node->next;
        node->next = newNode;
        node = newNode->next;
    }
}

void MultyplyListSecondWay(Person_t* node)
{
    Person_t* originalHead = node, *originalMulty = node, *curNode = node, *lastNode = node;
    int isFirstIter = 1;

    while (node)
    {
        Person_t* newNode = calloc(1, sizeof(Person_t));
        if (!newNode)exit(1);

        newNode->age = node->age;
        newNode->ID = node->ID;
        strcpy(newNode->name, node->name);

        if (isFirstIter)
        {
            originalMulty = newNode;
            isFirstIter = 0;
        }
        else {
            curNode->next = newNode;
        }
        curNode = newNode;
        if (!node->next)
        {
            lastNode = node;
        }
        node = node->next;
    }
    if(lastNode)
    {
        lastNode->next = originalMulty;
    }
}

void ListPrint(Person_t* head)
{
    if (!head)
    {
        printf("\nempty list.\n");
        return;
    }
    
    printf("\nThe List:\n");
    while (head){
        printf("ID: %d\tName: %s\tAge: %d\n", head->ID, head->name, head->age);
        head = head->next;
    } 
}



