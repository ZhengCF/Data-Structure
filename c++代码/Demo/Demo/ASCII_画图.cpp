#include<iostream>
using namespace std;

const int MAXSIZE = 100;
char G[MAXSIZE][MAXSIZE];
int n, m, q;

void fill(int x, int y,char c) {
	if (G[y][x] != '-' && G[y][x] != '+' &&G[y][x] != '|' &&y < n&&x < m&&G[y][x] != c&& x>=0 && y>=0 ) {//
		fill(x + 1, y, c);
		fill(x, y + 1, c);
		fill(x, y - 1, c);
		fill(x - 1, y, c);
	}
}

int main() {
	int t,a,b;
	int x1, y1, x2, y2;
	char c;
	cin >> m >> n >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			G[i][j] = '.';
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 0) {
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2) {
				a = __min(y1, y2); b = __max(y1, y2);
				for (int k = a; k <= b; k++) {
					if (G[k][x1] == '-')
						G[k][x1] = '+';
					else
						G[k][x1] = '|';
				}
			}
			else
			{
				a = __min(x1, x2); b = __max(x1, x2);
				for (int k = a; k <= b; k++) {
					if (G[y1][k] == '|')
						G[y1][k] = '+';
					else
						G[y1][k] = '-';
				}
			}
			
		}
		else {
			cin >> x1 >> y1 >> c;
			a = x1; b = y1; fill(a, b, c);
			/*while (G[b][a] != '-' && G[b][a] != '+' &&G[b][a] != '|' &&b<n)
			{
				while (G[b][a] != '-' &&G[b][a] != '+' &&G[b][a] != '|'&&a<m) {
					G[b][a++] = c;
				}
				a = x1;
				b++;
			}*/
		}
	}
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < m; j++)
			cout << G[i][j];
		cout << endl;
	}
}