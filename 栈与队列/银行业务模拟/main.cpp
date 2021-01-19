#include"Queue.cpp"
#include"time.h"

#define Qn     5
#define maxit  5
#define maxdt  30

typedef LinkList EventList;

EventList ev;
Event     en,et;
LinkQueue q[5];
QElemType customer;
int TotalTime,CustomerNum;
int CloseTime=100;
int n=1;

int cmp(Event a,Event b){
	if(a.Occurtime>b.Occurtime)
		return 1;
	else if(a.Occurtime<b.Occurtime)
		return -1;
	else
		return 0;	
}//cmp

int Minimum(LinkQueue *q){
	int i,j=1;
	for(i=2;i<Qn;i++){
		if(QueueLength(q[j])>QueueLength(q[i]))
			j=i;
	}//printf("ее╣з %d ап\n",j);
	return j; 
	 
}//Minimum

void Random(int &a,int &b)
{
	//srand((unsigned int)__TIME__);//seed of time
	a=rand()%maxdt+1;//duritime
	b=rand()%maxit+1;//intertime
}//Random

Event GetCurElem(Link p){
	return p->data;
}
void OpenForDay(){
	//Init operation
	int i;
	TotalTime=0;
	CustomerNum=0;
	InitList(ev);
	en.Occurtime=0; en.Ntype=0;
	OrderInsert(ev,en,cmp);
	for(i=1;i<=Qn;++i) InitQueue(q[i]);
} //OpenForDay

void CustomerArried(){
	//en.NType=0;
	int i,durtime,intertime;
	CustomerNum++;	
	Random(durtime,intertime);
	//printf("d :%d,i :%d\n",durtime,intertime);
	et.Occurtime=en.Occurtime+intertime;
	
	customer.ArrivalTime=en.Occurtime;
	customer.Duration=durtime;
	customer.num=++n;
	
	//printf("TIME :%d     ",et.Occurtime);
	//printf("c %d arrived;\n",customer.num);
	
	et.Ntype=0;
	
	if(et.Occurtime<CloseTime)
		OrderInsert(ev,et,cmp);			
	
	i=Minimum(q);        //The minimum length of queue;
	
	EnQueue(q[i],customer);
	//printf("%d",i);
	if(QueueLength(q[i])==1)
	{
		et.Occurtime=en.Occurtime+durtime;
		et.Ntype=i;
		OrderInsert(ev,et,cmp);
		                 //deparure event of i queue;
	}
		
}//CustomerArried

void CustomerDeparture(){
	//en.Ntype>0;
	int i;
	i=en.Ntype;  DeleQueue(q[i],customer);
	TotalTime+=en.Occurtime-customer.ArrivalTime;
						//accumulate customer's sojourn/stay time

	if(!QueueEmpty(q[i])){//printf("\nTIME :%d     \n",en.Occurtime);
		GetHead_Q(q[i],customer);
		et.Occurtime=en.Occurtime+customer.Duration;
		et.Ntype=i;
		OrderInsert(ev,et,cmp);
		
		//printf("c %d departure;\n",customer.num);
	}
	
} //CustomerDeparture

void Bank_Simulation(int Closetime)
{
	Link p;
	OpenForDay();
	while(!ListEmpty(ev)){
		DelFirst(GetHead(ev),p);
		//printf("%d %d\n",p->data.Occurtime,p->data.Ntype);
		en=GetCurElem(p);
		if(en.Ntype==0)
			CustomerArried();
		else 
			CustomerDeparture(); 
	}
	printf("The average time is %f\n",(float)TotalTime/CustomerNum);
}//Bank_Simulation

int main(){
	Bank_Simulation(CloseTime);
	return 0;
}
