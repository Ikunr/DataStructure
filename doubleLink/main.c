#include "doubleLinkList.h"
#include <stdlib.h>
#include <stdio.h>



#define LIST_NUM 10

int main()
{
    LinkList list;
    initLinkList(&list);

    insertLinkListTail(&list, 1);
    insertLinkListTail(&list, 1);
    insertLinkListTail(&list, 3);
    insertLinkListTail(&list, 3);
    insertLinkListTail(&list, 4);
    insertLinkListTail(&list, 5);
    insertLinkListTail(&list, 5);
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

    printLinkListValue(&list);

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
    
    
    int *findNum = findLinkListElement(&list, 1);

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
    /* bug */
    removeLinkListElement(&list,5);
    //removeLinkListIndex(&list,0);
     printLinkListValue(&list);
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