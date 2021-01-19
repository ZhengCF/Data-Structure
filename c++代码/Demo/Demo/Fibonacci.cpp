#include"iostream"
#include"iomanip"
using namespace std;

int fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		n = fib(n - 1) + fib(n - 2);
		//cout << n << setw(2);
		return n;
	}
}

int main() {
	const int n = 20;
	for (int i = 1; i < n; i++)
		cout << fib(i) << " ";
	return 0;
}
