#include"head.h"

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}*Link,*position;

typedef struct LinkList{
	Link head,tail;
} LinkList;

Status InitList(LinkList &L)
{ 
	//int i=0;
	Link p;
	p=(Link)malloc(sizeof(LNode));
	if(!p) exit(OVERFLOW);
	p->next=NULL;
	L.head=L.tail=p;
	printf("The day is start------\n"); 
}// CreatList_L

Status ListEmpty(LinkList L){
	return L.head->next==NULL;
}//ListEmpty
 
Status DelFirst(Link h,Link &q){
	q=h->next;
	printf("%d:%d ",q->data.Occurtime/60+8,q->data.Occurtime%60);
	if(q->data.Ntype==0)
		printf("cus arrived\n");
	else
		printf("cus departure from %d queue\n",q->data.Ntype); 
	if(q)
	{
		h->next=q->next;//printf("-------");		
		return OK;
	}
	else
 		return ERROR;
}//DelFirst

Status OrderInsert(LinkList &L,ElemType e,int (*cmp)(Event,Event)){
	Link p,q,o;
	q=L.head;
	p=q->next;
	while(p&&cmp(p->data,e)<0)
	{
		q=p;
		p=p->next;
	}
	o=(Link)malloc(sizeof(LNode));
	o->data=e;
	q->next=o;
	o->next=p;
	if(!p)
		L.tail=o;    // 
	//free(o);
	return OK;
}//ListInsert_L

position GetHead(LinkList L)
{//printf("======");
	return L.head;
}//GetHead

/*Status Listprint(LinkList L){
	LNode *p;
	//int i=6;
	p=L->next;
	//printf("%d",L->data);
	ElemType e=p->data;
	while(!p){
		printf("Occurring time is :%d  the event is :%d\n",p->data.Occurtime,p->data.Ntype);
		p=p->next;
	}
	printf("\n");
	return OK;
}*/

//printf("----");
