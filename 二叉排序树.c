#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BSTNode, *BSTree;

//非递归按值查找
BSTNode *BST_Search(BSTree T, int key)
{
    while (T && T->data != key)
    {
        if (key < T->data)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}

//二叉排序树的插入
_Bool BST_Insert(BSTree T, int key)
{
    if (!T)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->data = key;
        T->lchild = T->rchild = NULL;
        return true;
    }
    else if (key == T->data)
        return false;
    else if (key < T->data)
        return BST_Insert(T->lchild, key);
    else
        return BST_Insert(T->rchild, key);
}

//构造
void Creat_BST(BSTree T, int str[], int n)
{
    T = NULL;
    int i = 0;
    while (i < n)//字符串str有n个字符
    {
        BST_Insert(T, str[i]);//依次将每个关键字插入二叉排序树
        i++;
    }
}





int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
