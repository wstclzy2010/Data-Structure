#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define bool char
#define true 1
#define false 0
#define InitSize 100
#define MaxSize 50
/*
    线性表元素的位序从1开始，数组的下标从0开始
*/

//静态分配
typedef struct SqList
{
    int data[MaxSize];
    int length;
} SqList;

//动态分配一维数组
typedef struct SeqList
{
    int *data; //动态分配数组的指针
    int maxSize, length;
} SeqList;

_Bool InitList(SeqList *L) //_Bool 是C99中的关键字
{
    L->data = (int *)malloc(sizeof(int) * InitSize);
    if (!L->data)
        return false;
    L->length = 0;
    L->maxSize = InitSize;
    return true;
}

//插入一个元素
_Bool ListInsert(SeqList *L, int i, int e)
{
    if (i < 1 || i > L->length + 1)
        return false;
    if (i >= L->maxSize)
        return false;
    for (int j = L->length; j >= i; j--)//从最后一个元素开始往前依次将元素后置
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length++;
    return true;
}

_Bool ListDelete(SeqList *L, int i, int *e)
{
    if (i < 1 || i > L->length)
        return false;
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)//从
        L->data[j - 1] = L->data[j];
    L->length--;
    return true;
}

int LocateElem(SeqList L, int e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1; //位序从1开始
    return 0;
}

int main(int argc, char const *argv[])
{
    SeqList L;
    if (InitList(&L))
    {
        if (ListInsert(&L, 1, 3))
            printf("插入元素成功\n");
        else
            printf("插入失败\n");
        if (ListInsert(&L, 2, 6))
            printf("插入元素成功\n");
        else
            printf("插入失败\n");
    }
    else
        printf("初始化失败\n");
    int a;
    ListDelete(&L, 2, &a);
    printf("%d\n", LocateElem(L, 6));

    return 0;
}
