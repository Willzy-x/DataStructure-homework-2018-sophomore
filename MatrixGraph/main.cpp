//
//  main.cpp
//  MGraph
//
//  Created by Yucheng on 2018/11/20.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "MGraph.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream in;
    in.open("input.txt");
    if(!in)
    {
        cerr << "Cannot open file!\n";
        exit(1);
    }
    
    int n, e;
    in >> n >> e;
    int v[n];
    for (int i=0; i < n; i++) {
        v[i] = i;
    }
    GraphType k = dinetwork;
    MGraph<int> test(v, n, e, k, in);
//    test.PrintVexs();
//    test.PrintEdges();
//    test.Prim(0);
//    cout << "DFS: ";
//    test.DFSTraverse();
//    cout << "BFS: ";
//    test.BFSTraverse();
//    vector<EdgeType> tree;
//    test.Kruskal(tree);
//    for (int i=0; i < tree.size(); i++) {
//        cout << tree[i].head << "-->" << tree[i].tail << " with cost: " << tree[i].cost << endl;
//    }
//    vector<int> path(n, 0);
//    vector<int> dist(n, 0);
//    test.Dijkstra(0, path, dist);
//    for (int i=0; i < n; i++) {
//        cout << "path: " << path[i] << " distance: " << dist[i] <<  endl;
//    }
//    int path[n][20], D[n][20];
//    test.Floyd(path, D);
//    for (int i = 0; i<n; i++)
//    {
//        for (int j=0; j<n; j++)
//        {
//            cout <<" (" << i << "," << j << ") ";
//            cout << "path " << path[i][j] <<" D " << D[i][j] << "\t";
//        }
//        cout << endl;
//    }
    test.Toposort();
    cout << endl;
    cout << "Hello, World!\n";
    return 0;
}
