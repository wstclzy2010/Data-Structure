#include <stdio.h>
#define true 1
#define false 0
#define MaxSize 50
typedef struct
{
	int data[MaxSize];
	int top;
} SqStack;

void InitStack(SqStack *S)
{
	S->top = -1;
}

_Bool isStackEmpty(SqStack S)
{
	if (S.top == -1)
		return true;

	return false;
}

_Bool Push(SqStack *S, int e)
{
	if (S->top == MaxSize - 1)
		return false;
	S->data[++S->top] = e;
	return true;
}

_Bool Pop(SqStack *S, int *e)
{
	if (S->top == -1)
		return false;
	*e = S->data[S->top--];
	return true;
}

_Bool GetTop(SqStack S, int *e)
{
	if (S.top == -1)
		return false;
	*e = S.data[S.top];
	return true;
}

int main(int argc, char *argv[])
{
	SqStack S;
	int e;
	InitStack(&S);
	Push(&S, 1);
	Push(&S, 2);
	Push(&S, 3);
	Pop(&S, &e);

	GetTop(S, &e);
	printf("%d\n", e);
}