#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doubleLinkListQueue.h"


/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 静态函数前置声明!!!! */

static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);
/* 创建新的节点 */
static BSTreeNode* createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *pParent);
/* 根据指定的值获取二叉搜索树的节点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val);
/* 判断二叉搜索树度为2 */
static int binarySearchTreeNodeHasTwoChildren(BSTreeNode * node);
/* 判断二叉搜索树度为1 */
static int binarySearchTreeNodeHasOneChildren(BSTreeNode * node);
/* 判断二叉搜索树度为0 */
static int binarySearchTreeNodeIsLeaf(BSTreeNode * node);
/* 前序遍历 */
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node);
/* 中序遍历 */
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node);
/* 后序遍历 */
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node);
/* 获取当前节点的前驱节点 */
static BSTreeNode * bstreeNodePreDEcessor(BSTreeNode *node);
/* 获取当前节点的后继节点 */
static BSTreeNode * bstreeNodeSuccessor(BSTreeNode *node);


/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printfFunc)(ELEMENTTYPE val))
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

#if 0
    /* 分配根节点 */
    BSTree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if(!BSTree->root)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(BSTree->root, 0, sizeof(BSTreeNode) * 1);

    {
        BSTree->root->left = NULL;
        BSTree->root->right = NULL;
        BSTree->root->parent = NULL;
        BSTree->root->data = 0;
    }
#else 
    /* 初始化树 */
    {
        BSTree->root = createBSTreeNewNode(0, NULL);
        BSTree->size = 0;
        /* 钩子函数在这边赋值 */
        BSTree->compareFunc = compareFunc;
        /* 钩子函数包装器 自定义打印  */
        BSTree->printfFunc = printfFunc;
    }
#endif

    *pBstree = BSTree; 
    return ret;
}

/* 判断二叉搜索树度为2 */
static int binarySearchTreeNodeHasTwoChildren(BSTreeNode * node)
{
    return (node->left != NULL) && (node->right != NULL) ? 1 : 0;
}
/* 判断二叉搜索树度为1 */
static int binarySearchTreeNodeHasOneChildren(BSTreeNode * node)
{
    return ((node->left == NULL) && (node->right != NULL)) || ((node->left != NULL) && (node->right == NULL));
}
/* 判断二叉搜索树度为0 */
static int binarySearchTreeNodeIsLeaf(BSTreeNode * node)
{
    return (node->left == NULL) && (node->right == NULL);
}

/* 获取当前节点的前驱节点 */
static BSTreeNode * bstreeNodePreDEcessor(BSTreeNode *node)
{
    /* 度为2 */
    if (binarySearchTreeNodeHasTwoChildren(node))
    {
        /* 度为2 一定在左子树的右子树右子树 */
        BSTreeNode * travelNode = node->left;
        while(travelNode->right != NULL)
        {
            travelNode = travelNode->right;
        }
        return travelNode;
    }

    /* 程序到这个地方一定是度为1 或者 度为0的 */
    /* 度为1 */


    /* 度为0 */
}

/* 获取当前节点的后继节点 */
static BSTreeNode * bstreeNodeSuccessor(BSTreeNode *node)
{

}

 /* 二叉搜索树新增节点 */
static BSTreeNode* createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *pParent)
{
    /* 分配新节点 */
    BSTreeNode * newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (!newBstNode)
    {
        return NULL;
    }
    /* 清除脏数据 */
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);

    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }

    /* 赋值 */
    newBstNode->data = val;
    newBstNode->parent = pParent;
    return newBstNode;
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
        cmp = pBstree->compareFunc(val, travelNode->data);
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
#if 0    
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

#else
    BSTreeNode * newBstNode = createBSTreeNewNode(val, parentNode);
#endif
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

#if 0
    /* 新结点的parent指针赋值 */
    newBstNode->parent = parentNode;
#endif
    (pBstree->size)++;
    return ret;
}

/* 根据指定的值获取二叉搜索树的节点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    BSTreeNode * travelNode = pBstree->root;

    int cmp = 0;
    while(travelNode != NULL)
    {
        /* 比较大小 */
        cmp = pBstree->compareFunc(val, travelNode->data);
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            /* 找到了 */
            return travelNode;
        }

    }
    return NULL;
}

/* 二叉搜索树是否包含某个元素*/
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    return baseAppointValGetBSTreeNode(pBstree, val) == NULL ? 0 : 1;
}

/* 前序遍历 */
/* 跟结点 左子树 右子树 */
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node)
{
    int ret = 0;
    
    if (node == NULL)
    {
        return ret;
    }
    /* 跟结点 */
    pBstree->printfFunc(node->data);
    /* 左边子树 */
    inOrderTravel(pBstree, node->left);
    /* 右子树 */
    inOrderTravel(pBstree, node->right);
}

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    preOrderTravel(pBstree, pBstree->root);

    return ret;
}

/* 中序遍历 */
/* 左子树 跟结点 右子树 */
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node)
{
    int ret = 0;
    
    if (node == NULL)
    {
        return ret;
    }
    /* 左边子树 */
    inOrderTravel(pBstree, node->left);
    /* 跟结点 */
    pBstree->printfFunc(node->data);
    /* 右子树 */
    inOrderTravel(pBstree, node->right);

}

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{   
    int ret = 0;
    inOrderTravel(pBstree, pBstree->root);

    return ret;
}

/* 后序遍历 */
/* 左子树 右子树 跟结点 */
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode * node)
{
    int ret = 0;
    
    if (node == NULL)
    {
        return ret;
    }
    /* 左边子树 */
    inOrderTravel(pBstree, node->left);
    /* 右子树 */
    inOrderTravel(pBstree, node->right);
    /* 跟结点 */
    pBstree->printfFunc(node->data);
}

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    postOrderTravel(pBstree, pBstree->root);
    return ret;
}

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    if (!pBstree)
    {
        return -1;
    }
    /* 算法 */

    /* 初始化一个队列 */
    DoubleLinkListQueue *queue = NULL;
    doubleLinkListQueueInit(&queue);
    
    /* 将根结点入队 */
    doubleLinkListQueuePush(queue, pBstree->root);

    /* 2. 判断队列是否为空 */
    BSTreeNode *nodeVal = NULL;
    while(!doubleLinkListQueueIsEmpty(queue))
    {
        doubleLinkListQueueTop(queue, (void **)&nodeVal);
#if 0
        printf("%d\n", nodeVal->data);
#else
        pBstree->printfFunc(nodeVal->data);
#endif
        doubleLinkListQueuePop(queue);

        /* 将左子树入队 */
        if (nodeVal->left != NULL)
        {
            doubleLinkListQueuePush(queue, nodeVal->left);
        }

        /* 将右子树入队 */
        if (nodeVal->right != NULL)
        {
            doubleLinkListQueuePush(queue, nodeVal->right);
        }
    }

    /* 释放队列 */
    doubleLinkListQueueDestroy(queue);

    return ret;
}

/* 获取二叉搜索树的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree, int *pHeight)
{
    if (!pBstree)
    {
        return NULL_PTR;
    }

    int ret = 0;
    /* 判断是否为空树 */
    if (pBstree->size == 0)
    {
        return 0;
    }

    DoubleLinkListQueue * pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);

    doubleLinkListQueuePush(pBstree, pBstree->root);
    /* 树的高度（ 根节点入队高度为1 ）*/
    int height = 0;
    /* 树的每一层结点的数量 */
    int leaveSize = 1;

    BSTreeNode * newNode = NULL;


    while(!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&newNode);
        doubleLinkListQueuePop(pQueue);
        leaveSize--;

        /* 左子树不为空 入队 */
        if (newNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, newNode->left);
        }
        /* 右子树不为空 入队 */
        if (newNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, newNode->right);
        }
        /* 树的当前层结点遍历结束 */
        if (leaveSize == 0)
        {
            height++;
            doubleLinkListQueueGetSize(pQueue, &leaveSize);
        }
    }   

    /* 解引用 */
    *pHeight = height;

    /* 释放队列 */
    return ret;

}

/* 二叉搜索树的删除 */
int binarySearchTreeDelete(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;


    return ret;
}

/* 二叉搜索树的销毁 */
int  binarySearchTreeDestroy(BinarySearchTree *pBstree)
{
    int ret = 0;

    if (!pBstree)
    {
        return NULL_PTR;
    }

    DoubleLinkListQueue * pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);

    doubleLinkListQueuePush(pBstree, pBstree->root);

    BSTreeNode * travleNode = NULL;

    while(!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&travleNode);
        doubleLinkListQueuePop(pQueue);
        
        /* 左子树不为空 入队 */
        if (travleNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, travleNode->left);
        }
        /* 右子树不为空 入队 */
        if (travleNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, travleNode->right);
        }

        /* 最后释放 */
        if (travleNode)
        {
            free(travleNode);
            travleNode = NULL;
        }
    }
    /* 销毁队列 */
    doubleLinkListQueueDestroy(pQueue);

    /* 树的销毁 */
    if (pBstree)
    {
        free(pBstree);
        pBstree = NULL;
    }
    return ret;
}