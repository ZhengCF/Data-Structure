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
}HTNode,*HuffmanTree;//��̬��������洢��������

typedef char **HuffmanCode;//��̬��������洢�����������

void Select(HuffmanTree HT, int i, int s1,int s2){}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n){
	//w���n���ַ���Ȩֵ�������������HT�������n���ַ��Ĺ���������HC��
	int m,i;      //m:������
	int s1, s2;
	char * cd;    //�����ռ�
	int start;    //���������λ��
	unsigned int c, f;
	HuffmanTree p;
	if (n <= 1)return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1)*sizeof(HTNode));//0�ŵ�Ԫ����
	for (p = HT, i = 1; i <= n; ++i, ++p, ++w) *p = { *w,0,0,0 };
	for (; i <= m; ++i, ++p) *p = { 0,0,0,0 };
	for (i = n + 1; i <= m; ++i) {
		//����������
		//��HT[i..i-1]ѡ��parentΪ0 ����weight��С�������ڵ㣬����ŷֱ�Ϊs1,s2.
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	//---��Ҷ�ӵ���������ÿ���ַ��Ĺ���������---
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));//����n���ַ�����ͷָ������
	cd = (char*)malloc(n*sizeof(char));//���������Ĺ����ռ�
	cd[n - 1] = '\0';//���������
	for (i = 1; i <= n; ++i) {//����ַ������������
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)//��Ҷ�ӵ������������
			if (HT[f].lchild == c) cd[--start] = '0';
			else cd[--start] = '1';
		HC[i] = (char*)malloc((n - start) * sizeof(char));//Ϊ��i���ַ��������ռ�
		strcpy(HC[i], &cd[start]);//��cd���Ʊ��뵽HC
	}
	free(cd);
}//HuffmanCoding
