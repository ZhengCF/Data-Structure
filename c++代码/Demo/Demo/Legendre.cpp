#include"iostream"
#include"iomanip"
using namespace std;

int lege(int x, int n) {
	if (n == 0) return 1;
	else if (n == 1) return x;
	else {
		x = ((2 * n - 1)*x*lege(x, n - 1) - (n - 1)*lege(x, n - 2)) / n;
		return x;
	}
}
int main() {
	for (int n = 0; n < 5; n++) {
		for (int x = 0; x < 10; x++)
			cout << lege(x, n) << " ";
		cout << endl;
	}
}