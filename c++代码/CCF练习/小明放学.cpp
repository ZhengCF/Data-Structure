//10^6 int 不够
#include<iostream>
using namespace std;
int main() {
	int r, y, g, n, k, t, sum = 0, c;
	cin >> r >> y >> g;
	cin >> n;
	while (n--) {
		cin >> k >> t;
		if (sum - t > 0) {
			c = (sum - t) % (r + y + g);//周期差值
			if (k == 0) {
				sum += t;
			}
			else if (k == 1) {//红
				if (c > g)
					sum += r + y - c;
			}
			else if (k == 2) {//黄
				if (c < r)
					sum += r - c;
				else if (c > g + r) {
					sum += r + g + y - c + r;
				}
			}
			else if (k == 3) {//绿
				if (c < r + y) {
					sum += r + y - c;
				}
			}
		}
		else {
			if (k == 0 || k == 1 || k == 2)
				sum += t;
		}
	}
	cout << sum << endl;
	return 0;
}