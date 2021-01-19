#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int n, k;//n<=40000;k<=2500;
	int c, sno;
	string name;
	vector<vector<string>> cs;
	vector<string> sname;
	vector<vector<int>> out;
	vector<int> o;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cs.push_back(sname);
	}
	for (int i = 0; i < k; i++) {
		cin >> c >> sno;
		for (int j = 0; j < sno; j++) {
			cin >> name;
			cs[c-1].push_back(name);
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> name;
		sname.push_back(name);
		out.push_back(o);
		out[i].push_back(0);
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < cs[i].size(); j++) {
			for (int l = 0; l < n; l++) {
				if (cs[i][j].compare(sname[l])==0) {
					out[l][0]++;
					out[l].push_back(i+1);
					break;
				}
			}			
			//cout << cs[i][j] << " ";
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << sname[i] << " ";
		for (int j = 0; j < out[i].size(); j++) {
			cout << out[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
