#pragma once
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max(); // 表示无穷大

class CGraph {
private:
    int NodeNum;
    vector<vector<int>> AdjMatrix; // 邻接矩阵，储存权重

public:
    CGraph(int N);
    ~CGraph();
    void AddEdge(int str, int dest, int weight);
    void PrintGraph();
    void Prim_MST(); // 普利姆算法获得图的最小生成树

private:
    int minKey(const vector<int>& key, const vector<bool>& inMST);
    void printMST(const vector<int>& parent);
};