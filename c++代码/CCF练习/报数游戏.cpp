#include<iostream>
using namespace std;
#define MAX 100
int main() {
	int n,k,rest=0,a[100],sum=0;
	cin >> n;//����
	cin >> k;//����
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
	while (rest!=n-1) {
		for (int i = 0; i < n; i++) {			
			if (a[i] >= 0) {
				sum++;
				if (sum % k == 0) {
					a[i] = -1;//��̭
					rest++;
				}
				else
				{
					a[i]=sum;
				}
			}			
		}		
	}
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			cout << i+1 << endl;	
	return 0;
}
