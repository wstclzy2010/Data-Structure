#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 255
typedef struct
{
    char *ch;
    int length;
} SString;
//Brute Force，BF算法，即暴力模式匹配
int index(SString S, SString T)        
{
    int i = 1, j = 1;//串的下标从1开始
    while (i <= S.length && j <= T.length)//每次都将T与S中和T长度相同的一段字符串比较，比较失败i和j都回退
    {
        if (S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;      //i回退到原先开始比较的后一个位置，开始新一轮的匹配
            j = 1;              //j从头开始
        }
    }
    if (j > T.length)           //j指针超出了模式串的长度，表示完整地匹配了一遍模式串，即匹配成功
        return i - T.length;    //返回成功匹配的位置
    
    return 0;
}

int BF(char *x, int m, char *y, int n) 
{ 
    char *yb; 
    /* 匹配*/ 
    for (yb = y; *y != '\0'; ++y) 
        if (memcmp(x, y, m) == 0)
            return y - yb;
    return 0;
} 

int main(int argc, char const *argv[])
{
    SString S,T;
    S.ch="nimabibidan";S.length=11;
    T.ch="bibi";T.length=4;
    printf("%d\n",index(S,T));
    printf("%c\n",S.ch[2]);
    printf("%d\n",BF("nimabibidan",11,"ma",4));
    return 0;
}
