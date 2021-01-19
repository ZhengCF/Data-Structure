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
#define MAX_TREE_SIZE 100
typedef TElemType SqBiTree[MAX_TREE_SIZE];
SqBiTree bt;

typedef struct BiTNode {
	TElemType   data;
	struct BiTNode *lchild, *rchild;
}*BiTree;

Status PrintElement(TElemType e){
	printf("%d ",e);
	return OK;
}

Status CreateBiTree(BiTree &T)
{
	TElemType e;
	scanf("%d",e);
	if(e=='#') T==NULL;
/*
	else if(e=='#'){
		T==NULL; return OK;
	}
*/
	else{
		if(!(T=(BiTree)malloc(sizeof(BiTNode)))) exit(ERROR);
		T->data=e;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild); 
	}
	return OK;
}

Status PreOrderTraverse(BiTree T,Status(* PrintElement)(TElemType e))
{
	//先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
	//Visit ：
	//	Status PrintElement(TElemType e){
	//		printf(e);
	//		return OK;
	//  }
	//调用实例PreOrderTraverse(T,PrintElement);

	if (T) {
		if (PrintElement(T->data))
			if (PreOrderTraverse(T->lchild, PrintElement))
				if (PreOrderTraverse(T->rchild, PrintElement)) return OK;
		return ERROR;
	}
	else return OK;
}

int main()
{
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T,PrintElement);
}

Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {}
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {}
Status LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {}

