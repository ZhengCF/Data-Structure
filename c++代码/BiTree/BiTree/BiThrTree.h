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

typedef enum PointerTag{Link,Thread};     //Link==0:ָ��,Thread==1:����
typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag, RTag;
}BiThrNode,*BiThrTree;                   //ͷ���ָ����������

Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e)) {
	//Tָ��ͷ��㣬ͷ��������lchildָ������
	//��������������������ǵݹ��㷨
	BiThrTree p;
	p = T->lchild;   //pָ������
	while (p!=T)
	{//�������������ʱ��p==T��
		while (p->LTag == Link)p = p->lchild;
		if (!Visit(p->data)) return ERROR;        //������������Ϊ�յĽڵ�
		while (p->RTag==Thread&&p->lchild==T)
		{
			p = p->lchild; Visit(p->data);       //���ʺ�̽ڵ㣻
		}
		p = p->rchild;
	}
	return OK;
}//InOrderTraverse_Thr


Status Inthreading(BiThrTree p){
	BiThrTree pre;
	if (p) {
		Inthreading(p->lchild);//������������
		if (!p->lchild) { p->LTag = Thread; p->lchild = pre; }//ǰ������
		if (!pre->rchild) { pre->RTag = Thread; pre->rchild = p; }//�������
		pre = p;
		Inthreading(p->rchild);//������������
	}
}//Inthreading


Status InorderThreading(BiThrTree &Thrt, BiThrTree T) {
	//�������������T��������������Thrtָ��ͷ���
	BiThrTree pre;
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
	Thrt->LTag = Link;Thrt->RTag = Thread;//��ͷ���
	Thrt->rchild = Thrt;//��ָ���ָ
	if (!T)Thrt->lchild = Thrt;//���������գ�����ָ���ָ
	else
	{
		Thrt->lchild = T; pre = Thrt;
		Inthreading(T);      //���������������������
		pre->rchild = Thrt; pre->RTag = Thread;//���һ�����������
		Thrt->rchild = pre;
	}
	return OK;
}//InOrderThreading
