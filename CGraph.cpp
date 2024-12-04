#include "CGraph.h"

int SINGLE_EDGE =0 ;

CGraph::CGraph(int N) : NodeNum(N), AdjMatrix(N, vector<int>(N, INF)) {
    // ��ʼ���ڽӾ������бߵĳ�ʼȨ��Ϊ INF(���޴�)
    for (int i = 0; i < NodeNum; ++i) {
        AdjMatrix[i][i] = 0; // �Լ���Ȩ��Ϊ 0
    }
}

CGraph::~CGraph() {
    // ���������������գ���Ϊ����ʹ�õ��Ǳ�׼������
}

void CGraph::AddEdge(int str, int dest, int weight) {
    if (str < 0 || str >= NodeNum || dest < 0 || dest >= NodeNum) {
        cout << "�� " << str << "->" << dest << " ��Ч" << endl;
        return;
    }
    AdjMatrix[str][dest] = weight;
    if(!SINGLE_EDGE)
        AdjMatrix[dest][str] = weight; // ����ͼ ˫����
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
    vector<int> key(NodeNum, INF); // ���ڼ�¼��СȨ��
    vector<int> parent(NodeNum, -1); // ���ڼ�¼��С�������ĸ��ڵ�
    vector<bool> inMST(NodeNum, false); // ���ڼ�¼�ڵ��Ƿ��Ѿ�����С��������

    // �Ӷ��� 0 ��ʼ
    key[0] = 0;
    parent[0] = -1; // ���ڵ�û�и��ڵ�

    for (int count = 0; count < NodeNum - 1; ++count) {
        int u = minKey(key, inMST);

        if (u == -1) {
            cout << "�޷��ҵ���С��������ͼ���ܲ���ͨ" << endl;
            return;
        }

        inMST[u] = true;

        // �������ڽڵ�� key ֵ
        for (int v = 0; v < NodeNum; ++v) {
            if (AdjMatrix[u][v] != INF && !inMST[v] && AdjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = AdjMatrix[u][v];
            }
        }
    }

    // ��ӡ��С������
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
    cout << "�� \t Ȩ��" << endl;
    for (int i = 1; i < NodeNum; ++i) {
        if(!SINGLE_EDGE)cout << parent[i] << " - " << i << " \t " << AdjMatrix[i][parent[i]] << endl;
        else cout << parent[i] << " -> " << i << " \t " << AdjMatrix[i][parent[i]] << endl;
    }
}