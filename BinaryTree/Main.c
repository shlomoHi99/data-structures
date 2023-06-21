/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  10/8/22
    Last modified date: --
    Description : Binary Search Tree Implementation.
***************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "ADTDefs.h"
#include "BinaryTree.h"

void UnitTestsForBinarySearchTrees();
void Practice();
BinTree_t* CreateNewBinTree();

void main()
{
    UnitTestsForBinarySearchTrees();
    //Practice();
}

void UnitTestsForBinarySearchTrees()
{
    /*BinTree_t* bst = BinTreeCreate();
    ADTErr errCode = BinTreeInsert(bst, 8);
    errCode = BinTreeInsert(bst, 6);
    errCode = BinTreeInsert(bst, 7);
    BinTreeInsert(bst, 9);
    BinTreeInsert(bst, 11);
    errCode = BinTreeInsert(bst, 7);
    HandleErr(errCode, "adding 7 twice");
    BinTreeInsert(bst, 8);
    BinTreePrint(bst, INORDER);

    printf("%s\n", BinTreeIsDataFound(bst, 11) ? "yaeh": "naaa");
    BinTreeDestroy(bst);*/

    BinTree_t* bst1 = CreateNewBinTree();
    int isPerfect, treeHeight;
    //BinTree_t* bst2 = CreateNewBinTree();

    //printf("The trees are%ssimilar", AreSimilarTrees(bst1, bst2) ? " " : " not ");
    //printf("The trees is%sfull", IsFullTree(bst1) ? " " : " not ");
    CheckTree(bst1, &isPerfect, &treeHeight);
    printf("The tree is%sperfect, and it's height is %d.", isPerfect ? " " : " not ", treeHeight);
}                   

void Practice()
{
    BinTree_t* bst = BinTreeCreate();
    BinTreeInsert(bst, 8);
    BinTreeInsert(bst, 6);
    BinTreeInsert(bst, 7);
    BinTreeInsert(bst, 9);
    BinTreeInsert(bst, 11);
    BinTreeInsert(bst, 15);
    BinTreeInsert(NULL, 15);

  
    BinTree_t* bst1 = CreateNewBinTree();
    printf("The leafs on the computer tree are: ");
    PrintLeafs(bst);
    printf("\nThe leafs on your tree are: ");
    PrintLeafs(bst1);
    printf("\nThe biggest number on the computer tree are: %d", GetBiggestInTree(bst));
    printf("\nThe biggest number on your tree are: %d", GetBiggestInTree(bst1));
    printf("\nThe smallest number on the computer tree are: %d", GetSmallestInTree(bst));
    printf("\nThe smallest number on your tree are: %d", GetSmallestInTree(bst1));
    printf("\nThe height of the computer tree are: %zu", GetTreeHeight(bst));
    printf("\nThe height of your tree are: %zu", GetTreeHeight(bst1));
    BinTreeDestroy(bst);
    BinTreeDestroy(bst1);
}

BinTree_t* CreateNewBinTree()
{
    int numOfNodes, curData;
    BinTree_t* bst = BinTreeCreate();
    if (!bst)
    {
        printf("ERROR: not enough memory!");
        exit(1);
    }

    printf("Ho many items you'd like to enter?\n");
    scanf("%d", &numOfNodes);
    for (int i = 0; i < numOfNodes; i++)
    {
        printf("enter a number:");
        scanf("%d", &curData);
        BinTreeInsert(bst, curData);
    }
    return bst;
}

