//逻辑混乱，代码冗余
//有时间推掉重写

#include<iostream>
#include<string>
using namespace std;
const int MAXSIZE = 100;
int n, m;//匹配规则数，待匹配地址数
string rule[MAXSIZE], out_s[MAXSIZE], ss[MAXSIZE];

void match(string ss) {
	if (ss.at(1) == 's') {
		//static
		ss = ss.substr(8, ss.size()-1);
		for (int i = 0; i < n; i++) {
			if (rule[i].at(1) == 's') {
				cout << out_s[i] << " ";
				cout << ss << endl;
				break;
			}
		}
	}
	else if (ss.at(1) == 'a') {
		//articles
		ss = ss.substr(10, ss.size() - 1);
		if (isdigit(ss.at(0))&&(ss.at(ss.size()-1)=='/')) {
			ss.erase(ss.size() - 1);
			if (ss == "2003") {
				for (int i = 0; i < n; i++) {
					if (rule[i].at(10) == '2') {
						cout << out_s[i] << endl;
						break;
					}
				}
			}
		}
		else
			cout << "404" << endl;
		for (int i = 0; i < n; i++) {
			if (rule[i].at(1) == 'a') {

			}
		}
	}
}

int main() {	
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> rule[i] >> out_s[i];
	for (int i = 0; i < m; i++) {
		cin >> ss[i];
		match(ss[i]);
	}
}
