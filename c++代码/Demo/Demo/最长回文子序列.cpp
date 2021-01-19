#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int deal(string str) {
	int n = str.length();
	vector<vector<int> > dp(n, vector<int>(n));

	for (int i = n - 1; i >= 0; i--) {
		dp[i][i] = 1;
		for (int j = i + 1; j<n; j++) {
			if (str[i] == str[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	return dp[0][n - 1];
}

int main() {
	string s;
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	cout << deal(s) << endl;
	return 0;
}