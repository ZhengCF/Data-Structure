#include<iostream>
#define MAX_TREE_SIZE 100
using namespace std;
typedef char TElemType;

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

int degree(CTree T) {
	int d = 0,j=1;
	ChildPtr q;
	for (int i = 0; i < T.n; i++) {
		q = T.nodes[i].firstchild;
		while (q != NULL) {
			//q = T.nodes[i].firstchild;
			q = q->next;
			j++;
		}
		if (j > d)d = j;
	}
	return j;
}

void initCtree(CTree &T) {
	T.n = 10;
	T.r = 0;
	CTNode *p;
	for (int i = 0; i < T.n; i++) {
		T.nodes[i].data = (char)('A'+i);
		T.nodes[i].firstchild = NULL;
	}
	p = (ChildPtr)malloc(sizeof(struct CTNode));
	T.nodes[0].firstchild->child = 3;
	T.nodes[0].firstchild->next = p;
}
void main() {
	CTree T;
	initCtree(T);
	cout << degree(T);
}