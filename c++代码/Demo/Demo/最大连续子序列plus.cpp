#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int k, n[10000], dp[10000], d[10000][2];
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> n[i];
	dp[0] = n[0];
	for (int i = 1; i < k; i++) {
		dp[i] = max(n[i], dp[i - 1] + n[i]);
		if (n[i] >= dp[i - 1] + n[i]) {
			d[i][0] = d[i][1] = n[i];
		}
		else {
			d[i][1] = n[i];
			d[i][0] = d[i - 1][0];
		}
	}
	int j = 0;
	for (int i = 0; i < k; i++) {
		if (dp[j] < dp[i])
			j = i;
	}
	if (dp[j] > 0)
		cout << dp[j] << " " << d[j][0] << " " << d[j][1] << endl;
	else
		cout << 0 << " " << n[0] << " " << n[k-1] << endl;
	return 0;
}