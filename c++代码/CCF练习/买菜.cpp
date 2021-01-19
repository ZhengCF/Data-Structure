#include<iostream>
using namespace std;
int main() {
	int n, a[2000][2], b[2000][2], k = 0, j = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1];
	for (int i = 0; i < n; i++)
		cin >> b[i][0] >> b[i][1];
	while (k<n&&j<n)
	{
		if (a[k][0] >= b[j][1])
			j++;
		else if (a[k][1] <= b[j][0])
			k++;
		else {
			sum += (a[k][1] > b[j][1] ? b[j][1] : a[k][1])-(a[k][0] > b[j][0] ? a[k][0] : b[j][0]);
			k++; j++;
		}
	}
	cout << sum << endl;
	return 0;
}