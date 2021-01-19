#include<stdio.h>
#include<stdlib.h>

#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 
#define MAX_VERTEX_NUM  20//最大顶点个数
typedef int Status;
typedef int InfoType;
typedef int VertexType;

typedef enum{unvisited,visited}VisitedIf;
typedef struct EBox{
	VisitedIf     mark;
	int			ivex, jvex;
	struct EBox  *ilink, *jlink;
	InfoType	*info;
};

typedef struct VexBox {
	VertexType data;
	EBox		*firstedge;
};

typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];
	int     vexnum, edgenum;
}AMLGraph,Graph;

bool visited[MAX_VERTEX_NUM];
Status(*VisitFunc)(int v);

//深度优先算法
void DFSTraverse(Graph G, Status(*visit)(int v)) {
	//
	int v;
	VisitFunc = visit;//
	for (v = 0; v < G.vexnum; v++) visited[v] = FLASE;//init
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v]) DFS(G, v);
}

void DFS(Graph G, int v) {
	//从第v个顶点出发，递归的深度优先遍历图G
	int w;
	visited[v] = TRUE;  VisitFunc(v);
	for (w = FirstAdjVex(G, v); w >= 0; w=NextAdjVex(G,v,w))
		if (!visited[w]) DFS(G, w);
}

Status FirstAdjVex(Graph G,int v){}
Status NextAdjVex(Graph G, int v,int w) {}

//广度优先算法
void BFSTraverse(Graph G, Status(*visit)(int v)) {
	//
	int v,w;
	for (v = 0; v < G.vexnum; v++) visited[v] = FLASE;//init
	//IntQueue(Q);
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v]) {
			visited[v] = TRUE;  visit(v);
			//EnQueue(Q,v);
			while (/*!QueueEmpty(Q)*/1)
			{
				//DeQueue(Q,u);
				for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
					if (!visited[w]) {
						visited[w] = TRUE;  visit(w);
						//EnQueue(Q,v);
					}
			}
		}
}
