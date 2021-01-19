#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 
typedef int Status;
typedef int TElemType;
typedef int ElemType;

typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode,*HuffmanTree;//动态分配数组存储哈夫曼树

typedef char **HuffmanCode;//动态分配数组存储哈夫曼编码表

void Select(HuffmanTree HT, int i, int s1,int s2){}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n){
	//w存放n个字符的权值，构造哈夫曼树HT，并求出n个字符的哈夫曼编码HC；
	int m,i;      //m:结点个数
	int s1, s2;
	char * cd;    //工作空间
	int start;    //编码结束符位置
	unsigned int c, f;
	HuffmanTree p;
	if (n <= 1)return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1)*sizeof(HTNode));//0号单元不用
	for (p = HT, i = 1; i <= n; ++i, ++p, ++w) *p = { *w,0,0,0 };
	for (; i <= m; ++i, ++p) *p = { 0,0,0,0 };
	for (i = n + 1; i <= m; ++i) {
		//建哈夫曼树
		//在HT[i..i-1]选择parent为0 ，且weight最小的两个节点，其序号分别为s1,s2.
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	//---从叶子到根逆向求每个字符的哈夫曼编码---
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));//分配n个字符编码头指针向量
	cd = (char*)malloc(n*sizeof(char));//分配求编码的工作空间
	cd[n - 1] = '\0';//编码结束符
	for (i = 1; i <= n; ++i) {//逐个字符求哈夫曼编码
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)//从叶子到根逆向求编码
			if (HT[f].lchild == c) cd[--start] = '0';
			else cd[--start] = '1';
		HC[i] = (char*)malloc((n - start) * sizeof(char));//为第i个字符编码分配空间
		strcpy(HC[i], &cd[start]);//从cd复制编码到HC
	}
	free(cd);
}//HuffmanCoding
