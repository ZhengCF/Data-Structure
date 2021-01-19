#include<stdio.h>
#include<stdlib.h>

#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 
typedef int Status;

//图的数组（邻接矩阵）存储表示
#define INFINITY      INT_MAX//最大值无穷大
#define MAX_VERTEX_NUM  20//最大顶点个数
typedef enum{DG,DN,UDG,UDN}GraphKind;  //{有向图，有向网，无向图，无向网}
typedef int VRType;
typedef int InfoType;
typedef int VertexType;

typedef struct ArcCell {
	VRType        adj;//VRType是顶点关系类型，对无权图 用1或0 表示相邻否，对带权图，则为权值类型
	InfoType      *info;//该弧相关信息的指针
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType   vexs[MAX_VERTEX_NUM];//顶点向量
	ArcCell      arcs;//邻接矩阵
	int          vexnum, arcnum;//图的当前顶点数和弧数；
	GraphKind    kind;//图的种类标志
}MGraph;

Status CreateGraph(MGraph &G) {
	//
	scanf("%d", &G.kind);
	switch (G.kind)
	{
	case DG:return CreateDG(G);
	case DN:return CreateDN(G);
	case UDG:return CreateUDG(G);
	case UDN:return CreateUDN(G);
	default:
		break;
	}
}

Status CreateDG(MGraph &G) {
	//
	int i, j, k;
	int IncInfo;
	scanf("%d%d%d", &G.vexnum, &G.arcnum, &IncInfo);
	for (i = 0; i < G.vexnum; i++) scanf("%d", &G.vexs);
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)G.arcs[i][j] = { INFINITY,NULL };
	for (k = 0; k < G.arcnum; k++) {
		scanf("%d%d%d", &v1, &v2, &w);
		i = LocateVex(G, v1);j= LocateVex(G, v2);
		G.arcs[i][j].adj = w;
		if (IncInfo) Input(*G.arcs[i][j].info);
		G.arcs[j][i] = G.arcs[i][j];
	}
}
Status CreateDN(MGraph &G) {}
Status CreateUDG(MGraph &G) {}
Status CreateUDN(MGraph &G) {}
