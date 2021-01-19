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

#define MAX_VERTEX_NUM  20//最大顶点个数
typedef struct ArcNode {
	//结点
	int              adjvex;//该弧所指向的顶点的位置
	struct ArcNode  *nextarc;//指向下一条弧的指针
	InfoType        *info;//该弧相关信息的指针
}ArcNode;

typedef struct VNode {
	//顶点
	VertexType   data;//顶点信息
	ArcNode      *firstarc;//指向第一条依附该顶点的弧的指针
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList		vertices;
	int         vexnum, arcnum;
	int			kind;
}ALGraph;
