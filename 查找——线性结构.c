#include <stdio.h>
#include <stdlib.h>
/*
    查找 这一章主要讨论的是各个查找算法的效率指标——平均查找长度ASL
    ASL是所有关键字的比较次数的平均值，ASL=∑查找各个元素的概率×关键字比较次数
*/


//顺序查找，设置哨兵，从后向前一个个与key比较。顺序表和链表都可以
//查找成功的ASL为(n+1)/2，失败ASL为n+1
typedef struct
{
    int *elem; //0号单元留空
    int tableLen;
} SSTable;
int SeqSearch(SSTable ST, int key)
{
    ST.elem[0] = key;                                 //哨兵，可以避免很多不必要的判断
    for (int i = ST.tableLen; ST.elem[i] != key; i--) //从后往前查找
        return i;                                     //i=0表示查找失败
}

/*
    折半/二分查找。要求线性表能随机存取，只是用有序的顺序表
    设置low和high指针，不断地将key与两指针之间的顺序表的中间元素比较，改变low和high位置来缩小查找的范围。
    折半查找判定树即二叉排序树，查找时间复杂度与树高相同，为O(log2n)。
    成功ASL = (n+1)/n * log2(n+1)-1 ≈ log2(n+1)-1。
*/
int binSearch(SSTable ST, int key)
{
    int low = 0, high = ST.tableLen - 1, mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (ST.elem[mid] == key)
            return mid;
        else if (key < ST.elem[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

//折半查找递归实现
int recBinSearch(SSTable ST, int key, int low, int high)
{
    if (low > high)
        return 0;
    mid = (low + high) / 2;
    if (key > ST.elem[mid])
        recBinSearch(ST, key, mid + 1, high);
    else if (key < ST.elem[mid])
        recBinSearch(ST, key, low, mid - 1);
    else
        return mid;
}

int main(int argc, char const *argv[])
{
    printf("%d\n",75%7);
    return 0;
}
