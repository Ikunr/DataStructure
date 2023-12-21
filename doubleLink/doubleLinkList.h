#ifndef __DOUBLELINKLIST_H__
#define __DOUBLELINKLIST_H__

#define ELEMENTTYPE void*


typedef struct Node
{
    ELEMENTTYPE data;
    struct Node *next;
    struct Node *prev;

}Node;

typedef struct LinkList
{
    Node *head;  // 头节点
    Node *tail;  // 尾节点
    int len;

}LinkList;

/* 初始化 */
int initLinkList(LinkList * list);                
                         
/* 头插 */
int insertLinkListHead(LinkList *list, ELEMENTTYPE element);

/* 尾插 */
int insertLinkListTail(LinkList *list, ELEMENTTYPE element);

/* 按位插 */
int insertLinkListIndex(LinkList *list, ELEMENTTYPE element,int index);

/* 按位删除 */
int removeLinkListIndex(LinkList *list, int index);

/* 按值删除 */
int removeLinkListElement(LinkList *pList, ELEMENTTYPE element, int (*deleteIndex)(ELEMENTTYPE, ELEMENTTYPE));

/* 按值查找 */
int * findLinkListElement(LinkList *pList,ELEMENTTYPE element, int (*deleteIndex)(ELEMENTTYPE, ELEMENTTYPE));

/* 获取链表的长度 */
int getLinkListLen(LinkList *pList);

/* 按位改值 */
int changeIndexLinkList(LinkList *pList, int index, ELEMENTTYPE element);

/* 打印 */
int printLinkListValue(LinkList *list, int (*printCall)(ELEMENTTYPE));

/* 释放链表 */
//int freeLinkList(LinkList *pList);






#endif