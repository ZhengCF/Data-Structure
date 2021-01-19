#include<iostream>
#include<string>
using namespace std;
int main() {
	string s[100];
	int times, n, k, j;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int l = 0; l < n; l++) {
		k = 0; j = 1; times = 0;
		for (int i = 1; i < s[l].length(); i++) {
			if (s[l].at(i) == s[l].at(k)) {
				j++;
			}
			else {				
				if (times < j)
					times = j;
				j = 1;
				k = i;
			}
			if (i == j - 1)
				times = j;
		}
		cout << times << endl;
	}
	return 0;
}
//3
//aaaabbcdhhh
//ifdhshfdaasdiahsd
//eeeeeee