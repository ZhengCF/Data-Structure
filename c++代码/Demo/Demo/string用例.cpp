#include<iostream>
#include<string>
using namespace std;

int n;

string deal(string s,int &e) {
	int k=0;                          //s���±�
	while (s.length() > 0 && s[0] == 0)
		s.erase(s.begin());           //ȥ��ǰ����
	if (s[0] == '.') {                //Ϊ0.�������
		s.erase(s.begin());           //ȥ��С����
		while (s.length() > 0 && s[0] == 0) {
			s.erase(s.begin());       //ȥ��С��������λǰ��������
			e--;                      //ÿȥ��һ���㣬ָ��e��1
		}
	}
	else {                            //Ϊ��.�������
		while (s.length() > k && s[k] != '.') {
			k++;                      
			e++;                      //ָ��e��1
		}
		if (k < s.length())           //˵����С����
			s.erase(s.begin() + k);   //ɾ��С����
	}
	if (s.length() == 0)
		e = 0;
	int num = 0;
	k = 0;
	string res;
	while (num < n) {
		if (k < s.length()) res += s[k++];
		else res += '0';
		num++;
	}
	return res;
}

int main() {
	string s1, s2, s3, s4;
	cin >> n >> s1 >> s2;
	int e1 = 0, e2 = 0;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	if (s3 == s4 && e1 == e2)
		cout << "YES 0." << s3 << "*10^" << e1 << endl;
	else
		cout << "NO 0." << s3 << "*10^" << " 0." << s4 << "*10^" << e2 << endl;
	return 0;
}