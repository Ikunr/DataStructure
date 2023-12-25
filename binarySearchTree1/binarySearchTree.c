#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};



/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree)
{
    int ret = 0;
    BinarySearchTree *BSTree = (BinarySearchTree *)malloc(sizeof(BSTreeNode) * 1);
    if(!BSTree)
    {
        return MALLOC_ERROR;
    }

    /* 清楚脏数据*/
    memset(BSTree, 0, sizeof(BSTreeNode ) * 1);
    /* 初始化树 */
    {
        BSTree->root = NULL;
        BSTree->size = 0;
    }

#if 1
    /* 分配根节点 */
    BSTree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if(!BSTree->root)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(BSTree->root, 0, sizeof(BSTreeNode) * 1);

#endif
    {
        BSTree->root->left = NULL;
        BSTree->root->right = NULL;
        BSTree->root->parent = NULL;
        BSTree->root->data = 0;
    }

    *pBstree = BSTree; 
    return ret;
}

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree **pBstree, ELEMENTTYPE val)
{

}