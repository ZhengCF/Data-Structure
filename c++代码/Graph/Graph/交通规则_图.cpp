//��Դ�����·������
//��С���������� n-1��
#include<iostream>
using namespace std;
const int MAXSIZE = 10000;

struct ArcNode{//��
	int adjvex;
	ArcNode *nextArc;
	int len;
};
typedef struct {//���
	int data;
	ArcNode *firstArc;
}VNode,AdjList[MAXSIZE];
typedef struct {//ͼ
	AdjList vertices;
	int vexnum, arcnum;
}Graph;

Graph G;

int main() {
	int n, m, D[MAXSIZE],da[MAXSIZE][3];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		D[i] = INFINITY;
	for (int i = 0; i < m; i++) {
		cin >> da[i][0] >> da[i][1] >> da[i][2];
		if (da[i][0] == 1)
			D[da[i][1]] = da[i][2];
	}

}