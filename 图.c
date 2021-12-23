#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct
{
    int data[MaxSize];
    int front, rear;
} SqQueue;

//领接矩阵
#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct
{
    VertexType vex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
    int vernum, arcnum;
} MGraph;

//邻接表
typedef struct ArcNode//边表结点
{
    int adjvex;//该弧所指向的顶点下标
    struct ArcNode *nextarc;//指向下一条弧的指针
} ArcNode;
typedef struct VNode//顶点表
{
    VertexType data;
    ArcNode *firstarc;//第一个依附该顶点的弧的指针
} VNode, AdjList[MaxVertexNum];
typedef struct
{
    AdjList vertices;//领接表
    int vernum, arcnum;
} ALGraph;

//领接表转换成领接矩阵
void Convert(ALGraph *G, int arcs[M][N])
{
    for (int i = 0; i < n; i++)
    {
        p = (G->vertices[i]).first;
        while (p != NULL)
        {
            arcs[i][p->data] = 1;
            p = p->next;
        }
    }
}

ArcNode *p;                         //创建一个全局变量，以便于进行查找
int FirstNeighbor(ALGraph G, int u) //表示u的第一个邻接点。FirstNeighbor(G,x)，找不到返回-1
{
    p = G.vertices[u].firstarc; //全局变量的赋值
    if (p == NULL)              //如果头结点的下一个结点为空，返回负数，否则返回p结点的值
        return -1;
    else
        return p->adjvex;
}
int NextNeighbor(ALGraph G) //下一个邻接点，NextNeighbor(G,x,y)，y如果是x的最后一个邻接点，返回-1
{
    p = p->nextarc; //由于p为全局变量，这里直接指向下一个便是
    if (p == NULL)  //如果头结点的下一个结点为空，返回负数，否则返回p结点的值
        return -1;
    else
        return p->adjvex;
}
//广度优先搜索（层次遍历）。时间复杂度：领接表O(|V|+|E|),领接矩阵0(|V|^2);空间复杂度最坏O(|V|)
_Bool visited[MaxVertexNum];
void BFS(ALGraph G, int v) //BFS，从顶点v出发遍历与之连通的顶点
{
    visit(v);
    visited[v] = true;
    EnQueue(&Q, v);
    while (!isEmpty(Q))
    {
        DeQueue(&Q,&v);               //两个基本操作找不到会返回-1，所以大于等于0时继续循环
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) 
        {
            if (!visited[w])
            {
                visit(w);
                visited[w] = true;
                EnQueue(&Q, w);
            }
        }
    }
}
//广度优先遍历，确保非连通也能遍历全部顶点
void BFSTraverse(ALGraph G) 
{
    for (int i = 0; i < G.vernum; i++)
        visited[i] = false;
    SqQueue Q;
    InitQueue(&Q);
    for (int i = 0; i < G.vernum; i++)
        if (!visited[i])
            BFS(G, i);
}

//深度优先搜索(先序遍历、递归)。时间复杂度同广度优先搜索，空间复杂度就是O(|V|)
void DFS(ALGraph G, int v)
{
    visit(v);
    visited[v] = true;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
    {
        if (!visited[w])
            DFS(G, w);
    }
}
void DFSTraverse(ALGraph G)
{
    for (int v = 0; v < G.vernum; v++)
        visited[v] = false;
    for (int v = 0; v < G.vernum; v++)
        if (!visited[v])
            DFS(G, v);
}

//DFS非递归算法---------------->类似于树的中序遍历
void DFS_NonRC(ALGraph G, int v) //非递归DFS算法核心部分
{
    InitStack(&S);      //初始化一个栈，借助栈实现
    Push(&S, v);        //将首个顶点压入栈底
    while (!IsEmpty(S)) //栈不空，则一直循环
    {
        Pop(&S, v);                                                      //将栈顶弹出
        visit(v);                                                        //visit()函数用来表示访问顶点
        visited[v] = true;                                               //标记顶点已经访问
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) //
            if (!visited[w])                                             //如果该顶点未被访问
                Push(&S, w);                                             //将该顶点压入栈
    }
}
void DFSTraverse(ALGraph G)
{
    for (int i = 0; i < G.vernum; i++) //将每个顶点标记未访问
        visited[i] = false;
    for (int i = 0; i < G.vernum; i++) //防止出现不相连的图出现
        if (visited[i] == false)
            DFS(G, i);
}

//拓扑排序——针对有向无环图/AOV网，借助栈
_Bool TopologicalSort(ALGraph G)
{
    InitStack(&S);
    struct ArcNode *e;
    int v, count = 0;
    for (int i = 0; i < G.vernum; i++)
        if (indegree[i] == 0)
            Push(&S, i);
    while (!isEmpty(S))
    {
        Pop(&S, i);
        print[count++] = i;
        for (e = G.vertices[i]; e; e = e->nextarc)
        {
            v = e->adjvex;
            if (!(--indegree[v]))
                Push(&S, v);
        }
    }
    if (count < G.vernum)
        return false;
    else
        return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
