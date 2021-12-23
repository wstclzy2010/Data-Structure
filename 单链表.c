#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
#define InitSize 50

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//尾插法建立单链表
void List_TailInsert(LinkList *L)
{
    int x;
    *L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = *L; //r指针指向表尾
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
}
//头插法建立单链表
void List_HeadInsert(LinkList *L)
{
    int x;
    LNode *s;
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = (*L)->next;
        (*L)->next = s;
        scanf("%d", &x);
    }
}

//按位查找
LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;     //L->next指向第一个数据结点，因为这是带头结点的单链表
    if (i == 0)             //第0个结点即头结点
        return L;
    if (i < 1)
        return NULL;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}
//在第i个位置上插入元素
_Bool ListInsert(LinkList *L, int i, int e)
{
    LNode *p = GetElem(*L, i - 1);
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
//删除第i个元素
_Bool ListDelete(LinkList *L, int i, int *e)
{
    LNode *p, *q;
    p = GetElem(*L, i - 1);
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return true;
}
//求表长
int ListLength(LinkList L)
{
    int length = 0;
    LNode *p = L->next;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

int main(int argc, char const *argv[])
{
    LinkList L;
    LNode *node;
    List_HeadInsert(&L);
    int a;
    if (ListInsert(&L, 4, 666))
        printf("插入元素成功\n");
    printf("表长%d\n", ListLength(L));
    if (ListDelete(&L, 4, &a))
        printf("删除元素成功\n");
    node = GetElem(L, 4);
    printf("原本第四个元素值为：%d,现在第四个元素值为%d\n", a, node->data);
    printf("表长%d\n", ListLength(L));
    return 0;
}
