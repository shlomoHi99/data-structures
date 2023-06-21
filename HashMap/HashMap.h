/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  23/8/22
    Last modified date: --
    Description : Hash Map Implementation.
                    -Using a linked list as a way to deal with collisions.
***************************************************************************************/
#ifndef __HASH_MAP_C__
#define __HASH_MAP_C__

typedef struct HashMap HashMap_t;
typedef struct BeachHashMap BeachHashMap_t;

HashMap_t* MapCreate(size_t size);

void       MapDestroy(HashMap_t* map);

ADTErr     MapInsert(HashMap_t* map, size_t key, int item, char* name);

ADTErr     MapRemove(HashMap_t* map, size_t key, int* item, char** name);

ADTErr     MapGet(HashMap_t* map, size_t key, int* item, char** name);

/*   unit test functions   */

void MapPrint(HashMap_t* map);

/*   practice functions    */

size_t Hash(char* name);

size_t HashWTableSize(char* name, size_t tableSize);

void MapPrintCountBySlots(HashMap_t* map);

BeachHashMap_t* BeachHashMapCreate(size_t size);

#endif //__HASH_MAP_C__