#include<iostream>
using namespace std;
int main() {
	int r, y, g, n, k, t, sum = 0;
	cin >> r >> y >> g;
	cin >> n;
	while (n--) {
		cin >> k >> t;
		if (k == 0||k == 1) {
			sum += t;
		}
		else if (k == 2) {
			sum += t + r;
		}
	}
	cout << sum << endl;
	return 0;
}