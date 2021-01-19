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
	int rpos[MAXRC+1];      //���е�һ������Ԫ��λ�ñ� 
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
					ccol=N.data[q].j;       //�˻�Ԫ����Q�е��к� 
					ctemp[ccol]+=M.data[p].e*N.data[q].e;
				}
			}//���Q�е�crow( =arow)�еķ���Ԫ 
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
