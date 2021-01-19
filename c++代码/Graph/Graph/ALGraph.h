#include<stdio.h>
#include<stdlib.h>

#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 
typedef int Status;
typedef int InfoType;
typedef int VertexType;

#define MAX_VERTEX_NUM  20//��󶥵����
typedef struct ArcNode {
	//���
	int              adjvex;//�û���ָ��Ķ����λ��
	struct ArcNode  *nextarc;//ָ����һ������ָ��
	InfoType        *info;//�û������Ϣ��ָ��
}ArcNode;

typedef struct VNode {
	//����
	VertexType   data;//������Ϣ
	ArcNode      *firstarc;//ָ���һ�������ö���Ļ���ָ��
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList		vertices;
	int         vexnum, arcnum;
	int			kind;
}ALGraph;
