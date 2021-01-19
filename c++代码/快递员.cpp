#include<iostream>
#include<string>
using namespace std;
const int maxsize = 100;
const int INF = 1000000000; 
//图的结构
template<class T>
struct Graph {
	T vertex[maxsize];//存放图中顶点的数组
	int arc[maxsize][maxsize];//存放图中边的数组
	int vertexnum, arcnum;
};
//dijkstra算法
void Dijkstra(Graph<string> G, int v) {
	int dist[maxsize];
	string path[maxsize];
	int s[maxsize];
	bool final[maxsize];
	for (int i = 0; i < G.vertexnum; i++) {
		final[i] = false;
		dist[i] = G.arc[v][i];
		if (dist[i] != INF)
			path[i] = G.vertex[v] +"->"+ G.vertex[i];
		else
			path[i] = " ";
	}
	s[0] = v;
	final[v] = true;
	int num = 1;
	while (num < G.vertexnum) {
		//在dist中查找最小值元素
		int k = 0, min = INF;
		for (int i = 0; i < G.vertexnum; i++) {
			if (i == v) continue;
			if (!final[i] & dist[i] < min) {
				k = i;
				min = dist[i];
			}
		}
		cout << dist[k] <<"-"<< path[k] << endl;
		s[num++] = k;//将新生成的节点加入集合
		final[k] = true;
		//修改d，p数组
		for (int i = 0; i < G.vertexnum; i++) {
			if (!final[i] && dist[i] > dist[k] + G.arc[k][i]) {
				dist[i] = dist[k] + G.arc[k][i];
				path[i] = path[k] +"->"+ G.vertex[i];
			}
		}
	}
}
int main() {
	Graph<string> G;
	cin >> G.vertexnum >> G.arcnum;
	for (int i = 0; i < G.vertexnum; i++) {//初始化方阵
		for (int j = 0; j < G.vertexnum; j++) {
			if (i == j)
				G.arc[i][j] = 0;
			else
				G.arc[i][j] = INF;
			//cout << e[i][j] << " ";
		}
		//cout << endl;
	}
	for (int i = 0; i < G.vertexnum; i++)//顶点输入
		G.vertex[i] = 0x31+i;
	for (int i = 0; i < G.arcnum; i++) {//路径输入
		int a, b;
		cin >> a >> b;
		cin >> G.arc[a-1][b-1];
	}
	Dijkstra(G, 0);
	return 0;
}
/*
5 6
1 2 1
2 3 5
3 4 5
3 5 10
1 3 2
4 5 4*/
