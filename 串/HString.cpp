#include"basic.h"

typedef struct {
	char *ch;
	int length;
}HString;

Status StrInsert(HString &S,int pos,HString T){
	int i;
	if(pos<1||pos>S.length+1)
		return ERROR;
	if(T.length){
		if(!(S.ch=(char*)realloc(S.ch,(S.length+T.length)*sizeof(char))))
			exit(OVERFLOW);
		for(i=S.length-1;i>=pos-1;--i)
			S.ch[i+T.length]=S.ch[i];
		S.ch[pos-1..pos+T.length-2]=T.ch[0..T.length-1];
		S.length+=T.length;
	}
	return OK;
} //StrInsert

Status StrAssign(HString &T,char *chars){
	char *c;
	int i;
	if(T.ch) free(T.ch);
	for(i=0,c=chars;*c;++i,++c);
	if(!i){
		T.ch=NULL;T.length=0;
	}
	else{
		if(!(T.ch=(char*)malloc(i*sizeof(char))))
			exit(OVERFLOW);
		T.ch[0..i-1]=chars[0..i-1];
		T.length=i;
	}
	return OK;
} //StrAssign

int StrLength(HString S){
	return S.length;
} //StrLength

int StrCompare(HString S,HString T){
	int i;
	for(i=0;i<S.length&&i<T.length;++i)
		if(S.ch[i]!=T.ch[i]) return S.ch[i]-T.ch[i];
	return S.length-T.length;
}//StrCompare

Status ClearString(HString &S){
	if(S.ch){
		free(S.ch);S.ch=NULL;
	}
	S.length=0;
} //ClearString

Status Concat(HString &T,HString S1,HString S2){
	if(T.ch) free(T.ch);
	if(!(T.ch=(char*)malloc((S1.length+S2.length)*sizeof(char))))
		exit(OVERFLOW);
	T.ch[0..S1.length-1]=S1.ch[0..S1.length-1];
	T.length=S1.length+S2.length;
	T.ch[S1.length..T.length-1]=S2.ch[0..S2.length-1];
	return OK;
} //Concat

Status SubString(HString &Sub,HString S,int pos,int len){
	if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
		return ERROR;
	if(Sub.ch) free(Sub.ch);
	if(!len) {
		S.ch=NULL;S.length=0;
	}
	else{
		Sub.ch=(char*)malloc(len*sizeof(char));
		Sub.ch[0..len-1]=S.ch[pos-1..pos+len-2];
		Sub.length=len;
	}
	return OK;
} //SubString
