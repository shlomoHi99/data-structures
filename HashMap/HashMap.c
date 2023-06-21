/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  23/8/22
    Last modified date: 24/8/22
    Description : Hash Map Implementation.
                    -Using a linked list as a way to deal with collisions.
***************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "ADTDefs.h"
#include "SinglyLinkedList.h"
#include "HashMap.h"

struct HashMap
{
    Pair_t** dataTable;
    size_t tableSize;
    size_t numOfItems;
    size_t numOfSlotsUsed;
};

struct BeachHashMap
{
    Person_t** dataTable;
    size_t tableSize;
    size_t numOfItems;
    size_t numOfSlotsUsed;
};

HashMap_t* MapCreate(size_t size)
{
    assert(size > 0);

    HashMap_t* map = (HashMap_t*)calloc(1, sizeof(HashMap_t));
    if (!map)
    {
        return NULL;
    }

    map->dataTable = (Pair_t**)calloc(size, sizeof(Pair_t*));
    if (!map->dataTable)
    {
        free(map);
        return NULL;
    }

    map->tableSize = size;

    return map;
}

void       MapDestroy(HashMap_t* map)
{
    assert(map);

    for (int i = 0; i < map->tableSize; i++)
    {
        ListDestroy(map->dataTable[i]);
    }
    free(map->dataTable);
    free(map);
}

ADTErr     MapInsert(HashMap_t* map, size_t key, int item, char* name)
{
    assert(map);

    //in the hash table mathematic principals, using more than 70% of the 
    // table will cause a lot of collisions, causing the complexity to shift 
    //from O(1) to O(n), which makes the hash map a useless data structure 
    //compared to other data structures.
    if (map->numOfSlotsUsed >= map->tableSize * 0.7)
    {
        return ERR_OVERFLOW;
    }

    const size_t index = key % map->tableSize;
    Pair_t* newPair = (Pair_t*)calloc(1, sizeof(Pair_t));
    if (!newPair)
    {
        return ERR_ALLOCATION_FAILED;
    }

    newPair->item = item;
    newPair->key = key;
    strcpy(newPair->name, name);
    if (map->dataTable[index] == NULL)
    {
        ++map->numOfSlotsUsed;
    }
    map->dataTable[index] =
        ListInsertHead(map->dataTable[index], newPair);
    
    ++map->numOfItems;

    return ERR_OK;
}

ADTErr     MapRemove(HashMap_t* map, size_t key, int* item, char** name)
{
    assert(map && item);

    const size_t index = key % map->tableSize;
    if (!map->dataTable[index])
    {
        return ERR_WRONG_INDEX;
    }

    Pair_t* tempNode = NULL;

    map->dataTable[index] = ListRemoveByKey(map->dataTable[index], key, &tempNode);
    if (!tempNode)
    {
        return ERR_WRONG_INDEX;
    }

    *item = tempNode->item;
    strcpy(*name, tempNode->name);
    free(tempNode);
    if (!map->dataTable[index])
    {
        --map->numOfSlotsUsed;
    }
    --map->numOfItems;

    return ERR_OK;
}

ADTErr     MapGet(HashMap_t* map, size_t key, int* item, char** name)
{
    assert(map && item);

    const size_t index = key % map->tableSize;
    Pair_t* listHead = map->dataTable[index];
    if (!listHead)
    {
        return ERR_WRONG_INDEX;
    }

    while (listHead)
    {
        if (listHead->key == key)
        {
            *item = listHead->item;
            strcpy(*name, listHead->name);
            return ERR_OK;
        }
        listHead = listHead->next;
    }

    return ERR_WRONG_INDEX;
}

/*   unit test functions   */

void MapPrint(HashMap_t* map)
{
    assert(map);

    Pair_t* tempHead;

    printf("table size: %zu,\tslots used: %zu,\tnum of items: %zu\n",
                map->tableSize, map->numOfSlotsUsed, map->numOfItems);
    for (int i = 0; i < map->tableSize; i++)
    {
        tempHead = map->dataTable[i];
        printf("slot #%d\n", i);
        while (tempHead)
        {
            printf("\tkey: %zu, name: %s, data:%d\n", tempHead->key, tempHead->name, tempHead->item);
            tempHead = tempHead->next;
        }
    }
}

/*   practice functions    */

size_t Hash(char* name)
{
    size_t hashValue = 0;

    while (*name != '\0')
    {
        hashValue += (size_t)*name;
        ++name;
    }

    return hashValue;
}

size_t HashWTableSize(char* name, size_t tableSize)
{
    size_t hashValue = 0;

    while (*name != '\0')
    {
        hashValue += (size_t)*name;
        ++name;
    }

    return hashValue % tableSize;
}

void MapPrintCountBySlots(HashMap_t* map)
{
    assert(map);

    Pair_t* tempHead;
    size_t nodesCounter;

    for (int i = 0; i < map->tableSize; i++)
    {
        tempHead = map->dataTable[i];
        nodesCounter = 0;
        while (tempHead)
        {
            ++nodesCounter;
            tempHead = tempHead->next;
        }
        printf("slot #%d => %zu people\n", i, nodesCounter);
        
    }
}

