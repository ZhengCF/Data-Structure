#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int n, j, k;
	long long ii = 0, jj = 0, sum = 0, l;
	cin >> n;	
	for (int i = pow(10, n-1); i < pow(10, n); i++) {
		l = i;
		j = n;
		while (j) {
			k = l % 10;
			l /= 10;
			j--;
			if (k == 1 && ii == 0)
				ii = 1;
			else if (k == 0 && ii == 1)
				ii = 2;
			else if (k == 1 && ii == 2 || (k == 0 && ii == 0) || k > 3) {
				ii = 1;
				break;
			}
			else if (k == 3 && jj == 0)
				jj = 1;
			else if (k == 2 && jj == 1)
				jj = 2;
			else if ((k == 3 && jj == 2) || (k == 2 && jj == 0)) {
				jj = 1; break;
			}
		}
		if (ii == 2 && jj == 2) {
			sum++; 
			cout << i << endl; 
		}
		ii = 0; jj = 0;			
	}
	cout << sum << endl;
	return 0;
}