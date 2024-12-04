#pragma once
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max(); // ��ʾ�����

class CGraph {
private:
    int NodeNum;
    vector<vector<int>> AdjMatrix; // �ڽӾ��󣬴���Ȩ��

public:
    CGraph(int N);
    ~CGraph();
    void AddEdge(int str, int dest, int weight);
    void PrintGraph();
    void Prim_MST(); // ����ķ�㷨���ͼ����С������

private:
    int minKey(const vector<int>& key, const vector<bool>& inMST);
    void printMST(const vector<int>& parent);
};