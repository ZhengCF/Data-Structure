#include<stdio.h>
#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 
typedef int Status;
typedef int TElemType;

//顺序存储结构
#define MAX_TREE_SIZE 100
typedef TElemType SqBiTree[MAX_TREE_SIZE];
SqBiTree bt;

//链式存储结构
typedef struct BiTNode {
	TElemType   data;
	struct BiTNode *lchild, *rchild;
}*BiTree;


Status CreateBiTree(BiTree &T){}
Status PreOrderTraverse(BiTree T,Status(* Visit)(TElemType e))
{
	//先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
	//Visit ：
	//	Status PrintElement(TElemType e){
	//		printf(e);
	//		return OK;
	//  }
	//调用实例PreOrderTraverse(T,PrintElement);

	if (T) {
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit)) return OK;
		return ERROR;
	}
	else return OK;
}
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {}
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {}
Status LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {}

