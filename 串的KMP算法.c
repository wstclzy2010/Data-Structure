#define MAXLEN 255
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;
/*
    相当于以位置i之前的一子串为主串，与当前模式串进行匹配
    不同的是这里返回的j是匹配成功的长度，也就是如果主串匹配到这里失败了，可以直接从模式串[j+1]的值开始与主串[i]对比
*/
void get_next(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

void get_nextval(SString T, int nextval[])
{
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            i++;
            j++;
            if (T.ch[i] != T.ch[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
            j = nextval[j];
    }
}

int indexKMP(SString S, SString T, int next[])
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
