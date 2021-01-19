#include"basic.h"

typedef struct LNode{
	Elemtype data;
	struct LNode *next;
}LNode,*LinkList;

Status CreatList_L(LinkList &L,int n){ 
	//int i=0;
	LNode *p;
	L=(LinkList)malloc(sizeof(LNode));
	L->data=n;
	while(n--){
		//L 作为链表的表头，代表链表，故不做修改；
		p=(LinkList)malloc(sizeof(LNode));//每个节点分配一个空间； 
		//scanf(&p->data);
		p->data=n;
		//p=p->next; //插入表尾 ?
		p->next=L->next;L->next=p;//插入表头 
	}
}// CreatList_L


Status GetElem_L(LinkList L, int i,Elemtype &e){
	LNode *p;
	p=L->next;
	int j=1;
	while(p&&j!=i){
		p=p->next;j++; 
	}
	if(!p||j>i) exit(OVERFLOW);
	e=p->data;
	return OK; 
}//GetElem_L

Status ListInsert_L(LinkList &L,int i,Elemtype e){
	LNode *p,*q;
	p=L; //p=L;
	int j=0;   //j=0;
	while(p&&j<i-1){
		p=p->next;
		j++;
	}
	if(!p||j>i-1) return ERROR;
	q=(LinkList)malloc(sizeof(LNode));
	q->data=e;
	q->next=p->next;
	p->next=q;
	L->data+=1;
	return OK;
}//ListInsert_L

Status ListDelete_L(LinkList &L,int i,Elemtype e){
	int j=0;
	LNode *p;
	p=L;
	while(p->next&&j++<i-1) p=p->next;
	if(!(p->next)&&j>i-1) return ERROR;
	e=p->data;
	p->next=p->next->next;
	L->data-=1;
	return OK;
}//ListDelete_L

void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	LNode *pa,*pb,*pc;
	pa=La->next;pb=Lb->next;
	Lc=pc=La;
	while(pa&&pb){
		if(pa->data<pb->data){
			pc->next=pa;pc=pa;pa=pa->next;	
		}
		else{
			pc->next=pb;pc=pb;pb=pb->next;
		}
	}
	free(Lb);
} 
Status Listprint(LinkList L){
	LNode *p;
	//int i=6;
	p=L->next;
	//printf("%d",L->data);
	int i=L->data;
	while(i--){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

//printf("----");
