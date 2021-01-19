#include"HString.cpp"
#define MaxBookNum 1000
#define MaxKeyNum  2500
#define MaxLineLen 500
#define MaxWordNum 10

typedef struct {
	char *item[];      
	int last;         //词表长度 
}WordListType;       //词表类型 

typedef int ElemType; //链表的数据元素类型为int 

typedef struct {
	HString key;     //关键词 
	LinkList bnolist;//存放数目索引的链表 
}IdxTermType;        //索引项类型 

typedef struct {
	IdxTermType item[MaxKeyNum+1];
	int last;
}IdxListType;       //索引表类型 

char *buff;         //数目缓冲区 
WordListType wdlist;//词表 