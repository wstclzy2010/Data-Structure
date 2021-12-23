#include <stdio.h>
#include <stdlib.h>
typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode;
typedef struct
{
    QNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QNode *)malloc(sizeof(QNode)); //初始化头结点，头尾指针均指向头结点
    Q->front->next = NULL;
}

_Bool isEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return 1;
    else
        return 0;
}
//入队即尾插法插入新元素
void EnQueue(LinkQueue *Q, int x) //没有必要判断是否队满
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = x;
    newNode->next = NULL;
    Q->rear->next = newNode;
    Q->rear = newNode;
}

_Bool DeQueue(LinkQueue *Q, int *x)
{
    if (Q->rear == Q->front)
        return 0;
    QNode *delNode = Q->front->next; //因为带头结点，第一个元素是头结点之后的那个元素
    *x = delNode->data;
    Q->front->next = delNode->next;
    if (Q->rear == delNode) //原队列只有一个结点，出队后要让队尾指针指向头结点
        Q->rear = Q->front;
    free(delNode);
    return 1;
}

int main(int argc, char const *argv[])
{
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);
    int a;
    if (DeQueue(&Q, &a))
    {
        printf("被删除的元素值为%d\n", a);
    }
    return 0;
}
