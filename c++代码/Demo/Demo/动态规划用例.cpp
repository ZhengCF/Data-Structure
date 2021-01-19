#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int fn[31];
	fn[0] = 0;
	fn[1] = 1;
	for (int i = 2; i <= n; i++) {
		fn[i] = fn[i - 1] + fn[i - 2];
	}
	cout << fn[n] << endl;
	return 0;
}