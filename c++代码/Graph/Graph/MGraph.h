#include<stdio.h>
#include<stdlib.h>

#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 
typedef int Status;

//ͼ�����飨�ڽӾ��󣩴洢��ʾ
#define INFINITY      INT_MAX//���ֵ�����
#define MAX_VERTEX_NUM  20//��󶥵����
typedef enum{DG,DN,UDG,UDN}GraphKind;  //{����ͼ��������������ͼ��������}
typedef int VRType;
typedef int InfoType;
typedef int VertexType;

typedef struct ArcCell {
	VRType        adj;//VRType�Ƕ����ϵ���ͣ�����Ȩͼ ��1��0 ��ʾ���ڷ񣬶Դ�Ȩͼ����ΪȨֵ����
	InfoType      *info;//�û������Ϣ��ָ��
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType   vexs[MAX_VERTEX_NUM];//��������
	ArcCell      arcs;//�ڽӾ���
	int          vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ�����
	GraphKind    kind;//ͼ�������־
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
