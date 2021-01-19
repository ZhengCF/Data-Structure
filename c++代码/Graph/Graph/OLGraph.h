#include<stdio.h>
#include<stdlib.h>

#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 
#define MAX_VERTEX_NUM  20//��󶥵����
typedef int Status;
typedef int InfoType;
typedef int VertexType;

typedef struct ArcBox {
	int              tailvex, headvex;//�û���β��ͷ�����λ��
	struct ArcBox    *hlink, *tlink;//��ͷ��ͬ�ͻ�β��ͬ������
	InfoType         *info;//�û������Ϣ��ָ��
};

typedef struct VexNode{
	VertexType     data;
	ArcBox		*firstin, *firstout;//�ֱ�ָ��ö����һ���뻡�ͳ���
};

typedef struct {
	VexNode    xlist[MAX_VERTEX_NUM];//��ͷ����
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
		scanf("%d%d", &v1, &v2);//����һ�����������յ�
		i = LocateVex(G, v1); j = LocateVex(G, v2);
		p = (ArcBox*)malloc(sizeof(ArcBox));
		*p = { i,j,G.xlist[j].firstin,G.xlist[i].firstout,NULL };
		G.xlist[j].firstin = G.xlist[i].firstout = p;//������뻡�ͳ����Ĳ���
		if (IncInfo) Input(*p->info);
	}
}
