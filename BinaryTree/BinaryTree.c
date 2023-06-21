/**************************************************************************************
    Author: Shlomo Salomon
    Creation date :  9/8/22
    Last modified date: 10/8/22
    Description : Binary Search Tree Implementation.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ADTDefs.h"
#include "BinaryTree.h"

typedef struct Node Node_t;

struct Node
{
    int data;
    Node_t* father;
    Node_t* leftSon;
    Node_t* rightSon;
};

struct BinaryTree
{
    Node_t* root;
};

typedef enum SearchMode {
    FIND_LEAF,
    FIND_NODE
} SearchMode_t;

//Forward declaretions:
Node_t* CreateNode(int data);
Node_t* FindPlaceInTree(SearchMode_t serchMode, Node_t* node, int data);
void PrintInOrder(Node_t* node);
void PrintPreOrder(Node_t* node);
void PrintPostOrder(Node_t* node);
void NodesDestroy(Node_t* node);
int  AreSimilarTreesImp(Node_t* root1, Node_t* root2);
int IsFullTreeImp(Node_t* node);
void CheckTreeImp(Node_t* node, int* isPerfect, int* treeHeight);

BinTree_t* BinTreeCreate()
{
    BinTree_t* binTree = (BinTree_t*)calloc(1, sizeof(BinTree_t));
    if (!binTree)
    {
        return NULL;
    }

    return binTree;
}

ADTErr     BinTreeInsert(BinTree_t* binTree, int data)
{
    assert(binTree);

    Node_t* newNode = CreateNode(data);
    if (!newNode)
    {
        return ERR_ALLOCATION_FAILED;
    }

    if (!binTree->root)
    {
        binTree->root = newNode;
        return ERR_OK;
    }

    Node_t* temp = FindPlaceInTree(FIND_LEAF, binTree->root, data);
    if (!temp)
    {
        free(newNode);
        return ERR_DUPLICATION_NOT_ALLOWED;
    }

    if (temp->data > data)
    {
        temp->leftSon = newNode;
    }
    else
    {
        temp->rightSon = newNode;
    }

    newNode->father = temp;

    return ERR_OK;
}

int        BinTreeIsDataFound(BinTree_t* binTree, int data)
{
    assert(binTree);

    return !!(FindPlaceInTree(FIND_NODE, binTree->root, data));
}

void       BinTreeDestroy(BinTree_t* binTree)
{
    assert(binTree);

    NodesDestroy(binTree->root);
    free(binTree);   
}

int        AreSimilarTrees(BinTree_t* binTree1, BinTree_t* binTree2)
{
    assert(binTree1 && binTree2);

    return AreSimilarTreesImp(binTree1->root, binTree2->root);
}

int        IsFullTree(BinTree_t* binTree)
{
    assert(binTree);
    
    if (!binTree->root)
    {
        return 1;
    }
    return IsFullTreeImp(binTree->root);
}

void       CheckTree(BinTree_t* binTree, int* isPerfect, int* treeHeight)
{
    assert(binTree && isPerfect && treeHeight);

    CheckTreeImp(binTree->root, isPerfect, treeHeight);
}

//a sub function serving tree insert and is in tree function.
Node_t* FindPlaceInTree(SearchMode_t serchMode, Node_t* node, int data)
{
    Node_t* paps = NULL;

    while (node)
    {
        if (node->data > data)
        {
            if (node->leftSon)
            {
                paps = node;
                node = node->leftSon;
            }
            else 
            {
                paps = node;
                break;
            }
        }
        else if (node->data < data)
        {
            if (node->rightSon)
            {
                paps = node;
                node = node->rightSon;
            }
            else
            {
                paps = node;
                break;
            }
        }
        else 
        {
            if (serchMode == FIND_NODE)
            {
                return node;
            }
            return NULL;
        }
    }
    
    if (serchMode == FIND_LEAF)
    {
        return paps;
    }

    return NULL; 
}

//a sub function serving tree insert.
Node_t* CreateNode(int data)
{
    Node_t* node = (Node_t*)calloc(1, sizeof(Node_t));
    if (!node)
    {
        return NULL;
    }

    node->data = data;

    return node;
}

//a sub function serving tree destroy.
void NodesDestroy(Node_t* node)
{
    if (!node)
    {
        return;
    }
    NodesDestroy(node->leftSon);
    NodesDestroy(node->rightSon);
    free(node);
}

//a sub function serving are similar trees.
int  AreSimilarTreesImp(Node_t* root1, Node_t* root2)
{
    if (!root1 && !root2)
    {
        return 1;
    }
    else if (!root1 || !root2)
    {
        return 0;
    }

    return AreSimilarTreesImp(root1->leftSon, root2->leftSon) 
        && AreSimilarTreesImp(root1->rightSon, root2->rightSon);
}

//a sub function serving is full tree.
int IsFullTreeImp(Node_t* node)
{
    if (!node->leftSon && !node->rightSon)
    {
        return 1;
    }
    else if (!node->leftSon || !node->rightSon)
    {
        return 0;
    }

    return IsFullTreeImp(node->leftSon) && IsFullTreeImp(node->rightSon);
}

//a sub function serving check tree.
void CheckTreeImp(Node_t* node, int* isPerfect, int* treeHeight)
{
    int isLeftPerfct = 0, isRightPerfect = 0, leftHeight = 0, rightHeight = 0;

    if (!node)
    {
        *isPerfect = 1;
        *treeHeight = -1;
        return;
    }

    CheckTreeImp(node->leftSon, &isLeftPerfct, &leftHeight);
    CheckTreeImp(node->rightSon, &isRightPerfect, &rightHeight);
   
    *isPerfect = isLeftPerfct && isRightPerfect && leftHeight == rightHeight;
    *treeHeight = (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

/*  Unit-Test functions  */

void BinTreePrint(BinTree_t* binTree, TraversalMode_t printMode)
{
    assert(binTree);

    printf("Tree items: ");
    if (printMode == PREORDER)
    {
        PrintPreOrder(binTree->root);
    }
    else if (printMode == POSTORDER)
    {
        PrintPostOrder(binTree->root);
    }
    else
    {
        PrintInOrder(binTree->root);
    }
    printf("\n");
}

//a sub function serving tree print.
void PrintInOrder(Node_t* node)
{
    if (!node)
    {
        return;
    }

    PrintInOrder(node->leftSon);
    printf("%d, ", node->data);
    PrintInOrder(node->rightSon);
}

//a sub function serving tree print.
void PrintPreOrder(Node_t* node)
{
    if (!node)
    {
        return;
    }

    printf("%d, ", node->data);
    PrintInOrder(node->leftSon);
    PrintInOrder(node->rightSon);
}

//a sub function serving tree print.
void PrintPostOrder(Node_t* node)
{
    if (!node)
    {
        return;
    }

    PrintInOrder(node->leftSon);
    PrintInOrder(node->rightSon);
    printf("%d, ", node->data);
}

/*  practicing functions   */

//Forward declarations:
void PrintLeafsNodes(Node_t* node);
Node_t* GetBiggestNode(Node_t* node);
Node_t* GetSmallestNode(Node_t* node);
size_t GetNodesHeight(Node_t* node);

void PrintLeafs(BinTree_t* binTree)
{
    PrintLeafsNodes(binTree->root);
}

//a sub function serving print leafs.
void PrintLeafsNodes(Node_t* node)
{
    if (!node)
    {
        return;
    }

    PrintLeafsNodes(node->leftSon);
    PrintLeafsNodes(node->rightSon);
    if (!node->leftSon && !node->rightSon)
    {
        printf("%d, ", node->data);
    }
}

int GetBiggestInTree(BinTree_t* binTree)
{
    Node_t* biggestNode = GetBiggestNode(binTree->root);
    return biggestNode->data;
}

//a sub function serving get biggest.
Node_t* GetBiggestNode(Node_t* node)
{
    if (!node->rightSon)
    {
        return node;
    }
    
    return GetBiggestNode(node->rightSon);
}

int GetSmallestInTree(BinTree_t* binTree)
{
    Node_t* smallestNode = GetSmallestNode(binTree->root);
    return smallestNode->data;
}

Node_t* GetSmallestNode(Node_t* node)
{
    if (!node->leftSon)
    {
        return node;
    }

    return node->leftSon;
}

size_t GetTreeHeight(BinTree_t* binTree)
{
    if (binTree)
    {
        return GetNodesHeight(binTree->root) - 1;
    }
    return 0;
}

size_t GetNodesHeight(Node_t* node)
{
    if (!node)
    {
        return 0;
    }

    size_t left = (size_t)GetNodesHeight(node->leftSon);
    size_t right = (size_t)GetNodesHeight(node->rightSon);
    if (left > right)
    {
        return 1 + left;
    }
    else {
        return 1 + right;
    }
}