#include "basic.h"

//������--ͷβ����--�洢��ʾ 
typedef enum {
	ATOM,LIST           //ATOM==0 ԭ�ӣ�LIST==1 �ӱ� 
}ElemTag;
typedef struct GLNode{
	ElemTag tag;
	union{
		AtomType atom;
		struct {
			struct GLNode *hp,*tp;
		} ptr;
	}; 
}*GList;        //��������� 

//������--��չ��������--�洢��ʾ
typedef enum {
	ATOM,LIST           //ATOM==0 ԭ�ӣ�LIST==1 �ӱ� 
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
	//ͷβ��������������
	int max,dep;
	GList pp;
	if(!L) return 1;//�ձ�
	if(L->tag==ATOM) return 0;//ԭ�� 
	for(max=0,pp=L;pp;pp=pp->ptr.tp){
		dep=GListDepth(pp->ptr.hp);
		if(dep>max) max=dep;
	}
	return max+1;
} //GListDepth

Status CopyGList(GList &T,GList L){
	//ͷβ���� 
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

