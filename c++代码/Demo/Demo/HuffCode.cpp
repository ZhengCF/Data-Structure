#include<string>
#include<iostream>
using namespace std;

typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;//动态分配数组存储哈夫曼树

typedef string HuffmanCode;//动态分配数组存储哈夫曼编码表

HuffmanTree HT;
HuffmanCode HC[10];

int max(int s1, int s2) {
	if ((HT + s1)->weight >= (HT + s2)->weight)
		return s1;
	else
		return s2;
}

void Select(int i, int &s1, int &s2) {
	HuffmanTree p = HT;
	int j,f=1;
	unsigned n;
	for (j = 0; f < 3; j++) {
		if ((p + j)->parent == 0 && f == 1) {
			s1 = j; f++; //cout << s1+1 << "   ";
		}
		else if ((p + j)->parent == 0 && f == 2) {
			s2 = j; f++; //cout << s2+1 << "   ";
		}
	}
	for (; j < i; j++) {
		n = max(s1, s2);
		if (((p + j)->parent == 0)&&((p + j)->weight < (p+n)->weight)) {
			if (n == s1) 
				s1 = j;
			else
				s2 = j; 
		}
	}//cout << endl;
}

void HuffmanCoding(unsigned *w, int n) {
	//w存放n个字符的权值，构造哈夫曼树HT，并求出n个字符的哈夫曼编码HC；
	int m, i;      //m:结点个数
	int s1, s2;
	HuffmanCode cd;    //工作空间
	unsigned int c, f;
	HuffmanTree p;
	if (n <= 1)return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//0号单元不用
	for (p = HT+1, i = 1; i <= n; ++i, ++p, ++w) *p = { *w,0,0,0 };
	for (; i <= m; ++i, ++p) *p = { 0,0,0,0 };
	for (i = n + 1; i <= m; ++i) {
		//建哈夫曼树
		//在HT[1..i-1]选择parent为0 ，且weight最小的两个节点，其序号分别为s1,s2.
		Select(i - 1, s1, s2); //cout << s1+1 << "  " << s2+1 << endl;
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	//---从叶子到根逆向求每个字符的哈夫曼编码---
	for (i = 1; i <= n; ++i) {//逐个字符求哈夫曼编码
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{//从叶子到根逆向求编码
			if (HT[f].lchild == c) cd.append("0");
			else cd.append("1");
		}
		reverse(cd.begin(), cd.end());
		HC[i] = cd;//从cd复制编码到HC
		cd.clear();
	}
}//HuffmanCoding

int main() {
	const int n = 5;
	int s = 0;
	unsigned w[n] = { 1,3,4,2,5 };
	HuffmanCoding(w, n); 
	for (int i = 1; i <= n; ++i)
		cout << HC[i] << endl;
	for (int i = 1; i <= n; ++i)
		s += HC[i].size()*w[i-1];
	cout << s << endl;
}

	/*for (i = 1; i <= m; ++i) {
		cout << HT[i].weight << "  " << HT[i].parent<<"  "<<HT[i].lchild<<"  "<<HT[i].rchild << endl;
	}*/