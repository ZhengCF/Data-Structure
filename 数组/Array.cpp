#include"basic.h"
#include<stdarg.h>     //�ṩ��va_start,va_arg,va_end,���ڴ�ȡ�䳤������ 
#define MAX_ARRAY_DIM 8
typedef int ElemType;
typedef struct {
	ElemType *base;    //����Ԫ�ػ�ַ 
	int dim;           //����ά�� 
	int *bounds;       //����ά���ַ 
	int *constants;    //����ӳ����������ַ 
}Array;      

Status InitArray(Array &A,int dim,...){
	//��ά��dim�����ĸ�ά���ȺϷ���������Ӧ������A,������OK;
	va_list ap;
	int i;
	int elemtotal; 
	if(dim<1||dim>MAX_ARRAY_DIM) return ERROR;
	A.dim=dim;
	A.bounds=(int *)malloc(dim*sizeof(int));
	if(!A.bounds) exit(OVERFLOW);
	
	elemtotal=1;
	va_start(ap,dim);
	for(i=0;i<dim;++i){
		 A.bounds[i]=va_arg(ap,int);
		 if(A.bounds[i]<0) return OVERFLOW;
		 elemtotal*=A.bounds[i];
	} 
	va_end(ap);
	A.base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
	if(!A.base) exit(OVERFLOW);
	A.constants=(int*)malloc(dim*sizeof(int));
	if(!A.constants) exit(OVERFLOW);
	A.constants[dim-1]=1;
	for(i=dim-2;i>=0;--i)
		A.constants[i]=A.bounds[i+1]*A.constants[i+1];
	return OK;	
}//InitArray 

Status DestroyArray(Array &A){
	if(!A.base) return ERROR;
	free(A.base); A.base=NULL;
	if(!A.bounds) return ERROR;
	free(A.bounds); A.bounds=NULL;
	if(!A.constants) return ERROR;
	free(A.constants); A.constants=NULL;
	return OK;
}

Status Locate(Array A,va_list ap,int &off){
	int i,ind;
	off=0;
	for(i-0;i<A.dim;++i){
		ind=va_arg(ap,int);
		if(ind<0||ind>=A.bounds[i]) return OVERFLOW;
		off+=A.constants[i]*ind;
	}
	return OK;
}

Status Value(Array A,ElemType &e,...){
	//
	//
	va_list ap;
	int off,result;
	va_start(ap,e);
	if((result=Locate(A,ap,off))<=0) return result;
	e=*(A.base+off);
	return OK;
}//Value

Status Assign(Array &A,ElemType e,...){
	//
	//
	va_list ap;
	int off,result;
	va_start(ap,e);
	if((result=Locate(A,ap,off))<=0) return result;
	*(A.base+off)=e;
	return OK;
}//Assign


