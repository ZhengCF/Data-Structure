#include<iostream>
#include<vector>
using namespace std;

void dtob(int n) {
	vector<bool> a;
	while (n) {
		a.insert(a.begin(), n % 2);
		n /= 2;
	}
	for (int i = 0; i < a.size(); i++)
		cout << a.at(i);
	cout << endl;
}

void dtoo(int n) {
	vector<int> a;
	while (n) {
		a.insert(a.begin(), n % 8);
		n /= 8;
	}
	for (int i = 0; i < a.size(); i++)
		cout << a.at(i);
	cout << endl;
}

void dtoh(int n) {
	char s[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	vector<char> a;
	while (n)
	{
		a.insert(a.begin(), s[n % 16]);
		n /= 16;
	}
	for (int i = 0; i < a.size(); i++)
		cout << a.at(i);
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	dtob(n);
	dtoo(n);
	dtoh(n);
	return 0;
}