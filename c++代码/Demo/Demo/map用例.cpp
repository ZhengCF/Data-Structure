#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	map<string, int> mp;
	string s, subs;
	cin >> s;
	while (cin.peek()!='\n') {
		for (int i = 0; i < s.length(); i++) {
			if ((s.at(i) >= 'A'&&s.at(i) <= 'Z' )|| (s.at(i) >= 'a'&&s.at(i) <= 'z') || (s.at(i) >= '0'&&s.at(i) <= '9')) {//0-9,a-z,A-Z
				//continue;
			}
			else
				s.erase(i,i+1);
		}
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		//cout << s << endl;
		mp[s]++;
		cin >> s;
	}
	int max = mp.begin()->second;
	for (map<string, int> ::iterator i = mp.begin(); i != mp.end(); i++) {
		if (max < i->second)
			max = i->second;
	}
	for (map<string, int> ::iterator i = mp.begin(); i != mp.end(); i++) {
		if (max == i->second)
			cout << i->first << " " << i->second << " ";
	}
	cout << endl;
	return 0;
}