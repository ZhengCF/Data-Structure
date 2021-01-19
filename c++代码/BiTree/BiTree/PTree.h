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

//˫�ױ�ʾ��
#define MAX_TREE_SIZE 100
typedef struct {
	TElemType data;
	int parent;
}PTNode;

typedef struct {//���ṹ
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;//����λ�úͽ����
}PTree;

//���ĺ�������洢��ʾ
typedef struct CTNode {//���ӽڵ�
	int  child;
	struct CTNode *next;
}*ChildPtr;

typedef struct {
	TElemType data;
	ChildPtr firstchild; //��������ͷָ��
}CTBox;

typedef struct {//���ṹ
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;
}CTree;

//���Ķ�����������-�ֵܣ���ʾ��
typedef struct CSNode{
	ElemType data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
