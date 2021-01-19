//#include<iomanip>
//cout << fixed << setprecision(2);  //保留两位小数
//最后一个例子有问题
#include<iostream>
#include<string>
#include<stack>
using namespace std;

const int MAXSIZE = 26;
char name[MAXSIZE];
int sz[MAXSIZE][2];
int m;

int calculate(string ss) {
	//string::iterator i;
	stack<int*> ma;
	int a[2], b[2],c[2];
	int result = 0;
	if (ss.size() == 1) {
		for (int j = 0; j < m; j++)
			if (name[j] == ss.at(0)) {
				result = 0;
				break;
			}
	}
	else {
		for (int i = 0; i<ss.size(); i++) {
			if (ss.at(i) != '('&&ss.at(i) != ')') {
				for (int j = 0; j < m; j++) 
					if (name[j] == ss.at(i)) {
						ma.push(sz[j]);
						break;
					}			
			}
			else if (ss.at(i) == ')') {
				b[0] = ma.top()[0];
				b[1] = ma.top()[1];
				ma.pop();
				a[0] = ma.top()[0]; 
				a[1] = ma.top()[1];
				cout << '(' << a[0] << ',' << a[1] << ')' << '(' << b[0] << ',' << b[1] << ')' << endl;
				ma.pop();
				if (a[1] == b[0]) {
					result += a[0] * b[1] * b[0];
					c[0] = a[0]; c[1] = b[1];
					ma.push(c);
				}					
				else {
					result = -1;
					break;
				}
			}
		}
	}
	return result;
}

int main() {
	string s;
	cin >> m;
	int r;
	for (int i = 0; i < m; i++)
		cin >> name[i] >> sz[i][0] >> sz[i][1];
	while (1)
	{
		cin >> s;
		r = calculate(s);
		if (r < 0)
			cout << "ERROR" << endl;
		else
			cout << r << endl;
	}
}