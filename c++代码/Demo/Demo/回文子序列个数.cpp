//对于任意字符串，如果头尾字符不相等，则字符串的回文子序列个数就等于
//去掉头的字符串的回文子序列个数 + 去掉尾的字符串的回文子序列个数 - 去掉头尾的字符串的回文子序列个数；
//如果头尾字符相等，那么除了上述的子序列个数之外，还要加上首尾相等时新增的子序列个数，1 + 去掉头尾的字符串的回文子序列个数，
//1指的是加上头尾组成的回文子序列，如aa，bb等
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
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
			else
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
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