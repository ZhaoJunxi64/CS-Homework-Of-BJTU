#include <iostream>
#include "CGraph.h"
using namespace std;

int main() {
    int NodeNum = 5; // ������
    CGraph graph(NodeNum);

    // ��ӱ�
    graph.AddEdge(0, 1, 2);
    graph.AddEdge(0, 3, 6);
    graph.AddEdge(1, 2, 3);
    graph.AddEdge(1, 3, 8);
    graph.AddEdge(1, 4, 5);
    graph.AddEdge(2, 4, 7);
    graph.AddEdge(3, 4, 9);

    // ��ӡͼ
    cout << "ͼ�Ľṹ��" << endl;
    graph.PrintGraph();
    cout << endl;

    // ������С������
    cout << "��С��������" << endl;
    graph.Prim_MST();

    cin.get();
    return 0;
}