//排序dulsort()还不够完善
//逻辑不够简单
#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int data[2];
	int next;
}TNode;//TNode

typedef struct {
	TNode t[100];
	int length;
}Table;//next 取时间降序

typedef struct {
	int key;
	int state;
	int time;
}node;

Table ta,tb;
int N, K;
int n[100];//key box
queue<node> ev;

void dulSort(Table &t) {
	int max, min;
	//next 取时间降序
	t.t[0].next = 1;
	t.t[1].next = 0;  
	min = max = 1;
	for (int i = 2; i <= K; i++) {
		if (t.t[i].data[1] <= t.t[min].data[1])
		{
			t.t[i].next = min;
			min = i;
		}
		else if (t.t[i].data[1] >= t.t[max].data[1])
		{
			t.t[max].next = i;
			t.t[i].next = 0;
			max = i;
		}
		else
		{
			int index1 = min, index2;
			while (t.t[i].data[1] >= t.t[index1].data[1]) {
				index2 = index1;
				index1 = t.t[index1].next;
			}
			t.t[i].next = index1;
			t.t[index2].next = i;
		}
	}
	t.t[0].next = min;
}

void enQueue() {
	node nod;
	int p = ta.t[0].next;
	int q = tb.t[0].next;
	while (p||q)
	{
		if (p != 0 && ta.t[p].data[1] < tb.t[q].data[1]) 
		{//fist give back,then take out			
			nod.key = ta.t[p].data[0];
			nod.state = 0;//take out
			nod.time = ta.t[p].data[1];
			ev.push(nod);
			p = ta.t[p].next;// cout << p << endl;
		}
		else {
			nod.key = tb.t[q].data[0];
			nod.state = 1;//give back
			nod.time = tb.t[q].data[1];
			ev.push(nod);
			q = tb.t[q].next;
		//cout << q<<endl;
		}
	}
}

void dealQu() {
	node nd;
	while (!ev.empty())
	{
		nd = ev.front(); //cout << nd.key << endl;
		if (nd.state == 0)//take out  
			for (int i = 0; i < N; i++) {
				if (n[i] == nd.key)
					n[i] = -1;//no key
			}
		else {
			for (int i = 0; i < N; i++) {
				if (n[i] == -1) {
					n[i] = nd.key;//give back
					break;
				}
			}
		}
		ev.pop();
	}
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		cin >> ta.t[i].data[0];
		tb.t[i].data[0] = ta.t[i].data[0];
		cin >> ta.t[i].data[1];
		cin >> tb.t[i].data[1];
		tb.t[i].data[1] = ta.t[i].data[1] + tb.t[i].data[1];
	}
	for (int i = 0; i < N; i++)//初始化钥匙盒
		n[i] = i+1;

	dulSort(ta);
	dulSort(tb);
	enQueue();
	dealQu();

	for (int i = 0; i < N; i++)
		cout << n[i] << "  ";
	cout << endl;
}
/*int j = ta.t[0].next;	
	while (j) { 
		cout << ta.t[j].data[1] << '\t';
		j = ta.t[j].next;
	}
	cout << endl;
*/
//cout << "-------------";
