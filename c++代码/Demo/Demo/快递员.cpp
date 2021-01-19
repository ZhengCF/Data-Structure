#include<iostream>
#include<string>
using namespace std;
const int maxsize = 100;
const int INF = 1000000000; 
//ͼ�Ľṹ
template<class T>
struct Graph {
	T vertex[maxsize];//���ͼ�ж��������
	int arc[maxsize][maxsize];//���ͼ�бߵ�����
	int vertexnum, arcnum;
};
//dijkstra�㷨
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
		//��dist�в�����СֵԪ��
		int k = 0, min = INF;
		for (int i = 0; i < G.vertexnum; i++) {
			if (i == v) continue;
			if (!final[i] && dist[i] < min) {
				k = i;
				min = dist[i];
			}
		}
		cout << dist[k] <<"-"<< path[k] << endl;
		s[num++] = k;//�������ɵĽڵ���뼯��
		final[k] = true;
		//�޸�d��p����
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
	for (int i = 0; i < G.vertexnum; i++) {//��ʼ������
		for (int j = 0; j < G.vertexnum; j++) {
			if (i == j)
				G.arc[i][j] = 0;
			else
				G.arc[i][j] = INF;
			//cout << e[i][j] << " ";
		}
		//cout << endl;
	}
	for (int i = 0; i < G.vertexnum; i++)//��������
		G.vertex[i] = 0x31+i;            //10�����ڵı�ʾ
	for (int i = 0; i < G.arcnum; i++) {//·������
		int a, b;
		cin >> a >> b;
		cin >> G.arc[a-1][b-1];
	}
	Dijkstra(G, 0);
	return 0;
}
//#include<iostream>
////#include<vector>
//using namespace std;
//const int maxsize = 100;
//const int INF = 2147483647; 
//
//int main() {
//	int n, m, a, b, min, ii;
//	int e[maxsize][maxsize];
//	int path[maxsize];
//	bool final[maxsize];  //finalΪtrueʱ�����ҽ���v����S���������v0��v�����·��
//	cin >> n >> m;   //������Ŀ��·����Ŀ
//	for (int i = 0; i < n; i++) {//��ʼ������
//		final[i] = false;
//		for (int j = 0; j < n; j++) {
//			if (i == j)
//				e[i][j] = 0;
//			else
//				e[i][j] = INF;
//			//cout << e[i][j] << " ";
//		}
//		//cout << endl;
//	}
//	for (int i = 0; i < m; i++) {//·������
//		cin >> a >> b;
//		cin >> e[a-1][b-1];
//	}
//	final[0] = true;
//	for (int i = 0; i < n; i++)
//		path[i] = e[0][i];      //��ʼ���㵽��ʼ��ľ���
//	for (int i = 1; i < n; i++) {
//		min = INF;
//		for (int j = 0; j < n; j++) 
//			if (!final[j])
//				if (path[j] < min) { ii = j; min = path[j]; }
//		final[ii] = true;
//		for (int j = 0; j < n; j++)
//			if (!final[j] && min + e[ii][j] < path[j]) {
//				path[j] = min + e[ii][j];
//
//			}
//		
//	}
//	return 0;
//}
/*
5 6
1 2 1
2 3 5
3 4 5
3 5 10
1 3 2
4 5 4*/
