#ifndef __AVLTREE_H_
#define __AVLTREE_H_

#define ELEMENTTYPE int 



typedef struct Node
{
    int val;
    struct Node * left;
    struct Node * right;
    int  existFlag;
} Node;

typedef struct AvlTree
{
    Node * root;
    int treeNodeNum;    /* 树的结点个数 */
    int treeHeight;     /* 树的高度 */
} AvlTree;


/* 状态码 */
enum STATUSCODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERR,
    INVAILD_ACCESS,
};

/* AVL树 初始化 */
int avlTreeInit(AvlTree ** pTree);

int avlTreeInsert(AvlTree * pTree, ELEMENTTYPE val);

int avlTreeDel(AvlTree * pTree, ELEMENTTYPE val);

/* AVL树 前序遍历 */
int avlTreePrevTravel(AvlTree * pTree);

/* AVL树 中序遍历 */
int avlTreeMidTravel(AvlTree * pTree);

/* AVL树 后序遍历 */
int avlTreePostTravel(AvlTree * pTree);

/* AVL树 层序遍历 */
int avlTreeLevelTravel(AvlTree * pTree);

/* 判断结点是否是叶子结点 */
int avlTreeNodeIsLeaf(AvlTree * pTree, Node *pNode);

/* 满二叉树 */
int avlTreeIsFull(AvlTree * pTree);

/* 完全二叉树 */
int avlTreeIsCompleted(AvlTree * pTree);


#endif //__AVLTREE_H_