#include"head.h" 

Status IniteStack(Sqstack &S){
	S.base=(char *)malloc(100*sizeof(char));
	if(!S.base) exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=100;
	return 0;
} //IniteStack

Status GetTop(Sqstack S){
	char e;
	if(S.base==S.top) return ERROR; 
	e=*(S.top-1);
	return e;
} //GetTop

Status Push(Sqstack &S,char e){
	if(S.top-S.base==S.stacksize){
		S.base=(char *)realloc(S.base,(S.stacksize+10)*sizeof(char));
		if(!S.base) exit(OVERFLOW);
		S.top=S.base+S.stacksize;
		S.stacksize+=10;
	}
	*S.top++=e;
	return OK;
} //Push

Status Pop(Sqstack &S,char &e){
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return OK;
} //Pop
