#include"basic.h"
#include<time.h>
#define MAXSIZE  1000

typedef struct {
	Elemtype data;
	int      cur;
} component,SLinkList[MAXSIZE];//��� 

void InitSpace_SL(SLinkList &space){
	//���ɿ�����������Ϊ����space[0].cur Ϊͷָ��
	//"0"��ʾ��ָ�� 
	int i;
	for(i=0;i<MAXSIZE;i++) space[i].cur=i+1;
	space[MAXSIZE-1].cur=0;
} //InitSpace_SL

int Malloc_SL(SLinkList &space){
	int i;
	i=space[0].cur;
	if(space[0].cur) space[0].cur=space[i].cur;
	return i;
} //Malloc_SL

void Free_SL(SLinkList &space,int k){
	//���±�Ϊ k �Ŀ��нڵ���յ��������� 
	space[k].cur=space[0].cur;space[0].cur=k;
} //Free_SL

int LocateElem_SL(SLinkList S,Elemtype e){
	//���ҵ�����λ�򣬷��򷵻�0 
	int i=S[0].cur;
	while(i&&S[i].data!=e)	i=S[i].cur;
	return i;
} //LocateElem_SL

void differenc(SLinkList &space,int &S){
	//���뼯��A,B��Ԫ�أ���һά����space�н�����ʾ���ϵ�(A-B)U(B-A)
	//SΪ��ͷָ�룬�ռ��㹻��space[0].cur Ϊͷָ��
	int r,m,n,j,i,p,k; 
	Elemtype b;
	InitSpace_SL(space);
	S=Malloc_SL(space);
	r=S;             //r��Ϊ�α�ָ�룬����ǰ���ڵ� 
	srand((unsigned)time(NULL));
	m=rand()%5+2;
	n=rand()%5;
	//scanf("%d%d",&m,&n);      //����A��B�ĸ���
	printf("A :");
	for(j=1;j<=m;++j){
		i=Malloc_SL(space);
		//scanf("%d",&space[i].data);//����A��Ԫ��ֵ
		space[i].data=rand()%20+5;
		printf("%d ",space[i].data);
		space[r].cur=i;r=i;
	}
	printf("\nB :");
	space[r].cur=0; 
	for(j=1;j<=n;++j){
		//scanf("%d",&b);//����B��Ԫ��ֵ
		b=rand()%20+5;
		printf("%d ",b);
		p=S;k=space[S].cur;//kָ�򼯺�A�ĵ�һ���ڵ�
		/*s=LocateElem_SL(space,b);*/
		while(k!=space[r].cur&&space[k].data!=b){
			p=k;k=space[k].cur;
		} 
		if(k==space[r].cur) {          //û�� 
			i=Malloc_SL(space);
			space[i].data=b;
			space[i].cur=space[r].cur;
			space[r].cur=i;
		}
		else {
			space[p].cur=space[k].cur;
			Free_SL(space,k);
			if(r==k) r=p;
		}
	}
	printf("\n");
}

void print_SL(SLinkList	S){
	int i=1;
	printf("C :");
	while(S[i++].cur){
		printf("%d ",S[i].data);
	}
	printf("\n");
}

