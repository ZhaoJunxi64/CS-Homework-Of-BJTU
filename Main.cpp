#include <iostream>
#include "CGraph.h"
using namespace std;

int main() {
    int NodeNum = 5; // 顶点数
    CGraph graph(NodeNum);

    // 添加边
    graph.AddEdge(0, 1, 2);
    graph.AddEdge(0, 3, 6);
    graph.AddEdge(1, 2, 3);
    graph.AddEdge(1, 3, 8);
    graph.AddEdge(1, 4, 5);
    graph.AddEdge(2, 4, 7);
    graph.AddEdge(3, 4, 9);

    // 打印图
    cout << "图的结构：" << endl;
    graph.PrintGraph();
    cout << endl;

    // 生成最小生成树
    cout << "最小生成树：" << endl;
    graph.Prim_MST();

    cin.get();
    return 0;
}