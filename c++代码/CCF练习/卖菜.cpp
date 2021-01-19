#include<iostream>
using namespace std;
int main() {
	int n, nn;
	cin >> n;
	int shops[1000], sshops[1000];
	for (int i = 0; i < n; i++) {
		cin >> nn;
		shops[i] = nn;
	}
	sshops[0] = (shops[0] + shops[1]) / 2; cout << sshops[0] << " ";
	for (int i = 1; i < n - 1; i++) {
		sshops[i] = (shops[i - 1] + shops[i] + shops[i + 1]) / 3;
		cout << sshops[i] << " ";
	}
	sshops[n-1] = (shops[n-1] + shops[n-2]) / 2;
	cout << sshops[n-1] << " " << endl;
	return 0;
}