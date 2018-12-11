//
//  MGraph.h
//  MGraph
//
//  Created by Yucheng on 2018/11/20.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef MGraph_h
#define MGraph_h
#include <vector>
#define MAXV 20
using namespace std;
enum GraphType{undigraph, digraph, undinetwork, dinetwork};
struct EdgeType
{
    int head, tail;
    int cost;
    EdgeType() {}
    EdgeType(int h, int t, int c)
    {
        head = h; tail = t; cost = c;
    }
};

struct Edge
{
    int adjvex, lowcost;
};

template <class T>
class MGraph
{
private:
    int vexnum, edgenum;
    GraphType kind; // 只考虑网 3 or 4
    vector< vector<int> > edges;
    vector<T> vexs;
    void DFS(int v, bool * visited);
    int MiniNum(Edge miniedges[]);
    void GetGraph(vector<EdgeType> &graph);
    
public:
    MGraph(T v[], int n, int e, GraphType k, istream& in);
    ~MGraph();
    int VertexNum(); // 返回图中顶点数量
    int EdgeNum();  // 返回图中边的数量
    T GetVexValue(int i); // 返回顶点表中第i个顶点的值
    int GetVexValueNum(T v);
    int GetEdgeValue(int i, int j);
    void InsertVex(T v);
    void RemoveVex(T v);
    void InsertEdge(EdgeType e);
    void DeleteEdge(EdgeType e);
    void DFSTraverse();
    void BFSTraverse();
    void PrintEdges();
    void PrintVexs();
    void Prim(int v);
    void Kruskal(vector<EdgeType>& tree);
    void Dijkstra(int v, vector<int>& path, vector<int>& dist);
    void Floyd(int path[][MAXV], int D[][MAXV]);
    void Toposort();
};
#endif /* MGraph_h */
