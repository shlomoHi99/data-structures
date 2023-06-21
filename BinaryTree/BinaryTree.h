/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  9/8/22
    Last modified date: --
    Description : Binary Search Tree Implementation.
***************************************************************************************/
#ifndef __BINARI_TREE_H__
#define __BINARI_TREE_H__

typedef struct BinaryTree BinTree_t;

typedef enum TraversalOrderMode {
    PREORDER,
    INORDER,
    POSTORDER
}TraversalMode_t;

BinTree_t*  BinTreeCreate();

void        BinTreeDestroy(BinTree_t* binTree);

ADTErr      BinTreeInsert(BinTree_t* binTree, int data);

int         BinTreeIsDataFound(BinTree_t* binTree, int data);

int         AreSimilarTrees(BinTree_t* binTree1, BinTree_t* binTree2);

int         IsFullTree(BinTree_t* binTree);

void        CheckTree(BinTree_t* binTree, int* isPerfect, int* treeHeight);

/*  Unit-Test functions  */

void        BinTreePrint(BinTree_t* binTree, TraversalMode_t printMode);

/*  practicing functions   */

void        PrintLeafs(BinTree_t* binTree);

int         GetBiggestInTree(BinTree_t* binTree);

int         GetSmallestInTree(BinTree_t* binTree);

size_t      GetTreeHeight(BinTree_t* binTree);

#endif // __BINARI_TREE_H__
