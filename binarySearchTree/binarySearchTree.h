#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_
#include <stdio.h>

#define ELEMENTTYPE int
/* 树的结点 */
typedef struct Node
{
    ELEMENTTYPE val;
    struct Node * left;
    struct Node * right;
    struct Node * parent;
}Node;

typedef struct BinarySearchTree
{
    int size;       /* 结点的个数 */
    Node * root;

} BinarySearchTree;

/* 二叉搜索树初始化 */
int binarySearchTreeInit(BinarySearchTree *pBSTree);

/* 二叉搜索树新增元素 */
int binarySearchTreeInsert(BinarySearchTree *pBSTree, ELEMENTTYPE val);

/* 二叉搜索树删除元素 */
int binarySearchTreeRemove(BinarySearchTree *pBSTree, ELEMENTTYPE val);

/* 二叉搜索树中是否包含指定元素 */
int binarySearchTreeIsContainVal(BinarySearchTree *pBSTree, ELEMENTTYPE val);

/* 二叉搜索树是否为空树 */
int binarySearchTreeIsNull(BinarySearchTree *pBSTree);

/* 二叉搜索树元素的个数 */
int binarySearchTreeGetSize(BinarySearchTree *pBSTree);

/* 前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBSTree);

/* 中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBSTree);

/* 后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBSTree);

/* 层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBSTree);

#endif  // __BINARY_SEARCH_TREE_H_