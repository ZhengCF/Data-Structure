#include<iostream>
using namespace std;
int main() {
	int c, x, C[100000], sum = 0, xx = 0;
	cin >> c >> x;
	for (int i = 0; i < c; i++)
		cin >> C[i];
	for (int i = 0; i < c; i++)
		for (int j = i; j < c; j++) {
			sum += C[j];
			if (sum >= x)
				xx++;
		}
	cout << xx<<endl;
	return 0;
}