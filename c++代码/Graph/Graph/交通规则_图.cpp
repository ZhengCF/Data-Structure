//单源的最短路径问题
//最小生成树问题 n-1条
#include<iostream>
using namespace std;
const int MAXSIZE = 10000;

struct ArcNode{//弧
	int adjvex;
	ArcNode *nextArc;
	int len;
};
typedef struct {//结点
	int data;
	ArcNode *firstArc;
}VNode,AdjList[MAXSIZE];
typedef struct {//图
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