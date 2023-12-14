#include "hash_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



int hashTableInit(HashTable **pHashtable)
{
    int ret = 0;
    
    HashTable * p_pHashtable = (HashTable *)malloc(sizeof(HashTable) * 1);
    if (!p_pHashtable)
    {
        return -1;
    }
    memset(p_pHashtable, 0, sizeof(HashTable*) * 1);
    
    p_pHashtable->slotKeyId = malloc(sizeof(hashNode) * SLOT_CAPACITY);

    if (!(p_pHashtable->slotKeyId))
    {
        return -1;
    }
    memset(p_pHashtable->slotKeyId, 0, sizeof(hashNode) * SLOT_CAPACITY);

    *pHashtable = p_pHashtable;

    return ret;


}

/* 使用循环的方式获取slotId. */
static int calHashValue(int key)
{
    int slotId = key % SLOT_CAPACITY;
    return slotId;
}

int hashTableInsert(HashTable *pHashtable, int key, int value)
{
    if (!pHashtable)
    {
        return -1;
    }

    int slotId = calHashValue(key);
#if 0
    pHashtable->slotId->key = key;
    pHashtable->slotId->value = value;
#else
   
    // pHashtable->slotKeyId[slotId].real_key = key;
    // pHashtable->slotKeyId[slotId].value = value;
    

    hashNode *hash_new_Node = (hashNode *)malloc(sizeof(hashNode));
    memset(hash_new_Node, 0, sizeof( hashNode ));
    hash_new_Node->real_key = key;
    hash_new_Node->value = value;
    hash_new_Node->next = NULL;

    /* 查找原先Node 里面的value是否有值一个key对应一个value如果为NULL说明Value没有 值*/

    if (pHashtable->slotKeyId[slotId].next == NULL)
    {
        pHashtable->slotKeyId[slotId].next = hash_new_Node;
    }
    else
    {
        /* 判断链表中是否存在key 一样的节点，如果存在，则不需要插入，直接返回  */
        hashNode *Temp = (hashNode *)(pHashtable->slotKeyId[slotId].next);
        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = hash_new_Node;
    }

#endif
    return 0;
}

void DestroyHash(HashTable *pHashtable)
{

    for(int idx = 0; idx < SLOT_CAPACITY; idx++)
    {
        hashNode *TraveHash = pHashtable->slotKeyId[idx].next;
        while(TraveHash != NULL)
        {
            hashNode *FreeTemp = TraveHash;
            TraveHash = TraveHash->next;
            free(FreeTemp);
        }
    }
    free(pHashtable->slotKeyId);
    free(pHashtable);
}

// int getAppointKeyValue(HashTable *pHashtable, int key)
// {
//     return pHashtable->slotKeyId[calHashValue(key)].value;
// }

int FindElement(HashTable *pHashtable, int key)
{
    int slotId = calHashValue(key);

#if 1
    hashNode * travel = pHashtable->slotKeyId[slotId].next;
    while (travel)
    {
        if (travel->real_key == key)
        {
            return travel->value;
        }
        travel = travel->next;
    }
#else
    if(pHashtable->slotKeyId[slotId].real_key == key)
    {
        return pHashtable->slotKeyId[slotId].value;
    }
    else
    {
        hashNode *p = pHashtable->slotKeyId[slotId].next;
        while (p->next != NULL)
        {
            if (p->real_key == key)
            {
                return p->value;
            }
            p = p->next;
        }
        if(p->real_key == key)
        {
            return p->value;
        }
    #endif
    return -1;
    
}
