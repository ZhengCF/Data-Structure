#include"basic.h"
#define MAXSIZE 12500
#define MAXRC 12500

typedef int ElemType;
 
typedef struct {
	int i,j;
	ElemType e;
} Triple;

typedef struct {
	Triple data[MAXSIZE+1];
	int rpos[MAXRC+1];      //各行第一个非零元的位置表 
	int mu,nu,tu;
}RlSMatrix;

Status MultSMatrix(RlSMatrix M,RlSMatrix N,RlSMatrix &Q){
	//
	int ctemp[MAXSIZE];
	int arow,tp,t,p,q,brow,ccol;
	if(M.nu!=N.mu) return ERROR;
	Q.mu=M.mu;Q.nu=N.nu;Q.tu=0;
	if(M.tu*N.tu!=0){
		for(arow=1;arow<=M.mu;++arow){
			ctemp[ccol]=0;
			Q.rpos[arow]=Q.tu+1;
			if(arow<M.mu)
				tp=M.rpos[arow+1];
			else 
				tp=M.tu+1;
			for(p=N.rpos[arow];p<tp;++p)
			{
				brow=M.data[p].j;
				if(brow<N.mu) 
					t=N.rpos[arow+1];
				else 
					t=N.tu+1;
				for(q=N.rpos[arow];q<tp;++q)
				{
					ccol=N.data[q].j;       //乘积元素在Q中的列号 
					ctemp[ccol]+=M.data[p].e*N.data[q].e;
				}
			}//求得Q中第crow( =arow)行的非零元 
			for(ccol=1;ccol<=Q.nu;++ccol)
				if(ctemp[ccol]){
					if(++Q.tu>MAXSIZE) return ERROR;
					Q.data[Q.tu].i=arow;
					Q.data[Q.tu].j=ccol;
					Q.data[Q.tu].e=ctemp[ccol];
				}//if
		}//for
	}//if
	return OK;
}//MultSMatrix
