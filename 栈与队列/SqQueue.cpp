#include"head.h"
#define MAXQSIZE 100

typedef struct{
	QElemType  *base;
	int        front;     //point the front
	int        rear;      //point the next of rear
}SqQueue;

Status InitQueue(SqQueue &Q){
	//
	Q.base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q.base) exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}//InitQueue

Status QueueLength(SqQueue Q){
	return (Q.rear+MAXQSIZE-Q.front)%MAXQSIZE;
} //QueueLength

Status EnQueue(SqQueue	&Q,QElemType e){
	//
	if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;//������
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE; 
	return OK; 
}//EnQueue

Status DeleQueue(SqQueue &Q,QElemType &e){
	//
	if(Q.rear==Q.front) return ERROR;//������
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return OK;
}//DeleQueue
