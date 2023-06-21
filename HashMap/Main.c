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

//forward declaretion:
void UnitTest();
void Practice();

void main()
{
    //UnitTest();
    Practice();
}

void UnitTest()
{
    ADTErr errCode;
    int temp;
    char* tempName;

    /*   unit test for create element   */

    /*  trying to create a table with 0 size  */
    /*HashMap_t* emptyMap = MapCreate(0);
    if (!emptyMap)
    {
        printf("not enough memory!");
        exit(1);
    }*/
    HashMap_t* map = MapCreate(10);
    if (!map)
    {
        printf("not enough memory!");
        exit(1);
    }

    /*   unit test for Insert element   */

    errCode = MapInsert(map, 150, 14, "haim");
    HandleErr(errCode, "adding 14 with key 153");
    errCode = MapInsert(map, 50, 12, "yossi");
    HandleErr(errCode, "adding 12 with key 143");
    errCode = MapInsert(map, 250, 15, "david");
    HandleErr(errCode, "adding 12 with key 143");
    errCode = MapInsert(map, 350, 15, "yanki");
    HandleErr(errCode, "adding 15 with key 350");
    errCode = MapInsert(map, 147, 1, "yakov");
    HandleErr(errCode, "adding 1 with key 147");
    errCode = MapInsert(map, 178, 19, "matisyahu");
    HandleErr(errCode, "adding 19 with key 178");
    errCode = MapInsert(map, 141, 2, "yoel");
    HandleErr(errCode, "adding 2 with key 141");
    errCode = MapInsert(map, 152, 14, "yochai");
    HandleErr(errCode, "adding 14 with key 152");
    errCode = MapInsert(map, 146, 12, "nachum");
    HandleErr(errCode, "adding 12 with key 146");
    errCode = MapInsert(map, 155, 14, "chanoch");
    HandleErr(errCode, "adding 14 with key 155");
    errCode = MapInsert(map, 142, 12, "yechiel");
    HandleErr(errCode, "adding 12 with key 142");

    MapPrint(map);

    /*   unit test for remove element   */

    errCode = MapRemove(map, 147, &temp, &tempName);
    if (!errCode)
    {
        printf("item key-147 removed: %d\n", temp);
    }
    HandleErr(errCode, "removing key 147");
    errCode = MapRemove(map, 147, &temp, &tempName);
    if (!errCode)
    {
        printf("item key-147 removed: %d\n", temp);
    }
    HandleErr(errCode, "removing key 147 second time");
    errCode = MapRemove(map, 150, &temp, &tempName);
    if (!errCode)
    {
        printf("item key-150 removed: %d\n", temp);
    }
    HandleErr(errCode, "removing key 150");

    MapPrint(map);

    /*   unit test for get element   */

    errCode = MapGet(map, 250, &temp, &tempName);
    if (!errCode)
    {
        printf("item key-250 found: %d\n", temp);
    }
    HandleErr(errCode, "getting key 250");
    errCode = MapGet(map, 50, &temp, &tempName);
    if (!errCode)
    {
        printf("item key-50 found: %d\n", temp);
    }
    HandleErr(errCode, "getting key 50");
    errCode = MapGet(map, 450, &temp, &tempName);
    if (!errCode)
    {
        printf("item key-450 found: %d\n", temp);
    }
    HandleErr(errCode, "getting key 450");
    errCode = MapGet(map, 454, &temp, &tempName);
    if (!errCode)
    {
        printf("item key-454 found: %d\n", temp);
    }
    HandleErr(errCode, "getting key 454");
    errCode = MapGet(map, 350, &temp, &tempName);
    if (!errCode)
    {
        printf("item key-350 found: %d\n", temp);
    }
    HandleErr(errCode, "getting key 350");

    MapPrint(map);

    MapDestroy(map);
}

void Practice()
{
    size_t key;
    char name[10];

    /*    Hash w tablSize    */
    
    HashMap_t* map = MapCreate(10);

    printf("/*    Hash w tablSize    */\n\n");
    strcpy(name, "Jacov");
    key = HashWTableSize(name, 10);
    printf("%s => %zu\n", name, key);

    strcpy(name, "Itzhak");
    key = HashWTableSize(name, 10);
    printf("%s => %zu\n", name, key);

    strcpy(name, "Avraham");
    key = HashWTableSize(name, 10);
    printf("%s => %zu\n", name, key);
    
    /*    Hash     */
    printf("\n/*    Hash     */\n\n");

    strcpy(name, "Jacov");
    key = Hash(name);
    printf("%s => %zu\n", name, key);
    MapInsert(map, key, 0, name);

    strcpy(name, "Itzhak");
    key = Hash(name);
    printf("%s => %zu\n", name, key);
    MapInsert(map, key, 0, name);

    strcpy(name, "Avraham");
    key = Hash(name);
    printf("%s => %zu\n", name, key);
    MapInsert(map, key, 0, name);

    printf("\n");
    MapPrint(map);
    printf("\n");
    MapPrintCountBySlots(map);
}