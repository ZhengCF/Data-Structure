#include<iostream>
#include<string>
using namespace std;

bool deal(string &s,int e) {
	bool flag;
	int k = 0;
	while (s.length() > 0 && s[0] == '0')
		s.erase(s.begin());                      //去掉前导零
	if (s.length() < k)                          //字符串为0
		e = 0;
	if (s.length() > k&&s[k] != '.') {           //?.?或？的情况
		while (s[k] != '.' && s[k] != *s.end()) {
			k++;
			e++;                                 //指数+1
		}
		if (s[k] == '.') {
			s.erase(s.begin() + k);              //删除小数点
			flag = 1;
			while (s[k] != *s.end() && s[k] != 'e' && s[k] != 'E')//小数或科学计数的形式
			{

			}
		}
		else 
			return flag;					     //整数的情况
	}
	return flag;
}

int main() {
	int f1, f2, e1, e2;
	string s1, s2;
	f1 = deal(s1, e1);
	f2 = deal(s2, e2);
	if (f1 == 1 || f2 == 1) {//科学计数的情况

	}
	else                     //整数情况


}