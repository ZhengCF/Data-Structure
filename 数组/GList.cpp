#include "basic.h"

//广义表的--头尾链表--存储表示 
typedef enum {
	ATOM,LIST           //ATOM==0 原子，LIST==1 子表 
}ElemTag;
typedef struct GLNode{
	ElemTag tag;
	union{
		AtomType atom;
		struct {
			struct GLNode *hp,*tp;
		} ptr;
	}; 
}*GList;        //广义表类型 

//广义表的--扩展线性链表--存储表示
typedef enum {
	ATOM,LIST           //ATOM==0 原子，LIST==1 子表 
}ElemTag;
typedef struct GLNode{
	ElemTag tag;
	union{
		AtomType atom;
		struct GLNode *hp;
	} ;
	struct GLNode *tp; 
}*GList; 

int GListDepth(GList L){
	//头尾链，求广义表的深度
	int max,dep;
	GList pp;
	if(!L) return 1;//空表
	if(L->tag==ATOM) return 0;//原子 
	for(max=0,pp=L;pp;pp=pp->ptr.tp){
		dep=GListDepth(pp->ptr.hp);
		if(dep>max) max=dep;
	}
	return max+1;
} //GListDepth

Status CopyGList(GList &T,GList L){
	//头尾链表 
	if(!L) T=NULL;
	else{
		if(!(T=(GList)malloc(sizeof(GLNode)))) exit(OVERFLOW);
		T->tag=L->tag;
		if(L->tag==ATOM) T->atom=L->atom;
		else{
			CopyGList(T->ptr.tp==L->ptr.tp);
			CopyGList(T->ptr.hp==L->ptr.hp);
		}
	}
	return OK;
} //CopyGList

Status CreatGList(GList &L,SString S){
	//
	if(StrCompare(S,emp)) L=NULL;
	else{
		if(!(T=(GList)malloc(sizeof(GLNode)))) exit(OVERFLOW);
		if(StrLength(S)==1){
			L->tag=ATOM;L->atom=S;
		}
		else{
			L->tag=LIST;p=L;
			SubString(sub,S,2,StrLength(S)-2);
			do{
				//
				sever(sub,hsub);
				CreatGList(p->ptr.hp,busb);q=p;
				if(!StrEmpty(sub)){
					if(!(p=(GList)malloc(sizeof(GLNode)))) exit(OVERFLOW);
					p->tag=LIST;q->ptr.tp=p;
				}
			}while(!StrEmpty(sub));
			q->ptr.tp=NULL;
		}
	}
	return OK;
} //CreatGList

