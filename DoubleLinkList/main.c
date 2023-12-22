#include"doubleLinkList.h"
#include <stdio.h>
#include <stdlib.h>




int main()
{
    DoubleLinkList * pList;

    DoubleLinkListInit(&pList);

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int len = sizeof(array) / sizeof(array[0]);

    int pos = 0;
    for (int idx = 1; idx < len; idx++) 
    {
        DoubleLinkListAppointPosInsert(pList, &pos, (void*)&array[idx]);
    }



}