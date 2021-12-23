#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define true 1
#define false 0

typedef struct DNode
{
	int data;
	struct DNode *prior, *next;
} DNode, *DLinkList;

//尾插法建立双链表
void DList_TailInsert(DLinkList *L)
{
	*L = (DNode *)malloc(sizeof(DNode)); //头结点
	(*L)->prior = NULL;
	(*L)->next = NULL;
	DNode *newNode, *tailNode = *L;
	int x;
	scanf("%d", &x);
	while (x != 9999)
	{
		newNode = (DNode *)malloc(sizeof(DNode));
		newNode->data = x;
		tailNode->next = newNode;
		newNode->prior = tailNode;
		tailNode = newNode;
		scanf("%d", &x);
	}
	tailNode->next = NULL;
}

//按位查找
DNode *GetElem(DLinkList L, int i)
{
	int j = 1; //头结点的next是第一个结点，j从1开始
	DNode *p = L->next;
	if (i == 0)
		return L;
	if (i < 1)
		return NULL;
	while (p && j < i) //j等于i时表示查找成功
	{
		p = p->next;
		j++;
	}
	return p;
}

//按值查找
DNode *LocateElem(DLinkList L, int e)
{
	DNode *p = L->next;
	while (p != NULL && p->data != e)
		p = p->next;
	return p;
}
//插入一个元素
_Bool DLinkInsert(DLinkList *L, int i, int e)
{
	DNode *preNode = GetElem(*L, i - 1);
	DNode *newNode = (DNode *)malloc(sizeof(DNode));
	newNode->data = e;
	newNode->next = preNode->next;
	preNode->next->prior = newNode;
	newNode->prior = preNode;
	preNode->next = newNode;
	return true;
}

//删除一个元素
_Bool DLinkDelete(DLinkList *L, int i, int *e)
{
	DNode *preNode = GetElem(*L, i - 1);
	if (!preNode->next)
		return false;
	DNode *delNode = preNode->next;
	*e = delNode->data;
	preNode->next = delNode->next;
	delNode->next->prior = preNode;
	free(delNode);
	return true;
}

//求表长
int ListLength(DLinkList L)
{
	int length = 0;
	DNode *p = L->next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

void Print_DLinklist(DLinkList head)
{
	DNode *p = head;
	DNode *q = NULL;
	p = p->next;
	while (p != NULL)
	{
		printf("%d ", p->data); // 从前往后输出
		q = p;
		p = p->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	DLinkList L;
	DList_TailInsert(&L);
	DNode *node = LocateElem(L, 3);
	//printf("%d",node->data);
	Print_DLinklist(L);
	if (DLinkInsert(&L, 4, 666))
		printf("插入元素成功\n");
	printf("表长%d\n", ListLength(L));
	int a;
	if (DLinkDelete(&L, 4, &a))
		printf("删除元素成功\n");
	node = GetElem(L, 4);
	printf("原本第四个元素值为：%d,现在第四个元素值为%d\n", a, node->data);

	return 0;
}