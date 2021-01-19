#include"basic.h"
#include"Sqlist.cpp"

int main(){
	SqList La,Lb,Lc;
	ElemType e;
	ElemType*pa,*pb;
	int i=0;
	if(initList_Sq(La)) printf("The sequence list creats succesiful!\n");
	if(initList_Sq(Lb)) printf("The sequence list creats succesiful!\n");
	pa=La.elem;
	pb=Lb.elem;
	while(i<=10){//La,Lb 为非递减数列； 
		if(i%2==0){
			*pa++=i++;
			La.length++;
		}	
		else {
			Lb.length++;
			*pb++=i++;
		} 	
	}
	print_l(La);
	list_print(La);
	print_l(Lb);
	list_print(Lb);
	MergeList_Sq(La,Lb,Lc);
	print_l(Lc);
	list_print(Lc);
	
	/*if(initList_Sq(L)) printf("The sequence list creats succesiful!\n");
	i=listDelete_Sq(L,3,e);
	if(!i) printf("erno :%d\n",i);
	i=ListInsert_Sq(L,1,3);
	if(!i) printf("erno :%d\n",i);
	i=ListInsert_Sq(L,1,4);
	if(!i) printf("erno :%d\n",i);
	i=listDelete_Sq(L,3,e);
	if(!i) printf("erno :%d\n",i);
	else printf("The deleted number is %d\n",e);
	i=ListInsert_Sq(L,1,7);
	if(!i) printf("erno :%d\n",i);
	i=ListInsert_Sq(L,1,10);
	if(!i) printf("erno :%d\n",i);
	i=listDelete_Sq(L,3,e);
	if(!i) printf("erno :%d\n",i);
	list_print(L);
	printf("The deleted number is %d\n",e);*/
	
}
