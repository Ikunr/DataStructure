#include "avlTree.h"

#include <stdlib.h>
#include <string.h>


#define CHECK_PTR(ptr)      \
    do                      \
    {                       \
        if (ptr == NULL)    \
        {                   \
            exit(0);        \
        }                   \
    }while(0);


/* 函数前置声明 */
static int avlTreeInsertNode(AvlTree * pTree, Node * node, ELEMENTTYPE val);


int avlTreeInit(AvlTree ** pTree)
{
    int ret = 0;

    AvlTree * ptree = (AvlTree *)malloc(sizeof(AvlTree) * 1);
    if (!ptree)
    {
        return NULL_PTR;
    }

    memset(ptree, 0, sizeof(AvlTree) * 1);

    /* 根结点分配数据 */
    ptree->root = (Node *)malloc(sizeof(Node) * 1);
    if (!(ptree->root))
    {
        return NULL_PTR;
    }
    memset(ptree->root, 0, sizeof(Node) * 1);
    /* 将结点里面的数据置空 */
    {   
        ptree->root->left = NULL;
        ptree->root->right = NULL;
        ptree->root->val = 0;
        ptree->root->existFlag = 0; /* 初始化结点不存在数据 */
    }

    /* todo... */   
    ptree->treeHeight = 0;

    *pTree = ptree;
    return ret;
}

static Node * createNode(ELEMENTTYPE val)
{
    Node * newNode = (Node *)malloc(sizeof(Node) * 1);
    if (!newNode)
    {
        return NULL_PTR;
    }

    memset(newNode, 0, sizeof(Node) * 1);
    newNode->existFlag = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val  = val;

    return newNode;
}


static int avlTreeInsertNode(AvlTree * pTree, Node * pRoot, ELEMENTTYPE val)
{
    int ret;

    Node * newNode = createNode(val);

    /* 当前根结点的数据 比 插入的数据小. 要插左边 */
    if (val < pTree->root->val)
    {
        avlTreeInsertNode(pTree, pTree->root->left, val);
        pTree->root->left = createNode;
    }
    else if (val > pTree->root->val)
    {
        /* 当前根结点的数据 比 插入的数据小. 要插右边 */
        avlTreeInsertNode(pTree, pTree->root->right, val);
             
    }
    else    /* pTree->root->val == val */
    {

    }

    
    return ret;
}



int avlTreeInsert(AvlTree * pTree, ELEMENTTYPE val)
{
    CHECK_PTR(pTree);

    /* 空树: 直接将数据给根结点 */
    if (pTree->treeHeight == 0)
    {
        pTree->root->val = val;
    }
    else
    {
        /* 树不为空 */
        /* 将根结点 与 要插入的数据做比较 */
        return avlTreeInsertNode(pTree, pTree->root, val);
    }
}


int avlTreeDel(AvlTree * pTree, ELEMENTTYPE val)
{
    
}


int avlTreeGetHeight(AvlTree * pTree, int *pHeight)
{
    int ret = 0;
    CHECK_PTR(pTree);
    CHECK_PTR(pHeight);

    /* todo... */


    return ret;
}   



/* 满二叉树 */
int avlTreeIsFull(AvlTree * pTree)
{
    /* 除了叶子结点外, 其余结点都有左右结点 */
    int ret = 0;

    return ret;
}


/* 完全二叉树 */
int avlTreeIsCompleted(AvlTree * pTree)
{
    /* 完全二叉树: 前N层是满的, 最后一层不满, 但是最后一层必须是从左到右是连续的.
        (有右结点，一定有左结点, 否则就不是完全二叉树) 
    */
    int ret = 0;
    return ret;
}

/* 判断结点是否是叶子结点 */
int avlTreeNodeIsLeaf(AvlTree * pTree, Node *pNode)
{
    int ret = 0;
    CHECK_PTR(pTree);
    CHECK_PTR(pNode);


    return ret;
}


/* AVL树 前序遍历 */
int avlTreePrevTravel(AvlTree * pTree)
{
    int ret = 0;
    CHECK_PTR(pTree);



    return ret;
}

/* AVL树 中序遍历 */
int avlTreeMidTravel(AvlTree * pTree)
{
    int ret = 0;
    CHECK_PTR(pTree);



    return ret;
}

/* AVL树 后序遍历 */
int avlTreePostTravel(AvlTree * pTree)
{
    int ret = 0;
    CHECK_PTR(pTree);



    return ret;
}

/* AVL树 层序遍历 */
int avlTreeLevelTravel(AvlTree * pTree)
{
    int ret = 0;
    CHECK_PTR(pTree);



    return ret;
}
