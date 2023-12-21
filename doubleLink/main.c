#include "doubleLinkList.h"
#include <stdlib.h>
#include <stdio.h>

#define BUFFSIZE 10

int isEquallCall(void *arg1, void *arg2)
{
    int data1 = *(int*)arg1;
    int data2 = *(int*)arg2;

    return data1 == data2 ;
}

int printfCall(void *arg)
{
    int data1 = *(int*)arg;
    printf("%d\n", data1);
}


#define LIST_NUM 10

int main()
{
    LinkList list;
    initLinkList(&list);

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9} ;

    int len = sizeof(array) / sizeof(array[0]);

    for(int idx = 0; idx < len; idx++)
    {
        insertLinkListTail(&list, (void*)&array[idx]);
    }
   
    // insertLinkListTail(&list, 1);
    // insertLinkListTail(&list, 3);
    // insertLinkListTail(&list, 3);
    // insertLinkListTail(&list, 4);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListIndex(&list,99,4);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);
    // insertLinkListTail(&list, 5);

    printLinkListValue(&list, printfCall);

    //printf("len:%d\n", list.len);

    // for(int idx = 0; idx < LIST_NUM; idx++)
    // {
    //     // insertLinkListTail(&list, idx);
    //     //insertLinkListHead(&list,idx);
    //     //insertLinkListIndex(&list, idx + 1, 0);
    // }

    //insertLinkListHead(&list,5);

    // removeLinkListIndex(&list,4);


    //printLinkListValue(&list);

    //removeLinkListElement(&list,5);
    
    int data1 = 1;
    int *findNum = findLinkListElement(&list, &data1, isEquallCall);

    if (findNum)
    {
        for (int idx = 0; idx <= findNum[0]; idx++)
        {
            printf("%d ", findNum[idx]);
        }
        printf("\n");
        free(findNum);
    }
    // printLinkListValue(&list);

#if 1
    printf("\n");
    /* bug */
    int data = 5;
    removeLinkListElement(&list, &data, isEquallCall);
    //removeLinkListIndex(&list,0);
    printLinkListValue(&list, printfCall);
#else
    removeLinkListIndex(&list,0);
    removeLinkListIndex(&list,0);
    printLinkListValue(&list);


#endif


    // removeLinkListIndex(&list,getLinkListLen(&list));

    // printLinkListValue(&list);

    // removeLinkListIndex(&list,1);
    
    // printLinkListValue(&list);


    //changeIndexLinkList(&list, 3, 99);
    //printLinkListValue(&list);

    
}