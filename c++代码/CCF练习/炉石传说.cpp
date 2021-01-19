#include<iostream>
#include<string>
using namespace std;

struct Role
{
	int position;
	int attack;
	int health;
};

Role player[2][8] = { {{0,0,30}},{{0,0,30}} };    //0号玩家，1-7号随从

void Rand(int &ii,int &jj) {
	int l = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 8; j++) {
			if (player[i][j].health > 0) {
				player[i][l] = player[i][j];
				player[i][l].position = l;
				l++;
			}
		}
		for (int k = l; k < 8; k++)
			player[i][k] = { 0,0,0 };
		if (i == 0) 
			ii = l-1;
		else
			jj = l-1;
		l = 1;
	}
}

int main() {
	int n,po,x,y,ii=0,jj=0;
	bool py=0;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "summon") {
			cin >> po;
			if (player[py][po].position > 0) {//卡位占用
				for (int i = 6; i >= po; i--) {
					player[py][i + 1] = player[py][i];
				}//从po位开始，每个向右移一位
			}
			cin >> player[py][po].attack;
			cin >> player[py][po].health;
			player[py][po].position = po;			
		}
		else if (s == "attack") {
			cin >> x >> y;
			player[py][x].health -= player[!py][y].attack;
			player[!py][y].health -= player[py][x].attack;
			Rand(ii,jj);
		}
		else if (s == "end") {
			py = !py;
		}
	}
	if (player[0][0].health <= 0)
		cout << "-1" << endl;
	else if (player[1][0].health <= 0)
		cout << "1" << endl;
	else
		cout << "0" << endl;

	Rand(ii, jj);
	cout << player[0][0].health << endl;
	cout << ii << " ";
	for (int i = 1; i <= ii; i++)
		cout << player[0][i].health << " ";
	cout << endl;

	cout << player[1][0].health << endl;
	cout << jj << " ";
	for (int i = 1; i <= jj; i++)
		cout << player[1][i].health << " ";
	cout << endl;
}