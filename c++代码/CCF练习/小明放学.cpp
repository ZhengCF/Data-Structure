//10^6 int ����
#include<iostream>
using namespace std;
int main() {
	int r, y, g, n, k, t, sum = 0, c;
	cin >> r >> y >> g;
	cin >> n;
	while (n--) {
		cin >> k >> t;
		if (sum - t > 0) {
			c = (sum - t) % (r + y + g);//���ڲ�ֵ
			if (k == 0) {
				sum += t;
			}
			else if (k == 1) {//��
				if (c > g)
					sum += r + y - c;
			}
			else if (k == 2) {//��
				if (c < r)
					sum += r - c;
				else if (c > g + r) {
					sum += r + g + y - c + r;
				}
			}
			else if (k == 3) {//��
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