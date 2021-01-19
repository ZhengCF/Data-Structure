#include<iostream>
#define MAXSIZE 100
using namespace std;

typedef struct {
	int   position;
	bool  direction;//1 right ;0 left
}ball;

int main() {
	int n, L, t, p;
	cin >> n;//С��ĸ�����
	cin >> L;//�߶εĳ��ȣ�
	cin >> t;//ʱ��
	ball b[MAXSIZE];
	for (int i = 0; i < n; i++) {
		cin >> p;//С���ʼλ��
		b[i].position = p;
		b[i].direction = 1;
	}
	while (t--)
	{
		for (int i = 0; i < n; i++) {
			if (!b[i].direction) {
				if (b[i].position - 1 == 0) {
					b[i].direction = 1;
					b[i].position = 0;
				}
				else
					b[i].position = b[i].position - 1;
			}
			else {
				if (b[i].position + 1 == L) {
					//�����Ҷ˵㣬ת�䷽��
					b[i].position = L;
					b[i].direction = 0;
				}
				else {
					b[i].position = b[i].position + 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (b[i].position == b[j].position) {
					b[i].direction = !b[i].direction;
					b[j].direction = !b[j].direction;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) 
		cout << b[i].position << '\t';
	return 0;
}