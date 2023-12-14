#include <stdio.h>
#include "hash_table.h"
#include <time.h>
#include <stdlib.h> 

#define VLAUE_NUM   10
#define RANDOM_NUM  666

int main(int argc, char const *argv[])
{
    
    /* 这种方法如果在main函数申请空间 将这块地址传进去  地址会被改变 原先的那块地址找不到了 */
#if 0
    HashTable *hashtable = (HashTable*)malloc(sizeof(HashTable) * 1);
    /* todo... */
#else
    /* 这种方法可以正常解决释放问题 不会漏内存  */
    HashTable *hashtable = NULL;
    hashTableInit(&hashtable);

    

    // for (int idx = 0; idx < VLAUE_NUM; idx++)
    // {
    //     //int value = rand() % 1000;
    //     hashTableInsert(&hashtable, idx, RANDOM_NUM );
    // }
    // Printf (&hashtable);

    hashTableInsert(hashtable,1,100);
    hashTableInsert(hashtable,11,101);
    hashTableInsert(hashtable,21,105);
    
    printf("value1 : %d \n",FindElement(hashtable,1));
    printf("value2 : %d \n",FindElement(hashtable,11));
    printf("value3 : %d \n",FindElement(hashtable,21));

    DestroyHash(hashtable);

#endif  

    return 0;
}

