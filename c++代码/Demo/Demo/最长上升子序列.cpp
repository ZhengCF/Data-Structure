#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, a[10000], dp[10000];
	int max = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		max = dp[i];
	}
	cout << max << endl;
	return 0;
}