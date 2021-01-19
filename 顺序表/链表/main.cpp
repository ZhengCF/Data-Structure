#include"LinkList.cpp"

int main(){
	Elemtype e;
	LinkList L;
	LNode *p;
	int i=0,n=5;
	CreatList_L(L,n); 
	//p=L->next;
	Listprint(L);
	ListInsert_L(L,1,90);
	Listprint(L);
	ListDelete_L(L,1,e);
	Listprint(L);
}