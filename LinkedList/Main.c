/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  2/8/22
    Last modified date: 4/8/22
    Description : Grows on Demand, Dinamic Memory Allocation, No Direct Access.
***************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ADTDefs.h"
#include "SinglyLinkedList.h"

void UnitTestsForSinglyLinkedLIst();
//void PracticingSinglyLinkedList();
void UnitTestForSerchingTheFirstCommon();
void UnitTestForMultiplyList();

void main()
{
    //UnitTestsForSinglyLinkedLIst();

    //PracticingSinglyLinkedList();
    
    //UnitTestForSerchingTheFirstCommon();

    UnitTestForMultiplyList();
}

void UnitTestsForSinglyLinkedLIst()
{
    Person_t* head = NULL;
    Person_t* empty = NULL;
    Person_t item1 = {1,"shlomo",23, NULL};
    Person_t item2 = { 2,"chaim",24, NULL };
    Person_t item3 = { 3,"yosale",25, NULL };
    Person_t item4 = { 4,"david",29, NULL };
    Person_t item5 = { 5,"jgcfh",65, NULL };
    Person_t* recived;

    //Insert Head Unit Test:
    printf("***********************************************************\n");
    printf("Insert Head Unit Test:\n");
    //head = ListInsertHead(head, NULL);
    //ListPrint(head);
    //head = ListInsertHead(head, empty);
    //ListPrint(head);
    head = ListInsertHead(head, &item1);
    ListPrint(head);
    
    head = ListInsertHead(head, &item2);
    ListPrint(head);

    head = ListInsertHead(head, &item3);
    ListPrint(head);

    //Remove Head Unit Test:
    printf("\n***********************************************************\n");
    printf("Remove Head Unit Test:\n");
    //head = ListRemoveHead(head, NULL);
    //ListPrint(head);
    head = ListRemoveHead(head, &recived);
    printf("item removed: name:%s, ID:%d, age:%d\n",
        recived->name, recived->ID, recived->age);
    ListPrint(head);

    head = ListRemoveHead(head, &recived);
    printf("item removed: name:%s, ID:%d, age:%d\n",
        recived->name, recived->ID, recived->age);
    ListPrint(head);

    head = ListRemoveHead(head, &recived);
    printf("item removed: name:%s, ID:%d, age:%d\n",
        recived->name, recived->ID, recived->age);
    ListPrint(head);

    //Add by key unit test:
    printf("\n***********************************************************\n");
    printf("Add by Key Unit Test:\n");

    
    head = ListInsertByKey(head, 3, &item3);
    head = ListInsertByKey(head, 1, &item1);
    head = ListInsertByKey(head, 2, &item2);  
    head = ListInsertByKey(head, 4, &item4);
    ListPrint(head);

    //Remove by key unit test:
    printf("\n***********************************************************\n");
    printf("Remove by Key Unit Test:\n");

    head = ListRemoveByKey(head, 3, &recived);
    printf("item removed: name:%s, ID:%d, age:%d\n",
        recived->name, recived->ID, recived->age);

    head = ListRemoveByKey(head, 1, &recived);
    printf("item removed: name:%s, ID:%d, age:%d\n",
        recived->name, recived->ID, recived->age);

    head = ListRemoveByKey(head, 2, &recived);
    printf("item removed: name:%s, ID:%d, age:%d\n",
        recived->name, recived->ID, recived->age);

    head = ListRemoveByKey(head, 4, &recived);
    printf("item removed: name:%s, ID:%d, age:%d\n",
        recived->name, recived->ID, recived->age);

    ListPrint(head);


    //Add by key Recursive unit test:
    printf("\n***********************************************************\n");
    printf("Add by Key Recursive Unit Test:\n");

    head = ListInsertByKeyRecursive(head, 3, &item3);
    head = ListInsertByKeyRecursive(head, 1, &item1);
    head = ListInsertByKeyRecursive(head, 2, &item2);
    head = ListInsertByKeyRecursive(head, 4, &item4);
    head = ListInsertByKeyRecursive(head, 5, &item5);
    ListPrint(head);

    //Flip Recursive unit test:
    printf("\n***********************************************************\n");
    printf("Flip by Key Recursive Unit Test:\n");

    head = ListFlipRec(head);
    ListPrint(head);

    //Remove by key Recursive unit test:
    printf("\n***********************************************************\n");
    printf("Remove by Key Recursive Unit Test:\n");

    head = ListRemoveByKeyRecursive(head, 3, &recived);
    printf("item removed: name:%s, ID:%d, age:%d\n",
        recived->name, recived->ID, recived->age);

    head = ListRemoveByKeyRecursive(head, 1, &recived);
    printf("item removed: name:%s, ID:%d, age:%d\n",
        recived->name, recived->ID, recived->age);

    head = ListRemoveByKeyRecursive(head, 2, &recived);
    printf("item removed: name:%s, ID:%d, age:%d\n",
        recived->name, recived->ID, recived->age);

    head = ListRemoveByKeyRecursive(head, 4, &recived);
    printf("item removed: name:%s, ID:%d, age:%d\n",
        recived->name, recived->ID, recived->age);

    ListPrint(head);
}


//forward declaretions:
size_t ListCountNodes(Person_t* head);
int ListSumOfNodes(Person_t* head);
int ListIsOrderedUpward(Person_t* head);
size_t ListCountAppearenceOfItem(Person_t* head, char* name);
void ListPrintBackword(Person_t* head);
//void ListSort(Person_t** pHead);
Person_t* ListRemoveEvenItems(Person_t* head);
//Person_t* ListConvertToArray(Person_t* head);

//void PracticingSinglyLinkedList()
//{
//    /*items in list*/ 
//    Person_t* head = NULL;
//    Person_t item1 = { 1,"shlomo",73, NULL };
//    Person_t item2 = { 2,"chaim",24, NULL };
//    Person_t item3 = { 3,"yosale",21, NULL };
//    Person_t item4 = { 4,"david",29, NULL };
//    Person_t item5 = { 5,"shlomo",65, NULL }; 
//    /*insert (initializing the list)*/ {head = ListInsertByKey(head, 3, &item3);
//    head = ListInsertByKey(head, 1, &item1);
//    head = ListInsertByKey(head, 2, &item2);
//    head = ListInsertByKey(head, 4, &item4);
//    head = ListInsertByKey(head, 5, &item5); }
//    char name[] = "shlomo";
//
//    printf("number of nodes in list:%zu\n",ListCountNodes(head));
//    printf("saum of nodes in list:%d\n", ListSumOfNodes(head));
//    ListIsOrderedUpward(head) ? printf("yeah\n") : printf("sorry ah\n");
//    head = ListFlipRec(head);
//    printf("after flip:\n");
//    ListPrint(head);
//    head = ListFlipIter(head);
//    printf("after flip:\n");
//    ListPrint(head);
//    ListIsOrderedUpward(head) ? printf("yeah\n") : printf("sorry ah\n");
//    printf("the number of times the name \"%s\"appeared is %zu\n",
//        name, ListCountAppearenceOfItem(head, name));
//    ListPrint(head);
//    ListPrintBackword(head);
//    head = ListFlipRec(head);
//    ListSort(&head);
//    ListPrint(head);
//    /*head = ListRemoveEvenItems(head);
//    ListPrint(head);*/
//
//
//}

void UnitTestForMultiplyList()
{
    Person_t item5 = { 5,"shlomo",65, NULL };
    Person_t item4 = { 4,"david",29, &item5 };
    Person_t item3 = { 3,"yosale",21, &item4 };
    Person_t item2 = { 2,"chaim",24, &item3 };
    Person_t item1 = { 1,"shlomo",73, &item2 };
    Person_t* head = &item1;
}

size_t ListCountNodes(Person_t* head)
{
    if (!head->next)
    {
        return 1;
    }

    return 1 + ListCountNodes(head->next);
}

int ListSumOfNodes(Person_t* head)
{
    int sum = 0;

    while (head)
    {
        sum += head->age;
        head = head->next;
    }
    return sum;
}

int ListIsOrderedUpward(Person_t* head)
{
    while (head->next)
    {
        if (head->ID > head->next->ID)
        {
            return 0;
        }
        head = head->next;
    }
    return 1;
}

size_t ListCountAppearenceOfItem(Person_t* head, char* name)
{
    size_t count = 0;

    while (head)
    {
        if (!strcmp(head->name, name))
        {
            ++count;
        }
        head = head->next;
    }
    return count;
}

void ListPrintBackword(Person_t* head)
{
    if (!head)
    {
        return;
    }

    ListPrintBackword(head->next);
    printf("\nID:%d name:\"%s\" age:%d", head->ID, head->name, head->age);
}

Person_t* ListRemoveEvenItems(Person_t* head)
{
    Person_t* origHead = head;

    while (head->next)
    {
        head->next = head->next->next;
        head = head->next;
    }

    return origHead;
}

//Person_t* ListConvertToArray(Person_t* head)
//{
//    int i = 0;
//    size_t size = ListCountNodes(head);
//    Person_t* list = (Person_t*)malloc(size * sizeof(Person_t));
//    if (!list)
//    {
//        printf("ERROR:not enough memory!");
//        exit(1);
//    }
//
//    ListSort(&head);
//    while (head)
//    {
//        list[i].ID = head->ID;
//        list[i].age = head->age;
//        strcpy(list[i].name, head->name);
//        ++i;
//        head = head->next;
//    }
//
//    return list;
//}

void UnitTestForSerchingTheFirstCommon()
{
    Person_t* head1 = NULL, *head2 = NULL, *commonIter = NULL, * commonRec = NULL;
    Person_t item1 = { 1,"shlomo",73, NULL };
    Person_t item2 = { 2,"chaim",24, NULL };
    Person_t item3 = { 3,"yosale",21, NULL };
    Person_t item4 = { 4,"david",29, NULL };
    Person_t item5 = { 5,"shlomo",65, NULL };

    head1 = ListInsertHead(head1, &item5);
    head1 = ListInsertHead(head1, &item4);
    head1 = ListInsertHead(head1, &item3);
    head1 = ListInsertHead(head1, &item2);
    //head1 = ListInsertHead(head1, &item1);
    //head2 = ListInsertHead(head2, &item5);
    head2 = ListInsertHead(head2, &item4);
    head2 = ListInsertHead(head2, &item1);

    commonIter = FindFirstCommon(head1, head2);
    printf("commonIter = %s\n", commonIter->name);
    commonRec = FindFirstCommonRec(head1, head2);
    printf("commonRec = %s", commonRec->name);
}


