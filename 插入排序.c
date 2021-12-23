#include <stdio.h>
#include <stdlib.h>
/*
    ①插入排序认为当前所指元素的前面的子序列已经有序，将当前所指元素与前面的元素一一比较，将前面关键字大于该元素的
        元素全部后移，然后插入到前面有序序列中并保持有序。即比较大小——元素后移——元素插入的过程
    ②插入排序的时间复杂度都是O(N^2)，空间复杂度都是O(1)，只是折半插入往往有更好的性能、希尔最好能达到O(N^1.3)；
    都是基于比较和移动元素。
    ③直接插入排序的时间复杂度最好可以达到O(n)；基本有序时，插入排序的比较次数最少。
    ④折半插入排序利用折半查找思想，找到待排序元素应该插入的位置，即一边折半查找，一边插入排序。
    ⑤希尔排序利用了顺序存储的随机访问的特性，当采用链式存储的时候会增加时间复杂度
*/

//直接插入排序，时间O(N^2)，空间O(1)，稳定
void insertSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
        if (A[i] < A[i - 1])
        {
            temp = A[i];
            for (j = i - 1; j >= 0 && A[j] > temp; j--) //检查前面已经排好序的元素
                A[j + 1] = A[j];                        //所有大于temp的元素向后挪位
            A[j + 1] = temp;
        }
}

//折半插入排序，时间O(N^2)，空间O(1)，稳定
void binInsertSort(int A[], int n)
{
    int i, j, low, high, mid;
    for (i = 2; i < n; i++)
    {
        A[0] = A[2];        //A[0]是哨兵，A[1]视为有序序列，从A[2]开始排序
        low = 1;
        high = i - 1;
        while (low <= high) //low大于high时意味着已经找到应该插入的位置，即mid-1或者high+1或者low
        {
            mid = (low + high) / 2;
            if (A[0] < A[mid])
                high = mid - 1;
            else
                low = mid + 1; //当A[mid]==A[0]时，也继续在右半部分查找，可以保证稳定性
        }
        for (j = i - 1; j >= low; j--) //从low到i-1都是应该后移的元素，待排序元素要插入low这个位置
            A[j + 1] = A[j];           //元素后移，腾出位置
        A[high + 1] = A[0];
    }
}

//希尔排序(缩小增量排序)，n为某特定范围时时间O(N^1.3)，最坏时间时间O(N^2)，空间O(1)，不稳定
void ShellSort(int A[], int n)
{
    for (int d = n / 2; d >= 1; d /= 2)
        for (int i = d + 1; i <= n; i++) //实际代码并非对一个个子序列完整的完成直接插入排序
            if (A[i] < A[i - d])         //，而是各个子序列交替排序
            {
                A[0] = A[i];
                for (int j = i - d; j > 0 && A[0] < A[j]; j -= d)
                    A[j + d] = A[j];
                A[j + d] = A[0];
            }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
