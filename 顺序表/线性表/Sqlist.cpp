#include"basic.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define ElemType       int

#define print_l(n)printf ("The list of "#n" is :");//宏定义取变量命名 

typedef struct{
	ElemType *elem;     //?洢????? 
	int length;
	int list_size;
} SqList;

Status initList_Sq(SqList &L){
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);
	L.length=0;
	L.list_size=LIST_INIT_SIZE;
	return OK; 
}//initList_Sq

Status ListInsert_Sq(SqList &L,int i,ElemType e){
	ElemType *newbase;
	ElemType *p,*q;
	//ElemType *q;
	if(i>L.length+1||i<1) return ERROR;
	if(L.length>=L.list_size){
		newbase=(ElemType*)realloc(L.elem,LISTINCREMENT*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		L.elem=newbase;
		L.list_size+=LISTINCREMENT;
	}
	q=&(L.elem[i-1]);
	for(p=&(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p;
	*q=e;
	++L.length;
	return OK;
} //ListInsert_Sq

Status listDelete_Sq(SqList &L,int i,ElemType &e){
	//ElemType e;
	ElemType *p;
	if(L.length<=0) return ERROR;
	if(i>L.length||i<1) return ERROR;
	e=(L.elem[i-1]);
	for(p=&(L.elem[i]);p<&(L.elem[L.length]);p++) *(p-1)=*p;
	--L.length;
	return OK;
}//listDelete_Sq

Status list_print(SqList L){
	ElemType *p;
	if(L.length<=0) printf("The list is empty!");
	else {
		for(p=&(L.elem[0]);p<&(L.elem[L.length]);p++)
			printf("%d ",*p);
	}
	printf("\n");
	return OK;
}

int LocateElem_Sq(SqList L,ElemType e,Status(*compare)(ElemType,ElemType)){
	int i=1;
	ElemType *p;
	p=L.elem;
	while(i<=L.length&&!(*compare)(*p++,e)) i++;
	if(i<=L.length)return i;
	else  return 0;
} //LocateElem_Sq


void MergeList_Sq(SqList La,SqList Lb,SqList &Lc){
	ElemType *pa,*pb,*pc;
	ElemType *pa_last,*pb_last;
	pa=La.elem;
	pb=Lb.elem;
	Lc.list_size=Lc.length=La.length+Lb.length;
	//
	pc=Lc.elem=(ElemType*)malloc(Lc.list_size*sizeof(ElemType));
	if(!Lc.elem) exit(OVERFLOW);
	pa_last=La.elem+La.length-1;
	pb_last=Lb.elem+Lb.length-1; 
	while(pa<=pa_last&&pb<=pb_last){
		if(*pa<=*pb)
			*pc++=*pa++;
		else 
			*pc++=*pb++;
	}
	while(pa<=pa_last) *pc++=*pa++;
	while(pb<=pb_last) *pc++=*pb++;
	//return 0;
}//MergeList_Sq
