#include "dynamicArray.h"

#define true 1
#define false 0
#define CAPTICAL 10
#define ARRAY_SIZE 10

int initArray(DynamicArray *array)
{
    // if(array->DMArray == NULL || array == NULL)
    // {
    //     printf("Init error!!\n");
    //     return false;
    // }
    int ret = true;
    
    array->DMArray = (ElemenType *)malloc(sizeof(ElemenType) * CAPTICAL);
    if(array->DMArray == NULL)
    {
        printf("InitArray malloc error!\n");
        return false;
    }
    /* 申请完空间要进行初始化 */
    memset(array->DMArray,0,sizeof(ElemenType) * CAPTICAL);

    array->len = 0;
    array->size = ARRAY_SIZE;

    /* TODO... */

    return ret;
}

static int reallocArray(DynamicArray *array)
{
    /* todo... */
    if(array == NULL || array->DMArray == NULL)
    {
        printf("DynamicArray ReallocArray error!\n");
        return false;
    }

    /* 备份数据 */
    ElemenType *NewArray = array->DMArray; 
    /* 申请俩倍的空间 */

#if 0
    array->DMArray = (ElemenType *)malloc(array->size);
#else
    array->DMArray = (ElemenType *)malloc(sizeof(ElemenType) * array->size * 2);

    if(array->DMArray == NULL)
    {
        printf("ReallocArray error!\n");
        return false;
    } 

    /* 将原先拷贝的数组的值赋给我们新申请的数组里面的值 */
    for(int idx = 0; idx < array->len; idx++)
    {
        array->DMArray[idx] = NewArray[idx];
    }

    array->size = array->size << 1;
    free(NewArray);
    return true;

#endif
}

static int shrinKage(DynamicArray *array)
{
    if(array == NULL || array->DMArray == NULL)
    {
        printf("DynamicArray ReallocArray error!\n");
        return false;
    }

    ElemenType * newArray = array->DMArray;

    array->DMArray = (ElemenType *)malloc(sizeof(ElemenType) * array->size / 2);
    if(array->DMArray == NULL)
    {
        printf("Shrinkage malloc error!\n");
        return false;
    }

    for(int idx = 0; idx < array->len; idx++)
    {
        array->DMArray[idx] = newArray[idx];
    }
    

    array->size = array->size / 2;
    // printf("arr : %d\n",array->size);
    free(newArray);

    return true;
}



void freeArray(DynamicArray *array)
{
    if(array->DMArray != NULL)
    {
        free(array->DMArray);
        array->DMArray = NULL;
    }
}

int insertArray(DynamicArray *array, ElemenType element)
{
    /* 如果长度和大小相等说明没有位置了此时开始扩容  */
    if(array->len == array->size)
    {
        if(reallocArray(array) == false)
        {
            printf("Realloc Insert error!\n");
            return false;
        }
    }
    /* 如果扩容成功直接插到后面 */
    array->DMArray[array->len] = element;
    array->len++;
    return true;
    
}

int deleteArray(DynamicArray *array, int index)
{
    if(array == NULL || array->DMArray == NULL || index < 0 || index > array->len )
    {
        printf("invid palace  error!\n");
        return false;
    }

    /* 将index位置上的元素删掉 */
    for(int idx = index; idx < array->len - 1; idx++)
    {
        array->DMArray[idx] = array->DMArray[idx + 1];
    }

    array->len--;

    if(array->size > array->len << 1)
    {
        if(shrinKage(array) == false)
        {
            printf("缩容error!\n");
            return false;
        }
    }

    return true;
}
