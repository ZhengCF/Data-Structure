#include<iostream>
#include<string>
using namespace std;

bool deal(string &s,int e) {
	bool flag;
	int k = 0;
	while (s.length() > 0 && s[0] == '0')
		s.erase(s.begin());                      //ȥ��ǰ����
	if (s.length() < k)                          //�ַ���Ϊ0
		e = 0;
	if (s.length() > k&&s[k] != '.') {           //?.?�򣿵����
		while (s[k] != '.' && s[k] != *s.end()) {
			k++;
			e++;                                 //ָ��+1
		}
		if (s[k] == '.') {
			s.erase(s.begin() + k);              //ɾ��С����
			flag = 1;
			while (s[k] != *s.end() && s[k] != 'e' && s[k] != 'E')//С�����ѧ��������ʽ
			{

			}
		}
		else 
			return flag;					     //���������
	}
	return flag;
}

int main() {
	int f1, f2, e1, e2;
	string s1, s2;
	f1 = deal(s1, e1);
	f2 = deal(s2, e2);
	if (f1 == 1 || f2 == 1) {//��ѧ���������

	}
	else                     //�������


}