#include"head.h"

//单链队列，链式存储结构 
typedef struct QNode{
	QElemType     data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr   front;
	QueuePtr   rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q){
	//构造一个空队
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode)); 
	if(!Q.front) exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
} //InitQueue

Status DestroyQueue(LinkQueue &Q){
	//销毁队列
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
