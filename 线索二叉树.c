#include <stdio.h>

typedef struct ThreadNode
{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

ThreadNode *pre = NULL;
//访问结点
void visit(ThreadNode *node)
{
    if (node->lchild == NULL)
    {
        node->lchild = pre;
        node->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = node;
        pre->rtag = 1;
    }
    pre = node;
}

//先序遍历二叉树线索化
void PreThread(ThreadTree T)
{
    if(T)
    {
        visit(T);                   //因为先序是根-左-右，处理完一个节点后可能它的左孩子指针已经指向前驱
        if (T->ltag == 0)           //先序在递归遍历左子树之前必须判断结点左孩子是否已经线索化
            PreThread(T->lchild);   //防止出现循环转圈线索化的问题
        PreThread(T->rchild);
    }
}
//先序遍历建立线索二叉树
void GreatePreThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        PreThread(T);
        if(pre->rchild = NULL)
            pre->rtag = 1;
    }
}

//中序遍历二叉树线索化
void InThread(ThreadTree T)
{
    if (T)
    {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}
//中序遍历建立线索二叉树
void GreateInThread(ThreadTree T)
{
    pre = NULL;
    if (T)
    {
        InThread(T);
        if(pre->rchild = NULL)
            pre->rtag = 1;
    }
}

//后序遍历二叉树线索化
void PostThread(ThreadTree T)
{
    if (T != NULL)
    {
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit(T);
    }
}
//后序遍历建立线索二叉树
void GreatePostThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        PostThread(T);
        if(pre->rchild = NULL)
            pre->rtag = 1;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
