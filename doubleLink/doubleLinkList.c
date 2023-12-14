#include "doubleLinkList.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* 宏函数 进行判空处理 */
#define CHECK_PTR(ptr)      \
    do                      \
    {                       \
        if (ptr == NULL)    \
        {                   \
            exit(0);        \
        }                   \
                            \
    } while (0);            \
    

enum STATUSCODE
{
    ON_SUCCESS,
    NULL_PTR,
    CREATE_ERR,
    INVALID_PALACE,
    MALLOC_ERR,     
};





int initLinkList(LinkList *list)
{
    int ret = 0;

    list->head = NULL;
    list->tail = NULL;
    list->len = 0;

    return ret;
}

/* 创节点 */
static Node * createNewNode(ELEMENTTYPE element)
{
    Node * newNode = (Node *)malloc(sizeof(Node) * 1);
    if(!newNode)
    {
        printf("creater malloc error!\n");
        return NULL;
    }
    memset(newNode, 0, sizeof(Node));

    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = element;

    return newNode;
}

/* 头插 */
int insertLinkListHead(LinkList *list, ELEMENTTYPE element)
{
#if 0
    int ret = 0;

    Node * newNode = createNewNode(element);
    if(!newNode)
    {
        printf("insert newNode error!\n");
        return -1;
    }

    if(list->len == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->len++;

    return ret;
#else

    CHECK_PTR(list);

    return insertLinkListIndex(list, element, 0);

#endif
}

/* 尾插 */
int insertLinkListTail(LinkList *list, ELEMENTTYPE element)
{
#if 0
    int ret = 0;

    Node * newNode = createNewNode(element);
    if (!newNode)
    {
        printf("insertLinkListTail newnode error!\n");
        return - 1;
    }
    
    /* 链表里什么都没有 */
    if(list->len == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }

    list->len++;

    return ret;
#else

    CHECK_PTR(list);

    int index = list->len;
    return insertLinkListIndex(list, element, index);

#endif

}

/* 中间插 */
int insertLinkListIndex(LinkList *list, ELEMENTTYPE element, int index)
{
    CHECK_PTR(list);

    int ret = 0;
    Node * newNode = createNewNode(element);
    if (!newNode)
    {
        printf("insertLinkListIndex newnode error!\n");
        return CREATE_ERR;
    }
    /* 非法位置判断 */
    if(index < 0 || index > list->len)
    {
        printf("invidal palace");
        return INVALID_PALACE;
    }

    /* 判断插入的位置 */
    if (list->len == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else if (index == 0)
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    else if (index == list->len)
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;                                                                                                                                                

    }
    else
    {
        /* 创建一个遍历节点找到index的位置 */
        Node * travelPoint = list->head;
        for (int idx = 0; idx < index - 1; idx++)
        {
            travelPoint = travelPoint->next;
        }

        newNode->next = travelPoint->next;
        newNode->prev = travelPoint;
        travelPoint->next->prev = newNode;
        travelPoint->next = newNode;
    }

    list->len++;
    return ret;
}

int removeLinkListIndex(LinkList *list, int index)
{
    int ret = 0;

    if (index < 0 || index >= list->len)
    {
        printf("removeLinkListIndex invalid palace!\n");
        return INVALID_PALACE;
    }

    if (index == 0)
    {
        if(list->len == 1)
        {
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            list->len = 0;
            return ret;
        }
        Node *freeNode = list->head;
        list->head = freeNode->next;
        list->head->prev = NULL;
        free(freeNode);
        list->len--;
        return ret;
    }
    else if(index == list->len - 1)
    {
#if 0        
        /* 遍历到末尾的前一个O(n) 效率太慢 */

        // Node *travelPoint = list->head;

        // for(int idx = 0; idx < index - 1; idx++)
        // {
        //     travelPoint = travelPoint->next;
        // } 
        
        // Node * freeNode = travelPoint->next;

        // //travelPoint->next = freeNode->next;

        // travelPoint->next = NULL;
        // list->tail = travelPoint;
        // free(freeNode);
        // list->len--;
        // return ret;
#else
        /* 利用尾指针 O(1) */

        Node *travelPoint = list->tail->prev;
        Node *freeNodePoint = list->tail;   
        travelPoint->next = NULL;
        list->tail = travelPoint;
        free(freeNodePoint);
        list->len--;
        return ret;

    }
#endif    
    else
    {
        /* 找到index要删除的位置 */
        Node * travelPoint = list->head;

        for(int idx = 0; idx < index - 1; idx++)
        {
            travelPoint = travelPoint->next;
        } 
#if 1 
        /* 删除 */
        Node * freeNode = travelPoint->next;
        travelPoint->next = freeNode->next;
        freeNode->next->prev = travelPoint;
        free(freeNode);
    
#endif

    }

    list->len--;
    return ret;
}

int removeLinkListElement(LinkList *pList, ELEMENTTYPE element)
{
    int ret = 0;
    CHECK_PTR(pList);

    int * findArray = findLinkListElement(pList,element);
    
    int idx = 1;
    int pos = findArray[idx];
    for(idx; idx <= findArray[0]; idx++)
    {
        removeLinkListIndex(pList, pos);
        pos = findArray[idx + 1] - 1;
    }

    free(findArray);

    return ret;
}

int* findLinkListElement(LinkList *pList, ELEMENTTYPE element)
{
    CHECK_PTR(pList);

    /* index 记录下标 */ 
    /* findCount 记录找到元素的个数 */

    int index = 0;
    int findCountNum = 0;

    Node * travelPoint = pList->head;
    while(travelPoint != NULL)
    {
        if(travelPoint->data == element)
        {
            findCountNum++;
        }
        travelPoint = travelPoint->next;
        index++;
    }

    /* 判断是否找到 */
    if(findCountNum == 0)
    {
        printf("can not find num!\n");
        return NULL;
    }

    /* 申请找到数量+1的指针大小 */
    int * newPoint = (int *)malloc(sizeof(int) * (findCountNum + 1));
    if(!newPoint)
    {
        return NULL;
    }

    memset(newPoint, 0, sizeof(int) * (findCountNum + 1));

    /* 将数组的[0]的位置放我们的数量   后面的位置放索引的位置  */
    findCountNum = 1;
    index = 0;

    Node * travelPoint_index = pList->head;
    while(travelPoint_index != NULL)
    {
        if(travelPoint_index->data == element)
        {
            newPoint[findCountNum] = index;
            findCountNum++;
        }
        travelPoint_index = travelPoint_index->next;
        index++;
    }
    newPoint[0] = findCountNum - 1;
    
    return newPoint;
    
}

int getLinkListLen(LinkList *pList)
{
    CHECK_PTR(pList);

    return pList->len - 1;
}

int changeIndexLinkList(LinkList *pList, int index, ELEMENTTYPE element)
{
    CHECK_PTR(pList);

    int ret = 0;

    if(index < 0 || index >= pList->len)
    {
        printf("changeIndexLinkList invalid place!\n");
        return INVALID_PALACE;
    }

    Node * travelPoint = pList->head;

    if(index == 0)
    {
        travelPoint->data = element;
        return ret;
    }

    for (int idx = 0; idx < index - 1; idx++)
    {
        travelPoint = travelPoint->next;
    }

    travelPoint->next->data = element;

    return ret;
}

/* 打印函数 */
void printLinkListValue(LinkList *list)
{
    CHECK_PTR(list);
    
    struct Node * travlePoint = list->head;
    while(travlePoint != NULL)
    {
        printf(" %d", travlePoint->data);
        travlePoint = travlePoint->next;
    }

    printf("\n");
}

int freeLinkList(LinkList *pList)
{
    int ret = 0;
    CHECK_PTR(pList);

    Node * travelPoint = pList->head;

    while(travelPoint != NULL)
    {
        removeLinkListIndex(travelPoint, 0);
    }
    return ret;
}
