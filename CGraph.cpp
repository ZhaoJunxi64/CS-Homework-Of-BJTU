#include "CGraph.h"

int SINGLE_EDGE =0 ;

CGraph::CGraph(int N) : NodeNum(N), AdjMatrix(N, vector<int>(N, INF)) {
    // 初始化邻接矩阵，所有边的初始权重为 INF(无限大)
    for (int i = 0; i < NodeNum; ++i) {
        AdjMatrix[i][i] = 0; // 自己的权重为 0
    }
}

CGraph::~CGraph() {
    // 析构函数可以留空，因为我们使用的是标准库容器
}

void CGraph::AddEdge(int str, int dest, int weight) {
    if (str < 0 || str >= NodeNum || dest < 0 || dest >= NodeNum) {
        cout << "边 " << str << "->" << dest << " 无效" << endl;
        return;
    }
    AdjMatrix[str][dest] = weight;
    if(!SINGLE_EDGE)
        AdjMatrix[dest][str] = weight; // 无向图 双向建立
}

void CGraph::PrintGraph() {
    for (int i = 0; i < NodeNum; ++i) {
        for (int j = 0; j < NodeNum; ++j) {
            if (AdjMatrix[i][j] == INF) {
                printf("INF  ");
            }
            else {
                printf("%-5d", AdjMatrix[i][j]);
            }
        }
        cout << endl;
    }
}

void CGraph::Prim_MST() {
    vector<int> key(NodeNum, INF); // 用于记录最小权重
    vector<int> parent(NodeNum, -1); // 用于记录最小生成树的父节点
    vector<bool> inMST(NodeNum, false); // 用于记录节点是否已经在最小生成树中

    // 从顶点 0 开始
    key[0] = 0;
    parent[0] = -1; // 根节点没有父节点

    for (int count = 0; count < NodeNum - 1; ++count) {
        int u = minKey(key, inMST);

        if (u == -1) {
            cout << "无法找到最小生成树，图可能不连通" << endl;
            return;
        }

        inMST[u] = true;

        // 更新相邻节点的 key 值
        for (int v = 0; v < NodeNum; ++v) {
            if (AdjMatrix[u][v] != INF && !inMST[v] && AdjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = AdjMatrix[u][v];
            }
        }
    }

    // 打印最小生成树
    printMST(parent);
}

int CGraph::minKey(const vector<int>& key, const vector<bool>& inMST) {
    int min = INF, min_index = -1;

    for (int v = 0; v < NodeNum; ++v) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void CGraph::printMST(const vector<int>& parent) {
    cout << "边 \t 权重" << endl;
    for (int i = 1; i < NodeNum; ++i) {
        if(!SINGLE_EDGE)cout << parent[i] << " - " << i << " \t " << AdjMatrix[i][parent[i]] << endl;
        else cout << parent[i] << " -> " << i << " \t " << AdjMatrix[i][parent[i]] << endl;
    }
}