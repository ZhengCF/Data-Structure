#include<stdio.h>
#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 
typedef int Status;
typedef int TElemType;

//˳��洢�ṹ
#define MAX_TREE_SIZE 100
typedef TElemType SqBiTree[MAX_TREE_SIZE];
SqBiTree bt;

//��ʽ�洢�ṹ
typedef struct BiTNode {
	TElemType   data;
	struct BiTNode *lchild, *rchild;
}*BiTree;


Status CreateBiTree(BiTree &T){}
Status PreOrderTraverse(BiTree T,Status(* Visit)(TElemType e))
{
	//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
	//Visit ��
	//	Status PrintElement(TElemType e){
	//		printf(e);
	//		return OK;
	//  }
	//����ʵ��PreOrderTraverse(T,PrintElement);

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

