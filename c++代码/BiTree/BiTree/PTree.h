#include<stdio.h>
#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 
typedef int Status;
typedef int TElemType;
typedef int ElemType;

//双亲表示法
#define MAX_TREE_SIZE 100
typedef struct {
	TElemType data;
	int parent;
}PTNode;

typedef struct {//树结构
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;//根的位置和结点数
}PTree;

//树的孩子链表存储表示
typedef struct CTNode {//孩子节点
	int  child;
	struct CTNode *next;
}*ChildPtr;

typedef struct {
	TElemType data;
	ChildPtr firstchild; //孩子链表头指针
}CTBox;

typedef struct {//树结构
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;
}CTree;

//树的二叉链表（孩子-兄弟）表示法
typedef struct CSNode{
	ElemType data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
