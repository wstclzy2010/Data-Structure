#include <stdio.h>
#define MaxSize 50
typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode;
typedef struct
{
    QNode *front, *rear;
} LinkQueue;
typedef struct
{
    int data[MaxSize];
    int top;
} SqStack;
SqStack S;
//二叉树的链式存储
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void visit(BiTree T)
{
}

//先序遍历
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//非递归先序遍历
void PreOrderStack(BiTree T)
{
    InitStack(&S);
    BiTree p = T;
    while (p || !isStackEmpty(S))
    {
        if (p)
        {
            visit(p);
            Push(&S, p);
            p = p->lchild;
        }
        else
        {
            Pop(&S, &p);
            p = p->rchild;
        }
    }
}

//中序递归遍历
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
//非递归中序遍历
void InOrderStack(BiTree T)
{
    InitStack(&S);
    BiTree p = T;
    while (p || !isStackEmpty(S))
    {
        if (p)
        {
            Push(&S, p);
            p = p->lchild;
        }
        else
        {
            Pop(&S, &p);
            visit(p);
            p = p->rchild;
        }
    }
}

//后序遍历
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        postOrder(T->rchild);
        visit(T);
    }
}
//非递归后序遍历
void PostOrderStack(BiTree T)
{
    /*  
    1:取出的栈顶元素是否有右子节点,或者右子节点是否被访问过,若满足条件(
    2:
    重复一开始是否又左子节点的判断。 */

    InitStack(&S);
    BiTree p = T, recent = NULL;
    while (p || !isStackEmpty(S))
    {
        if (p)
        {
            Push(&S, p); //从根结点开始,只要左子节点非空,则进栈,直到左子节点为空为止
            p = p->lchild;
        }
        else
        {
            GetTop(S, &p); //取出栈顶元素(只是取,并非弹栈),判断
            if (p->rchild && p->rchild != recent)
                p = p->rchild; //取出的栈顶元素，若有右子节点，且未被访问过，则指针继续移动到右子节点
            else
            {
                Pop(&S, &p); //无右子节点,或者右子节点被访问过,弹出该结点
                visit(p);    //然后输出该结点
                recent = p;  //并且记录下这个最近访问的节点
                p = NULL;    //重置p结点
            }
        }
    }
}

//层次遍历
void LevelOrder(BiTree T)
{
    SqQueue Q;
    InitQueue(&Q);
    BiTree p;
    EnQueue(&Q, p);
    while (!isStackEmpty(Q))
    {
        DeQueue(&Q, &p);
        visit(p);
        if (p->lchild)
            EnQueue(&Q, p->lchild);
        if (p->rchild)
            EnQueue(&Q, p->rchild);
    }
}

//递归求二叉树高度
int BTHeight1(BiTree T)
{
    if (T)
    {
        int lheight = BTHeight(T->lchild);
        int rheight = BTHeight(T->rchild);
        return lheight > rheight ? lheight + 1 : rheight + 1;
    }
    return 0;
}
//层次遍历求二叉树高度
int BTHeight2(BiTree T)
{
    if (T)
    {
        int front = -1, rear = -1, level = 0, last = 0;
        BiTree Que[MaxSize];
        Que[++rear] = T;
        while (front < rear)
        {
            T = Que[++front];
            if (T->lchild)
                Que[++rear] = T->lchild;
            if (T->rchild)
                Que[++rear] = T->rchild;
            if (front == last)
            {
                last = rear;
                level++;
            }
        }
        return level;
    }
    return 0;
}

//利用先序遍历思想，递归求二叉树带权路径长度(WPL)，
int WPLpreOrder(BiTree T, int deep)
{
    static int wpl = 0;               //静态变量，0只赋值一次
    if (!T->lchild && !T->rchild)     //当左右孩子都为空，则当前结点为叶结点，
        wpl = wpl + T->weight * deep; //wpl等于每个叶结点的权值与深度(边数)的乘机之和
    if (T->lchild)
        WPLpreOrder(T->lchild, deep + 1); //有左孩子，则递归遍历左子树
    if (T->rchild)
        WPLpreOrder(T->rchild, deep + 1); //有右孩子，则递归遍历右子树
    return wpl;
}
//求wpl，初始从根结点开始，深度为0
int WPL(BiTree root)
{
    return WPLpreOrder(root, 0);
}

//交换所有左右子树
_Bool swapBitTree(BiTree T)
{
    BiTree temp;
    if (!T)
        return 0;
    swapBitTree(T->lchild);
    swapBitTree(T->rchild);
    temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
}



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
