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

static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
#if 0
    if (val1 < val2)
    {
        return -1;
    }
    else if (val1 > val2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
#else
    return val1 - val2;
#endif
}
                                   
/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;

    /* 空树*/
    if (pBstree->size == 0)
    {   
        /* 更新树的节点 */
        pBstree->root->data = val;

        (pBstree->size)++;
        return ret;
    }

    /* 标记根节点的位置 travelNode指向根节点 */
    BSTreeNode * travelNode = pBstree->root;

    BSTreeNode * parentNode = pBstree->root;

    /* 比较传入的值 确定符号 ：到底放在左边还是右边 */
    int cmp = 0;

    while (travelNode != NULL)
    {
        /* 标记父节点 */
        parentNode = travelNode;
        cmp = compareFunc(val, travelNode->data);
        /* 插入元素 < 遍历到的节点 */
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if(cmp > 0)     /* 插入元素 > 遍历到的节点 */
        {
            travelNode = travelNode->right;
        }
        else                                
        {
            /* 插入元素 = 遍历到的节点 */  
            return ret;
        }
    }
    
    /* 分配新节点 */
    BSTreeNode * newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (!newBstNode)
    {
        return MALLOC_ERROR;
    }

    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);

    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }

    /* 新节点赋值 */
    newBstNode->data = val;

    /* 挂在左子树 */
    if (cmp < 0)
    {
        parentNode->left = newBstNode;
    }
    else
    {
        /* 挂在右子树 */
        parentNode->right = newBstNode;
    }

    /* 新结点的parent指针赋值 */
    newBstNode->parent = parentNode;

    (pBstree->size)++;
    return ret;
}