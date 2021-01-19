#include"iostream"
using namespace std;

int nadd(int n) {
	if (n == 1) return 1;
	else {
		n += nadd(n - 1);
		return n;
	}
}

int main() {
	
	cout<< nadd(10)<<endl;
}