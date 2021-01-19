#include"LinkList.cpp"

//�������У���ʽ�洢�ṹ 
typedef struct QNode{
	QElemType     data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr   front;
	QueuePtr   rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q){
	//����һ���ն�
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode)); 
	if(!Q.front) exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
} //InitQueue

Status DestroyQueue(LinkQueue &Q){
	//���ٶ���
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear; 
	} 
	return OK;
}//DestroyQueue

Status EnQueue(LinkQueue &Q,QElemType e){
	//
	QNode *p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data=e;p->next=NULL;
	Q.rear->next=p;
	Q.rear=p; 
	return OK;
}//EnQueue

Status DeleQueue(LinkQueue &Q,QElemType &e){
	//
	QNode *p;
	if(Q.rear==Q.front) return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)Q.rear=Q.front;
	free(p);
	return OK;
}//DeleQueue

Status GetHead_Q(LinkQueue Q,QElemType &e)
{
	if(Q.front==Q.rear)
		return 0;
	else
		e=Q.front->next->data;
	return OK;
} //GetHead

Status QueueEmpty(LinkQueue Q){
	return Q.rear==Q.front; 
}//QueueEmpty

Status QueueLength(LinkQueue Q){
	int i=0;
	QueuePtr p;
	p=Q.front;
	while(p!=Q.rear){
		i++;
		p=p->next;
	}
	return i;	
} //QueueLength
