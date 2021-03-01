#include <iostream>

class Solution
{
private:
    bool visited[MAX_VERTEX_NUM]; //访问标记数组
public:
    void DFSTraverse(Graph G)
    {
        for (v = 0; v < G.vexnum; v++)
            visited[v] = false;        //初始化方位标记为未访问
        for (v = 0; v < G.vexnum; v++) //从v=0开始遍历
            if (!visited[v])
                DFS(G, v); //每次循环调用DFS可以遍历一个连通分量
    }
    void DFS(Graph G, int v)
    {
        visit(v);
        visited[v] = true;
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) //遍历所有的邻居
            if (!visited[w])
                DFS(G, w); //递归遍历邻居的邻居的邻居......
    }
}