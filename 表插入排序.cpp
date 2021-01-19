#include<iostream>
using namespace std;
#define SIZE 100
typedef struct {
	int rc; //记录项类型
	int next;//指针
}SLNode;

typedef struct {
	SLNode r[SIZE];//表，r【0】为表头
	int length;
}SLinkList;

int b[8] = { 49,39,65,97,76,13,27,69 };

void SLInsertSort(SLinkList &L) {
	int min, max;

	cout << "原序列" << endl;
	for (int i = 1; i < 9; i++) {
		L.r[i].rc = b[i - 1];
		cout << L.r[i].rc << '\t';
	}
	cout << endl;

	L.r[0].rc = 100;
	L.r[0].next = 1;
	L.r[1].next = 0;  //初循环
	min = max = 1;
	for (int i = 2; i < 9; i++) {
		if (L.r[i].rc <= L.r[min].rc)
		{
			L.r[i].next = L.r[0].next;
			L.r[0].next = i;
			min = i;
		}
		else if (L.r[i].rc >= L.r[max].rc)
		{
			L.r[max].next = i;
			L.r[i].next = 0;
			max = i;
		}
		else
		{
			int index1 = min, index2;
			while (L.r[i].rc >= L.r[index1].rc) {
				index2 = index1;
				index1 = L.r[index1].next;
			}
			L.r[i].next = index1;
			L.r[index2].next = i;
		}
	}
	cout << "表插入排序结果如下" << endl;
	int j = L.r[0].next;
	while (j) {
		cout << L.r[j].rc << '\t';
		j = L.r[j].next;
	}
	cout << endl;	
}
int main() {
	SLinkList L; 
	SLInsertSort(L);
}