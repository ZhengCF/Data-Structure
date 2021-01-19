#include<stdio.h>
#include<stdlib.h>
#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 
typedef int Status;
typedef int TElemType;

typedef enum PointerTag{Link,Thread};     //Link==0:指针,Thread==1:线索
typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag, RTag;
}BiThrNode,*BiThrTree;                   //头结点指针代表二叉树

Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e)) {
	//T指向头结点，头结点的左链lchild指向根结点
	//中序遍历二叉线索树，非递归算法
	BiThrTree p;
	p = T->lchild;   //p指向根结点
	while (p!=T)
	{//空树或遍历结束时，p==T；
		while (p->LTag == Link)p = p->lchild;
		if (!Visit(p->data)) return ERROR;        //访问其左子树为空的节点
		while (p->RTag==Thread&&p->lchild==T)
		{
			p = p->lchild; Visit(p->data);       //访问后继节点；
		}
		p = p->rchild;
	}
	return OK;
}//InOrderTraverse_Thr


Status Inthreading(BiThrTree p){
	BiThrTree pre;
	if (p) {
		Inthreading(p->lchild);//左子树线索化
		if (!p->lchild) { p->LTag = Thread; p->lchild = pre; }//前驱线索
		if (!pre->rchild) { pre->RTag = Thread; pre->rchild = p; }//后继线索
		pre = p;
		Inthreading(p->rchild);//右子树线索化
	}
}//Inthreading


Status InorderThreading(BiThrTree &Thrt, BiThrTree T) {
	//中序遍历二叉树T，中序线索化，Thrt指向头结点
	BiThrTree pre;
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
	Thrt->LTag = Link;Thrt->RTag = Thread;//建头结点
	Thrt->rchild = Thrt;//右指针回指
	if (!T)Thrt->lchild = Thrt;//若二叉树空，则做指针回指
	else
	{
		Thrt->lchild = T; pre = Thrt;
		Inthreading(T);      //中序遍历进行中序线索化
		pre->rchild = Thrt; pre->RTag = Thread;//最后一个结点线索化
		Thrt->rchild = pre;
	}
	return OK;
}//InOrderThreading
