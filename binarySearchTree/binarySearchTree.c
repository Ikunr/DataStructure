#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 二叉搜索树初始化 */
int binarySearchTreeInit(BinarySearchTree *pBSTree)
{
    int ret = 0;
    
    pBSTree->root = (Node *)malloc(sizeof(Node) * 1);
    if(!pBSTree->root)
    {
        printf("binarySearchTreeInit malloc error!\n");
        return -1;
    }

    memset(pBSTree->root, 0, sizeof(sizeof(Node) * 1));

    pBSTree->size = 0;
    pBSTree->root->left = NULL;
    pBSTree->root->parent = NULL;
    pBSTree->root->right = NULL;
    pBSTree->root->val = 0;

    return ret;
}

/* 结点比较函数, 配置不同的类型进行比较 */
/* todo... 后面把它做成包装器 */

static int nodeCompare(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    return val1 - val2;
}

/* 创建新的结点 */
static Node *createBstTreeNode(ELEMENTTYPE val)
{
    Node *newNode = (Node*)malloc(sizeof(Node) * 1);
    if (newNode == NULL)
    {
        return NULL;
    }
    memset(newNode, 0, sizeof(Node) * 1);
    {
        /* 开辟的新结点赋值 */
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
    }
    return newNode;
}
/* 二叉搜索树新增元素 */
int binarySearchTreeInsert(BinarySearchTree *pBSTree, ELEMENTTYPE val)
{
    int ret = 0;
    /* 空树 */
    if (pBSTree->size == 0)
    {
        pBSTree->root->val = val;
        pBSTree->size++;
        return ret;
    }

    Node *parentNode = pBSTree->root;
    Node *travelNode = pBSTree->root;
    
    int cmp = 0;
    while (travelNode != NULL)
    {
        parentNode = travelNode;
        cmp = nodeCompare(val, travelNode->val);
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
            return ret;
        }
    }

    /* 新增树结点并赋值 */
    Node * newNode = createBstTreeNode(val);
    if (newNode == NULL)
    {
        /* todo... */
        return ret;
    }
    
    if (cmp < 0)
    {
        /* 新结点插入到左子树 */
        parentNode->left = newNode;
        newNode->parent = parentNode;
    }
    else
    {
        /* 新结点插入到左子树 */
        parentNode->right = newNode;
        newNode->parent = parentNode;
    }
    pBSTree->size++;
    return ret;
}

/* 二叉搜索树删除元素 */
int binarySearchTreeRemove(BinarySearchTree *pBSTree, ELEMENTTYPE val)
{
    int ret = 0;

    if (pBSTree == NULL)
    {
        return 1;
    }

    Node * parent = NULL;
    Node * travelPoint = pBSTree->root;

    /* 一直找 */
    while(travelPoint != NULL && travelPoint->val != val)
    {   
        parent = travelPoint;
        if(val < travelPoint->val)
        {
            travelPoint = travelPoint->left;
        }
        else
        {
            travelPoint = travelPoint->right;
        }
    }
    /* 如果该节点是叶子节点 */
    if(travelPoint != NULL)
    {
        if(travelPoint->left == NULL && travelPoint->right == NULL)
        {
            if(parent == NULL)
            {
                pBSTree->root = NULL;
            }
            else if(travelPoint == parent->left)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }

            free(travelPoint);
        }
        /* 如果只有一边是叶子节点的话 */
        else if (travelPoint->left == NULL || travelPoint->right == NULL)
        {
            Node *child = (travelPoint->left != NULL) ? travelPoint->left : travelPoint->right;
            if (parent == NULL)
            {
                /* 根节点只有一个子节点 */
                pBSTree->root = child;
            }
            else if (travelPoint == parent->left)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
            free(travelPoint);
        }
        /* 如果该节点有两个子节点 */
        else
        {
            Node *successor = travelPoint->right;
            Node *successorParent = travelPoint;
            while (successor->left != NULL)
            {
                successorParent = successor;
                successor = successor->left;
            }
            if (successorParent != travelPoint)
            {
                successorParent->left = successor->right;
                successor->right = travelPoint->right;
            }
            successor->left = travelPoint->left;
            if (parent == NULL)
            {
                /* 根节点有两个子节点 */
                pBSTree->root = successor;
            }
            else if (travelPoint == parent->left)
            {
                parent->left = successor;
            }
            else
            {
                parent->right = successor;
            }
            free(travelPoint);
        }
        ret = 0;  // 删除成功
    }
    

    return ret;
}

/* 二叉搜索树中是否包含指定元素 */
int binarySearchTreeIsContainVal(BinarySearchTree *pBSTree, ELEMENTTYPE val)
{
    int ret = 0;

    return ret;
}

/* 二叉搜索树是否为空树 */
int binarySearchTreeIsNull(BinarySearchTree *pBSTree)
{
    if (pBSTree == NULL)
    {
        return 1;
    }
    return (pBSTree->size == 0) ? 1 : 0;
}

/* 二叉搜索树元素的个数 */
int binarySearchTreeGetSize(BinarySearchTree *pBSTree)
{
    if (!pBSTree)
    {
        return 0;
    }
    return pBSTree->size;
}

static void binarySearchTreePreOrder(Node *node)
{   
    /* 递归结束的条件 */
    if (node == NULL)
    {
        return;
    }
    printf("%d\n", node->val);
    binarySearchTreePreOrder(node->left);
    binarySearchTreePreOrder(node->right);
}

/* 前序遍历 */
/* 访问顺序: 根结点, 前序遍历左子树, 前序遍历右子树 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBSTree)
{
    int ret = 0;
    if (pBSTree == NULL)
    {
        return ret;
    }
    binarySearchTreePreOrder(pBSTree->root);
    return ret;
}

static int binarySearchTreeInOrder(Node *node)
{

}

/* 中序遍历 */
/* 访问顺序: 遍历左子树, 根结点, 前序遍历右子树 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBSTree)
{
    int ret = 0;
    if (pBSTree == NULL)
    {
        return ret;
    }
    binarySearchTreeInOrder(pBSTree->root);
    return ret;
}


static void binarySearchTreePostOrder(Node *node)
{
    
}

/* 后序遍历 */
/* 访问顺序: 遍历左子树, 右结点,  跟节点 , 前序遍历右子树 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBSTree)
{
    int ret = 0;
    if (pBSTree == NULL)
    {
        return ret;
    }
    binarySearchTreePostOrder(pBSTree->root);
    return ret;
}

static void binarySearchTreeLevelOrder(Node *node)
{
    
}

/* 层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBSTree)
{
    int ret = 0;

    if (pBSTree == NULL)
    {
        return ret;
    }

    binarySearchTreeLevelOrder(pBSTree->root);
    
    return ret;
}

