#include<iostream>
using namespace std;
typedef struct {
	int *elem;
	int length;
	int listsize;
}sqList;

typedef struct DulNode {
	int data;
	struct DulNode *prior;
	struct DulNode *next;
}DulNode,*DuLinkList;

void change(DuLinkList &DL, sqList L) {
	DulNode *p,*q;
	DL = (DulNode*)malloc(sizeof(DulNode));
	DL->data = L.elem[0];
	p = DL;
	for (int i = 1; i < L.length;i++) {
		q = (DulNode*)malloc(sizeof(DulNode));
		q->data = L.elem[i];
		q->prior = p;
		p->next = q;
		p = q;
	}
	DL->prior = p;
	p->next = DL;
}

void initeSq(sqList &L,int n) {
	L.length = n;
	//int *p;
	//p = L.elem;
	L.elem = (int *)malloc(n * sizeof(int));
	L.listsize = 100;
	for (int i = 0; i < L.length; i++)
	{
		//*(p++) = i;
		L.elem[i] = i+1;
	}
}

void test1(DuLinkList &DL) {
	DuLinkList p;
	int n = 1; 
	while (n)
	{
		p = DL;
		cin >> n;
		while(1){
			while (n <= 0 || n > 10)
			{
				cout << "wrong input ,please input again" << endl;
				cin >> n;
			}
			if (p->data == n) {
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=";
				cout << n << "' prior is :" << p->prior->data << " and next is :" << p->next->data << endl;
				break;
			}
			p = p->next;
		}		
	}
}

int main() {
	DuLinkList DL;
	sqList L;
	int n = 10;
	initeSq(L, n);
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << '\t';
	}
	cout << endl;
	change(DL, L);
	test1(DL);
}