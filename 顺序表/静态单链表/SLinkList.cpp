#include"basic.h"
#include<time.h>
#define MAXSIZE  1000

typedef struct {
	Elemtype data;
	int      cur;
} component,SLinkList[MAXSIZE];//组件 

void InitSpace_SL(SLinkList &space){
	//生成空链表，以数组为载体space[0].cur 为头指针
	//"0"表示空指针 
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
	//将下标为 k 的空闲节点回收到备用链表 
	space[k].cur=space[0].cur;space[0].cur=k;
} //Free_SL

int LocateElem_SL(SLinkList S,Elemtype e){
	//若找到返回位序，否则返回0 
	int i=S[0].cur;
	while(i&&S[i].data!=e)	i=S[i].cur;
	return i;
} //LocateElem_SL

void differenc(SLinkList &space,int &S){
	//输入集合A,B的元素，在一维数组space中建立表示集合的(A-B)U(B-A)
	//S为其头指针，空间足够大，space[0].cur 为头指针
	int r,m,n,j,i,p,k; 
	Elemtype b;
	InitSpace_SL(space);
	S=Malloc_SL(space);
	r=S;             //r作为游标指针，即当前最后节点 
	srand((unsigned)time(NULL));
	m=rand()%5+2;
	n=rand()%5;
	//scanf("%d%d",&m,&n);      //集合A和B的个数
	printf("A :");
	for(j=1;j<=m;++j){
		i=Malloc_SL(space);
		//scanf("%d",&space[i].data);//输入A的元素值
		space[i].data=rand()%20+5;
		printf("%d ",space[i].data);
		space[r].cur=i;r=i;
	}
	printf("\nB :");
	space[r].cur=0; 
	for(j=1;j<=n;++j){
		//scanf("%d",&b);//输入B的元素值
		b=rand()%20+5;
		printf("%d ",b);
		p=S;k=space[S].cur;//k指向集合A的第一个节点
		/*s=LocateElem_SL(space,b);*/
		while(k!=space[r].cur&&space[k].data!=b){
			p=k;k=space[k].cur;
		} 
		if(k==space[r].cur) {          //没有 
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

