#include"iostream"
using namespace std;

int GetPower(int x, int y) {
	if (y == 1) return x;
	else if (y == 0) {
		if (x == 0) return 0;
		else return 1;
	}
	else {
		return x * GetPower(x, y - 1);
	}
}
int main() {
	int x, y;
	do {
		cin >> x >> y;
		cout << GetPower(x, y) << endl;
	} while (x != 0 || y != 0);
	return 0;
}