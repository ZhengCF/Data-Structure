#include<iostream>
using namespace std;
int main() {
	int n, ii, jj;
	int vex[100][2];
	float path[100][100], sum, min;
	bool flag[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> vex[i][0] >> vex[i][1];
		flag[i] = false;
	}
	min = 200000;
	for (int i = 0; i < n; i++) {//转换路径矩阵
		for (int j = i; j < n; j++) {
			if (i == j)
				path[i][j] = 0;
			else {
				path[i][j] = path[j][i] = sqrt(pow(vex[i][0] - vex[j][0], 2) + pow(vex[i][1] - vex[j][1], 2));
				if (min > path[i][j]) {
					min = path[i][j];
					ii = i; jj = j;
				}
			}
		}
	}
	sum = min;
	flag[ii] = true; flag[jj] = true;//进入树的集合
	for (int j = 2; j < n; j++) {
		int a, b;
		float min0 = 200000;
		min = 200000;
		for (int i = 0; i < n; i++) {
			if (!flag[i] && path[ii][i] < min) {
				min = path[ii][i];
				a = i;
			}
		}
		for (int i = 0; i < n; i++) {
			if (!flag[i] && path[jj][i] < min) {
				min0 = path[jj][i];
				b = i;
			}
		}
		if (min < min0) {
			ii = a;
			sum += min;
			flag[ii] = true;
		}
		else {
			jj = b;
			sum += min0;
			flag[jj] = true;
		}
	}
	printf("%.2f\n", sum);
	return 0;
}
//4
//0 0
//100 0
//0 1
//100 1