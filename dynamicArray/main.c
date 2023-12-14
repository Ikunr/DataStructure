#include "dynamicArray.h"

#define ARRAY_NUM 10


int main()
{
    DynamicArray DyArray;
    initArray(&DyArray);

    for(int idex = 0; idex < ARRAY_NUM; idex++)
    {
        insertArray(&DyArray,idex + 1);
    }

    insertArray(&DyArray,111);
    insertArray(&DyArray,111);
    
    deleteArray(&DyArray,0);
    

    for(int idx = 0; idx < DyArray.len; idx++)
    {
        printf("array : %d\n",DyArray.DMArray[idx]);
    }

    printf("arrar size : %d\n",DyArray.size);
    

    freeArray(&DyArray);
    

    return 0;
}