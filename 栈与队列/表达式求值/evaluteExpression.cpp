#include"stack.cpp"

char OP[7]={
	'+','-','*','/','(',')','#'
};

char PR[7][7]={
	{'>','>','<','<','<','>','>'},
	{'>','>','<','<','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'<','<','<','<','<','=',' '},
	{'>','>','>','>',' ','>','>'},
	{'<','<','<','<','<',' ','='},
};

bool In(char c,char *OP){
	char *p=OP;
	while(*p){
		if(c==*p++)
			return OK;
	}
	return 0;
}//In

char Precede(char t,char c){
	int i,j;
	for(i=0;i<7;i++){
		if(t==OP[i])
			break;
	}
	for(j=0;j<7;j++){
		if(c==OP[j])
			break;
	}
	return PR[i][j];
}

char Operate(char a,char theta,char b){
	switch(theta){
		case '+':printf("%d+%d=%d\n",a,b,a+b);
			return a+b;
			break;
		case '-':printf("%d-%d=%d\n",a,b,a-b);
			return a-b;
			break;
		case '*':printf("%d*%d=%d\n",a,b,a*b);
			return a*b;
			break;
		case '/':printf("%d/%d=%d\n",a,b,a/b);
			return a/b;
			break;
	}
} //Operate

char EvalutExp(){
	//
	Sqstack OPND,OPTR;
	char a,b,c,theta,x;
	IniteStack(OPTR); Push(OPTR,'#');
	IniteStack(OPND); c=getchar();//printf("----\n");
	while(c!='#'||GetTop(OPTR)!='#'){
		if(!In(c,OP)){
			Push(OPND,c-'0');c=getchar();//printf("-1-\n");
		}
		else
			switch(Precede(GetTop(OPTR),c)){
				case '<':
					Push(OPTR,c);c=getchar();//printf("-2-\n");
					break;
				case '=':
					Pop(OPTR,x);c=getchar();//printf("-3-\n");
					break;
				case '>':
					Pop(OPTR,theta);
					Pop(OPND,b);Pop(OPND,a);
					Push(OPND,Operate(a,theta,b));
					break;			
			}//switch
	}//while
	return GetTop(OPND);
}//EvalutExp

int main(){
	//end by '#'; 
	while(1){
		printf("result :%d\n",EvalutExp());
	}
	
}
