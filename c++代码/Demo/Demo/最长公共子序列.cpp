#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int dp[10000][10000];
	string a, b;
	while (1) {
		cin >> a;
		cin >> b;
		for (int i = 0; i < a.size(); i++)
			dp[i][0] = 0;
		for (int j = 0; j < b.size(); j++)
			dp[0][j] = 0;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				if (a[i] == b[j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[a.size()][b.size()] << endl;
	}return 0;
}