#include"basic.h"
#define MAXSTRLEN   255
typedef unsigned char SString[MAXSTRLEN+1];

Status Concat(SString &T,SString S1,SString S2){
	if(S1[0]+S2[0]<=MAXSTRLEN){
		//T[1..S1[0]]=S1[1..S1[0]];
	}
	else if(S1[0]<MAXSTRLEN){
		
	}
	else{
		
	}
}

Status SubString(SString &Sub,SString S,int pos,int len){
	if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
		return ERROR;
	//Sub[1..len]=S[pos..pos+len-1];
	Sub[0]=len;
	return OK;
}

int Index(SString S,SString T,int pos){
	int i,j;
	i=pos;
	j=1;
	while(i<=S[0]&&j<=T[0]){
		if(S[i]==T[j]){
			++i;++j;
		}
		else{
			i=i+1-(j-1);j=1;
		}
	}
	if(j>T[0]) return i-T[0];
	else return ERROR;
} //Index

/*
int IndexKMP(SString S,SString T,int pos){
	int i,j;
	i=pos;
	j=1;
	while(i<=S[0]&&j<=T[0]){
		if(S[i]==T[j]){
			++i;++j;
		}
		else{
			j=next[j];      //KMP
		}
	}
	if(j>T[0]) return i-T[0];
	else return ERROR;
} //IndexKMP*/


void get_next(SString T,int next[]){
	int i=1;
	next[1]=0;
	int j=0;
	while(i<5){
		if(j==0||T[i]==T[j]){
			++i;++j;next[i]=j;
		}
		else j=next[j];
	}
}

void get_nextval(SString T,int nextval[]){
	int i=1;
	nextval[1]=0;
	int j=0;
	printf("%d\n",T[0]);
	while(i<5){
		if(j==0||T[i]==T[j]){
			++i;++j;
			if(T[i]!=T[j]) nextval[i]=j;
			else nextval[i]=nextval[j];
		}
		else j=nextval[j];
	}
}


int main(){
	SString T="5aaaab";	
	int next[6];
	int nextval[6];
	get_next(T,next);
	get_nextval(T,nextval);
	int i=1;
	printf("%d\n",T[0]);
	while(i<6){
		printf("%d ",next[i++]);
	}
	printf("\n");
	i=1;
	while(i<6){
		printf("%d ",nextval[i++]);
	}
	printf("\n");
} 