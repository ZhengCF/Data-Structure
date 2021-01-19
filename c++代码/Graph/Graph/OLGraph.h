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

typedef struct ArcBox {
	int              tailvex, headvex;//该弧的尾和头顶点的位置
	struct ArcBox    *hlink, *tlink;//弧头相同和弧尾相同的链域
	InfoType         *info;//该弧相关信息的指针
};

typedef struct VexNode{
	VertexType     data;
	ArcBox		*firstin, *firstout;//分别指向该顶点第一条入弧和出弧
};

typedef struct {
	VexNode    xlist[MAX_VERTEX_NUM];//表头向量
	int			vexnum, arcnum;//
}OLGraph;

Status CreateDG(OLGraph &G) {
	//
	int i, j, k;
	int IncInfo;
	ArcBox *p;
	scanf("%d%d%d", &G.vexnum, &G.arcnum, &IncInfo);
	for (i = 0; i < G.vexnum; i++) {
		scanf("%d", &G.xlist[i].data);
		G.xlist[i].firstin = NULL;
		G.xlist[i].firstout = NULL;
	}
	for (k = 0; k < G.arcnum; k++) {
		scanf("%d%d", &v1, &v2);//输入一条弧的起点和终点
		i = LocateVex(G, v1); j = LocateVex(G, v2);
		p = (ArcBox*)malloc(sizeof(ArcBox));
		*p = { i,j,G.xlist[j].firstin,G.xlist[i].firstout,NULL };
		G.xlist[j].firstin = G.xlist[i].firstout = p;//完成在入弧和出弧的插入
		if (IncInfo) Input(*p->info);
	}
}
