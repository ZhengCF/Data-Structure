#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main() {
	int n, m, elem, k, k1, k2, nt, nc;
	cin >> n;
	set<int> M;
	vector<set<int>> MM;
	vector<double> outs;
	for (int i = 0; i < n; i++) {
		cin >> m ;
		MM.push_back(M);
		for (int j = 0; j < m; j++) {
			cin >> elem;
			MM[i].insert(elem);
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> k1 >> k2;
		nc = MM[k1 - 1].size() + MM[k2 - 1].size();
		for (set<int>::iterator j = MM[k1 - 1].begin(); j != MM[k1 - 1].end(); j++)
			M.insert(*j);
		for (set<int>::iterator j = MM[k2 - 1].begin(); j != MM[k2 - 1].end(); j++)
			M.insert(*j);
		nt = M.size();
		nc -= nt;
		outs.push_back(nc * 1000 / nt / 10.0);
		M.clear();
	}
	for (int i = 0; i < outs.size(); i++)
		printf("%.1f%%\n", outs[i]);
		//cout << outs[i] << "%" << endl;
	return 0;
}