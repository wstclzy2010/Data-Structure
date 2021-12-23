#include <stdio.h>
#include <stdbool.h>
/*
    冒泡和快排属于交换排序，在每一趟排序后，都会有一个元素被交换到了最终位置
        ①冒泡是从后到前或者从前到后把把最小或者最大的元素依次和相邻元素比较，交换两者位置
            时间复杂度最好可以达到O(n)。排序趟数与序列初始状态有关
        ②快排的核心在于“划分”，每一趟划分会把一个枢轴元素放到最终位置，
            而比枢轴小的被交换到了左边，比枢轴大的被交换到了右边。
            快排是递归实现的，凡是递归算法都可以用利用栈来实现非递归方式；
            在基本有序或基本逆序时，达到最坏时间复杂度O(n^2)，达到最坏空间复杂度O(n)
            时间复杂度和空间复杂度与递归层数直接相关
                平均时间复杂度O(nlog2(n))，是平均性能最好的内部排序
*/

//交换两个数组元素
void swap(int *a, int *b)
{
    int tmp = *a; //不能交换数组的地址，因为静态数组的地址不能改变
    *a = *b;
    *b = tmp;
}

//冒泡排序，时间复杂度O(N^2)，空间复杂度O(1)，稳定，每趟确定一个元素的最终位置
void bubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        _Bool isSwap = false;
        for (int j = n - 1; j > i; j--) //一趟冒泡，从后往前冒，从小到大排序
            if (A[j] < A[j - 1])
            {
                swap(A + j, A + j - 1); //A即数组首地址，(A+j)即A[j]元素的地址
                isSwap = true;
            }
        if (!isSwap) //一次遍历没有交换元素，即已经有序
            return;
    }
}

//快速排序一趟划分，就是左移移，右移移的过程，每趟确定一个枢轴元素的最终位置
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low; //返回存放枢轴元素的最终位置
}
/*  快速排序，平均性能最好的内部排序。
    平均时间复杂度O(nlog2(n))，即O(n*递归层数)；空间复杂度O(log2(n)),即O(递归层数)。不稳定*/
void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotPos = partition(A, low, high);//low的左边都<枢轴，high的右边都>=枢轴
        quickSort(A, low, pivotPos - 1);  //对左子表递归快排
        quickSort(A, pivotPos + 1, high); //对右子表递归快排
    }
}

int main(int argc, char const *argv[])
{
    int a[2] = {1, 2};
    swap(a + 1, a + 0);
    printf("%d %d\n", a[0], a[1]);
    return 0;
}
