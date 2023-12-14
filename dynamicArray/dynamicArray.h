#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define  ElemenType void*

typedef struct DynamicArray
{
    ElemenType *DMArray;      //指针
    int len;         //当前的长度
    int size;        //总大小

}DynamicArray;

int initArray(DynamicArray *array);
void freeArray(DynamicArray *array);
int insertArray(DynamicArray *array,ElemenType element);
int deleteArray(DynamicArray *array,int index);



#endif
