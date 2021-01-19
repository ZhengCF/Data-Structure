#include<iostream>
#include<string>
using namespace std;

const int MAXSZIE = 100;
string str;
string s[MAXSZIE][2], r[MAXSZIE];
string obj[MAXSZIE][2];
int n, m;

void dealStr(string &str) {
	string::iterator i;
	str.erase(0, 1);
	str.pop_back();
	for (i = str.begin(); i != str.end(); i++) {
		if (*i == '\\' || *i == '"')//
			str.erase(i);
	}
	//cout << str << endl;
}

void research(string *s,int x) {
	bool j = 0;
	for (int i = 0; i < n; i++) {
		if (obj[i][0] == s[0]) {
			if (obj[i][1] == "OBJECT") {
				if (s[1]=="") {
					r[x] = obj[i][1];
					j = 1;
				}
				else
					for (i; obj[i][0] != "}"; i++) {
						if (obj[i][0] == s[1]) {
							r[x] = "STRING " + obj[i][1];
							j = 1;
						}
					}				
			}
			else {
				r[x] = "STRING " + obj[i][1];
				j = 1;
			}
		}
	}
	if (j == 0)
		r[x] = "NOTEXIST";
}

int main() {
	cin >> n >> m;
	for (int i = 0, j = 0; i < n; i++) {//deal object
		cin >> obj[i][j];
		if (*(obj[i][j].end() - 1) == ':') {
			obj[i][j].pop_back();
			cin >> obj[i][++j];
			if (*(obj[i][j].end() - 1) == '{') {//if it's sub-object
				obj[i][j] = "\"OBJECT\"";  
			}
			if(*(obj[i][j].end() - 1) == ',')
				obj[i][j].pop_back();
		}
		if (*(obj[i][j].end() - 1) == ',')
			obj[i][j].pop_back();
		j = 0;
	}
	for (int i = 0; i < n; i++) {          //deal string 
		if (*(obj[i][0].end() - 1) == '"') {
			dealStr(obj[i][0]);
			dealStr(obj[i][1]);
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> s[i][0];
		if (s[i][0].find('.') < MAXSZIE) {
			int k = s[i][0].find('.');
			string s1(s[i][0]);
			s[i][1] = s1.substr(k + 1);
			s[i][0] = s[i][0].substr(0, k);
		}
		research(s[i],i);
	}
	//cout << "--------Result---------" << endl;
	for (int i = 0; i < m; i++)
		cout << r[i] << endl;
		
	return 0;
}
/*for (int i = 0, j = 0; i < n; i++) {   
	cout << obj[i][0]<<"   ";
	cout << obj[i][1] << endl;
}
for (int i = 0; i < m; i++) {
	cout << s[i] << endl;
}*/