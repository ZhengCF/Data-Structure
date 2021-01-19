#include"basic.h"
#define MAXSIZE 12500
typedef int ElemType; 
typedef struct {
	int i,j;
	ElemType e;
} Triple;

typedef struct {
	Triple data[MAXSIZE+1];
	int  mu,nu,tu;
}TSMatrix;

Status TransposeSMtrix(TSMatrix M,TSMatrix &T){
	int q,p,col;
	T.mu=M.mu;
	T.nu=M.nu;
	T.tu=M.tu;
	if(T.tu){
		q=1;
		for(col=1;col<M.mu;++col)
			for(p=1;p<=M.tu;++p)
				if(T.data[p].j==col){
					T.data[q].i=M.data[p].j;
					T.data[q].j=M.data[p].i;
					T.data[q].e=M.data[p].e;
			}
	}
	return OK; 
}//TransposeSMtrix

Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T){
	int q,p,col,t;
	int num[M.nu+1],cpot[M.nu+1];
	T.mu=M.mu;
	T.nu=M.nu;
	T.tu=M.tu;
	if(T.tu){
		for(col=1;col<M.nu;++col) num[col]=0;
		for(t=1;t<=M.tu;++t) ++num[M.data[t].j];
		cpot[1]=1;
		for(col=1;col<M.nu;++col) cpot[col]=cpot[col-1]+num[col-1];
		for(p=1;p<=M.tu;++p){
			col=M.data[p].j; q=cpot[col]; 
			T.data[q].i=M.data[p].j;
			T.data[q].j=M.data[p].i;
			T.data[q].e=M.data[p].e;
			++cpot[col];
		}
	}
	return OK;
}//FastTransposeSMatrix
