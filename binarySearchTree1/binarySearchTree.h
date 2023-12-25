#ifndef __BINARYSEARCHTREE_H_
#define __BINARYSEARCHTREE_H_

#define ELEMENTTYPE int 

typedef struct BSTreeNode
{
    ELEMENTTYPE data;
    struct BSTreeNode *left;        /* 左子树*/
    struct BSTreeNode *right;       /* 右子树*/

    #if 1
    struct BSTreeNode *parent;      /* 父节点 */           
     
    #endif 
} BSTreeNode;

typedef struct BinarySearchTree
{
    /* 根节点 */
    BSTreeNode *root;
    /* 树的节点个数 */
    int size;
} BinarySearchTree;


/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree);

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree);
















#endif