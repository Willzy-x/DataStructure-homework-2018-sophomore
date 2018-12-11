//
//  MGraph.cpp
//  MGraph
//
//  Created by Yucheng on 2018/11/20.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include "MGraph.h"
#include "SeqQueue.cpp"

#define INFINITY 0x7fffffff

using namespace std;
/* Private functions */
//
template <class T>
void MGraph<T>::DFS(int v, bool *visited)
{
    cout << vexs[v] << " ";
    visited[v] = true;
    for (int i = 0; i < vexnum; i++)
        if (edges[v][i] == 1 && visited[i]) {
            DFS(i, visited);
        }
}
//
template <class T>
int MGraph<T>::MiniNum(Edge miniedges[])
{
    int i = 0;
    while (miniedges[i].lowcost == 0)
        i++;
    for (int j = i; j < vexnum; j++) {
        if (miniedges[j].lowcost != 0)
            if (miniedges[j].lowcost < miniedges[i].lowcost)
                i = j;
    }
    return i;
}
template <class T>
void MGraph<T>::GetGraph(vector<EdgeType> &graph)
{
    graph.resize(edgenum);
    int k = 0, i = 0;
    for (i = 0; i < vexnum; i++)
    {
        for (int j = i+1; j < vexnum; j++)
        {
            if (edges[i][j] < INT_MAX && i != j) {
                graph[k].head = i;
                graph[k].tail = j;
                graph[k].cost = edges[i][j];
                k++;
            }
        }
    }
    EdgeType e(0, 0, 0);
    for (i = 1; i < edgenum; i++)
    {
        for (int j = 0; j < edgenum-i; j++)
        {
            if (graph[j].cost > graph[j+1].cost)
            {
                e = graph[j];
                graph[j] = graph[j+1];
                graph[j+1] = e;
                e = graph[j];
            }
        }
    }
}
/* Public functions */
// 构造函数-----------------------------
template <class T>
MGraph<T>::MGraph(T v[], int n, int e, GraphType k, istream& in)
{
    vexnum = n;
    edgenum = e;
    kind = k;
    vexs.resize(vexnum);
    edges.resize(vexnum);
    for (int i = 0; i < n; i++)
        vexs[i] = v[i];
    for (int i= 0; i < n; i++)
        edges[i].resize(vexnum);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        if (i == j)
            edges[i][j] = 0;  // 网图邻接矩阵对角线元素为0
        else edges[i][j] = INFINITY;
    }
    for (int i = 0; i < e; i++)
    {
        int va, vb, w;
        in >> va >> vb;
        in >> w;
        edges[va][vb] = w;
        if (kind == undinetwork || kind == undigraph)
            edges[vb][va] = w; // 无向网图
    }
}
// 析构函数
template <class T>
MGraph<T>::~MGraph()
{
    vexs.clear();
    edges.clear();
}
//
template <class T>
int MGraph<T>::VertexNum()
{
    return vexnum;
}
//
template <class T>
int MGraph<T>::EdgeNum()
{
    return edgenum;
}
// 返回给定下标的顶点
template <class T>
T MGraph<T>::GetVexValue(int i)
{
    return vexs[i];
}
// 返回顶点的下标
template <class T>
int MGraph<T>::GetVexValueNum(T v)
{
    for (int i=0; i < vexnum; i++)
    {
        if (vexs[i] == v)
            return i;
    }
    return -1;
}
// 返回边权重
template <class T>
int MGraph<T>::GetEdgeValue(int i, int j)
{
    return edges[i][j];
}
// 插入顶点
template <class T>
void MGraph<T>::InsertVex(T v)
{
    vexs.push_back(v);
    vexnum++;
    edges.resize(vexnum);
    for (int i=0; i < vexnum; i++)
    {
        edges[i].resize(vexnum, INT_MAX); // initialize new edges
    }
}
// 删除顶点
template <class T>
void MGraph<T>::RemoveVex(T v)
{
    bool found = false;
    for (int i=0; i < vexnum; i++)
        if (vexs[i] == v)
        {
            vexs.erase(vexs.begin() + i);
            cout << "Found it!" << endl;
        }
    for (int i=0; i < vexnum; i++)
    {
        for (int j; j < vexnum; j++)
        {
            if (j == GetVexValueNum(v))
            {
                edges[i].erase(edges[i].begin() + j);
                continue;
            }
        }
        if (i == GetVexValueNum(v) && !found)
        {
            edges.erase(edges.begin() + i); // 考虑到vector在erase之后已经改变
            found = true;
            i--;
            continue;
        }
    }
}
//
template <class T>
void MGraph<T>::InsertEdge(EdgeType e)
{
    int i = e.head, j = e.tail;
    if (i >= vexnum || j >= vexnum) {
        cerr << "Wrong input.\n";
        exit(1);
    }
    edges[i][j] = e.cost;
    if (kind == undigraph || kind == undinetwork)
        edges[j][i] = e.cost; // 无向网图
}
//
template <class T>
void MGraph<T>::DeleteEdge(EdgeType e)
{
    int i = e.head, j = e.tail;
    if (i >= vexnum || j >= vexnum) {
        cerr << "Wrong input.\n";
        exit(1);
    }
    edges[i][j] = INT_MAX;
    if (kind == undigraph || kind == undinetwork)
        edges[j][i] = INT_MAX;
}
// 深度优先遍历------------------------------
template <class T>
void MGraph<T>::DFSTraverse()
{
    bool * visited = new bool[vexnum];
    for (int v = 0; v < vexnum; v++) {
        visited[v] = false;
    }
    for (int v = 0; v < vexnum; v++)
        if (!visited[v])
            DFS(v, visited);
    delete []visited;
}
// 广度优先遍历------------------------------
template <class T>
void MGraph<T>::BFSTraverse()
{
    SeqQueue<int, 10>  q;
    bool * visited = new bool[vexnum];
    for (int i = 0; i < vexnum; i++)
        visited[i] = false;
    for (int i = 0; i < vexnum; i++)
        if (!visited[i]){
            cout << vexs[i] << " ";
            visited[i] = true;
            q.EnQueue(i);
            while (!q.Empty())
            {
                int u = q.DeQueue();
                for (int j = 0; j < vexnum; j++) {
                    if (edges[u][j] == 1 && !visited[j]) {
                        cout << vexs[j] << " ";
                        visited[j] = true;
                        q.EnQueue(j);
                    }
                }
            }
        }
    delete []visited;
}
//
template <class T>
void MGraph<T>::PrintEdges()
{
    for (int i=0; i < vexnum; i++)
    {
        for (int j=i+1; j < vexnum; j++)
        {
            if (GetEdgeValue(i, j) < INT_MAX) {
                T v1 = GetVexValue(i);
                T v2 = GetVexValue(j);
                cout << v1 << " >---< " << v2 <<  " with cost: " << GetEdgeValue(i, j) << endl;
            }
        }
    }
}
//
template <class T>
void MGraph<T>::PrintVexs()
{
    for (int i=0; i < vexnum; i++)
    {
        cout << i << " ( " << vexs[i] << " ) " << endl;
    }
}
// Prim算法
template <class T>
void MGraph<T>::Prim(int v)
{
    Edge * miniedges = new Edge[vexnum];
    for (int i = 0; i < vexnum; i++) {
        miniedges[i].adjvex = GetVexValue(v);
        miniedges[i].lowcost = GetEdgeValue(v, i);
    }
    miniedges[v].lowcost = 0;
    for (int i = 1; i < vexnum; i++)
    {
        int k = MiniNum(miniedges);
        cout << miniedges[k].adjvex << "-->" << GetVexValue(k) << endl;
        miniedges[k].lowcost = 0;
        for (int j = 0; j < vexnum; j++)
        {
            if (GetEdgeValue(k, j) < miniedges[j].lowcost)
            {
                miniedges[j].adjvex = GetVexValue(k);
                miniedges[j].lowcost = GetEdgeValue(k, j);
            }
        }
    }
    delete []miniedges;
}
// Kruskal算法
template <class T>
void MGraph<T>::Kruskal(vector<EdgeType>& tree)
{
    vector<EdgeType> graph;
    GetGraph(graph);
//    vector<EdgeType> tree;
    tree.resize(vexnum - 1); // constructor for EdgeType
    int * components = new int[vexnum];
    for (int i = 0; i < vexnum; i++)
    {
        components[i] = i;
    }
    int j = 0, k = 0;
    while (k < vexnum - 1)
    {
        int h1 = graph[j].head;
        int t1 = graph[j].tail;
        int h2 = components[h1];
        int t2 = components[t1];
        if (h2 != t2)
        {
            tree[k].head = h1;
            tree[k].tail = t1;
            tree[k].cost = graph[j].cost;
            k++;
            for (int i = 0; i < vexnum; i++) {
                if (components[i] == t2)
                    components[i] = h2;
            }
        }
        j++;
    }
    delete []components;
}
// Dijistra 算法
template <class T>
void MGraph<T>::Dijkstra(int v, vector<int>& path, vector<int>& dist)
{
    bool * s = new bool[vexnum];
    for (int i=0; i<vexnum; i++)
    {
        dist[i] = GetEdgeValue(v, i);    // initialize distance
        if (dist[i] < INT_MAX && i != v) // initialize path
            path[i] = v;
        else
            path[i] = -1;
    }
    dist[v] = 0;
    s[v] = true; // add node v to set s
    for (int i=1; i<vexnum; i++)
    {
        int min = INT_MAX;
        int k = 0;
        for (int j=0; j<vexnum; j++)
            if (!s[j] && dist[j] < min)
            {
                k = j;
                min = dist[j];
            }
        s[k] = true; // add the closest node to v to s
        for (int w=0; w<vexnum; w++){
            if (GetEdgeValue(k, w) == INT_MAX)
                continue;
            if (!s[w] && dist[w] > dist[k] + GetEdgeValue(k, w))
            { // 溢出问题
                dist[w] = dist[k] + GetEdgeValue(k, w);
                path[w] = k;
            }
        }
    }
    delete [] s;
}
// Floyd 算法
template <class T>
void MGraph<T>::Floyd(int (*path)[20], int (*D)[20]) // 20 refers to MAXV in .h file
{
    for (int i=0; i<vexnum; i++)
        for (int j=0; j<vexnum; j++)
        {
            if (i == j)
                D[i][j] = 0;
            else
                D[i][j] = GetEdgeValue(i, j);
            if (D[i][j] < INT_MAX)
                path[i][j] = j;
            else
                path[i][j] = -1;
        }
    for (int k=0; k<vexnum; k++)
        for (int i=0; i<vexnum; i++)
            for (int j=0; j<vexnum; j++){
                if (D[i][k] == INT_MAX || D[k][j] == INT_MAX)
                    continue;
                if (D[i][k] + D[k][j] < D[i][j]) { // 溢出问题
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = path[i][k];
                }
            }
}
// 拓扑排序
template <class T>
void MGraph<T>::Toposort()
{
    vector<int> indegree(vexnum, 0);
    SeqQueue<int, 20> s;
    for (int i=0; i <  vexnum; i++)
        for (int j=0; j < vexnum; j++)
            if (edges[i][j] < INT_MAX && edges[i][j] != 0)
                indegree[j]++;
    for (int i=0; i < vexnum; i++)
        if (indegree[i] == 0)
            s.EnQueue(i);
    int c = 0;
    while (!s.Empty())
    {
        int k = s.DeQueue();
        cout << GetVexValue(k) << "-";
        ++c;
        for (int j = 0; j < vexnum; j++)
        {
            if (edges[k][j] < INT_MAX) {
                indegree[j]--;
                if (indegree[j] == 0)
                    s.EnQueue(j);
            }
        }
    }
    if (c < vexnum)
        cout << "There's a cycle in this AOE network!" << endl;
    indegree.clear();
}
