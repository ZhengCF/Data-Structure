//单源的最短路径问题
//最小生成树问题 n-1条
#include<iostream>
using namespace std;
const int MAXSIZE = 10000;

struct ArcNode {//弧
	int adjvex;
	ArcNode *nextArc;
	int len;
};
typedef struct {//结点
	int data;
	ArcNode *firstArc;
}VNode, AdjList[MAXSIZE];
typedef struct {//图
	AdjList vertices;
	int vexnum, arcnum;
}Graph;

Graph G;

void initGraph(int n, int m) {
	int a, b, c;
	int g[MAXSIZE];
	ArcNode *p, *q, *s;
	for (int i = 1; i <= n; i++) {
		G.vertices[i].data = i;
		g[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (g[a] == a) {
			p = (ArcNode*)malloc(sizeof(ArcNode));
			*p = { b,NULL,c };
			G.vertices[a].firstArc = p;
			g[a] = b;
		}
		else if (g[a] != a)
		{
			p = G.vertices[a].firstArc;
			while (p->adjvex != g[a])
				p = p->nextArc;
			q = (ArcNode*)malloc(sizeof(ArcNode));
			*q = { b,NULL,c };
			p->nextArc = q;
			g[a] = b;
		}
		if (g[b] == b) {
			p = (ArcNode*)malloc(sizeof(ArcNode));
			*p = { a,NULL,c };
			G.vertices[b].firstArc = p;
			g[b] = a;
		}
		else if (g[b] != b)
		{
			p = G.vertices[b].firstArc;
			while (p->adjvex != g[b])
				p = p->nextArc;
			q = (ArcNode*)malloc(sizeof(ArcNode));
			*q = { a,NULL,c };
			p->nextArc = q;
			g[b] = a;
		}
	}
}

int main() {
	int n, m, j;
	cin >> n >> m;
	initGraph(n, m);
	ArcNode *p;
	cout << "------------------------------" << endl;
	for (int i = 1; i <= n; i++) {
		cout << G.vertices[i].data << " ";
		p = G.vertices[i].firstArc; //cout << "(" << (int)p->nextArc << ")";
		while (p)
		{
			cout << p->adjvex << " ";
			//cout << "(" << (int)p->nextArc << ")";
			p = p->nextArc;
		}
		cout << endl;
	}
}