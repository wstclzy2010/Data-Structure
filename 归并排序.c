#include <stdio.h>
#include <stdbool.h>

/*
    归并排序是递归地将n个记录的待排序表 看成(拆分成) n个有序的子表，不断地两两合并前后相邻
                的两个有序表（只有一个元素时自然算有序）得到n/2(向上取整)个有序表。
    归并树是倒立的二叉树，归并趟数为log2(n)(向上取整)，每趟归并时间复杂度O(n)，所以总时间复杂度永远是O(nlog2(n))；
    归并排序是考研数据结构中唯一的稳定的时间复杂度为O(nlog2(n))的内部排序，而相同时间复杂度的快排和堆排序都不稳定；
    归并排序一趟结束后不能保证一个元素放在最终位置，且排序比较次数的数量级与初始状态无关
*/

int *B = (int *)malloc((n + 1) * sizeof(int));//辅助数组B

//归并“这一项”操作的时间复杂度O(n)，将两个前后相邻的有序序列归并，合为一个有序序列
void merge(int A[], int low, int mid, int high)
{
    int k;
    for (k = low; k <= high; k++)//将A中所有元素复制到B数组
        B[k] = A[k];
    for (int i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {           //i指向B中前序列的第一个元素，j指向B中后序列的第一个元素，k指向A中的第一个元素
        if (B[i] <= B[j])
            A[k] = B[i++];//把两个序列中较小者放到A数组最前面
        else
            A[k] = B[j++];
    }
    while (i <= mid)    //当j已经大于high，则不需要比较，直接将B中左边的剩余元素放到A中
        A[k++] = B[i++];
    while (j <= high)   //当i已经大于mid
        A[k++] = B[j++];
}
//归并排序，递归实现。时间复杂度O(nlog2(n))，空间复杂度O(n)，稳定
void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
