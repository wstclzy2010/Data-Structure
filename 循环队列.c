#include <stdio.h>
/*
	循环队列的入队和出队都是指针前进而不是后退
	此循环队列是用牺牲一个存储单元来区分队空和队满
*/
#define MaxSize 50
typedef struct
{
	int data[MaxSize];
	int front, rear;
} SqQueue;

void InitQueue(SqQueue *Q)
{
	Q->rear = Q->front = 0;
}

_Bool isEmpty(SqQueue Q) 
{
	if (Q.front == Q.rear)			//队头指针和队尾指针指向同一个位置视为队空
		return 1;
	
	return 0;
}

_Bool EnQueue(SqQueue *Q, int x)
{
	if ((Q->rear + 1) % MaxSize == Q->front)//队尾的后一个位置若是队头，视为队满
		return 0;
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize; //元素入队后，队尾指针指向的是队尾元素的后面的那个空着的位置
	return 1;
}

_Bool DeQueue(SqQueue *Q, int *x)
{
	if (Q->front == Q->rear)
		return 0;
	*x = Q->data[Q->front];				 //队头指针则就是指向队头元素
	Q->front = (Q->front + 1) % MaxSize; //出队其实就是队头指针后移一个位置，只是逻辑删除
	return 1;
}
//队列中的元素个数
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MaxSize) % MaxSize;
}

int main(int argc, char *argv[])
{
	SqQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);
	EnQueue(&Q, 4);
	int a;
	if (DeQueue(&Q, &a))
	{
		printf("当前队列长度是：%d\n", QueueLength(Q));
		printf("出队元素值是：%d\n", a);
	}
	return 0;
}