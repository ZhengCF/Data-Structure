#include"HString.cpp"
#define MaxBookNum 1000
#define MaxKeyNum  2500
#define MaxLineLen 500
#define MaxWordNum 10

typedef struct {
	char *item[];      
	int last;         //�ʱ��� 
}WordListType;       //�ʱ����� 

typedef int ElemType; //���������Ԫ������Ϊint 

typedef struct {
	HString key;     //�ؼ��� 
	LinkList bnolist;//�����Ŀ���������� 
}IdxTermType;        //���������� 

typedef struct {
	IdxTermType item[MaxKeyNum+1];
	int last;
}IdxListType;       //���������� 

char *buff;         //��Ŀ������ 
WordListType wdlist;//�ʱ� 