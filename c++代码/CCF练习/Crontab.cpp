#include<iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string>
#include <ctype.h>

using namespace std;

const char *months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const char *weeks[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

typedef struct {
	int yr;
	int mth;
	int day;
	int minu;
	int hor;
}date;

string cmd;
int n;

void anology_cmd(string cmd) {
	
}

int change_num(string s,int a,int b) {
	int num=0;
	for (int i = a; i <= b; i++)
		num = num * 10 + s[i] - '0';
	return num;
}

void output(char **e, date st, date et) {
	date nowt;
	nowt = st;
}

int main() {
	
	string st, et;
	cin >> n >> st >> et;
	date sst, eed;
	char buf[100][6];
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < 6; i++) {
			cin >> buf[j][i];	
		}
	}
	sst.yr = change_num(st, 0, 3);
	sst.mth = change_num(st, 4, 5);
	sst.day = change_num(st, 6, 7);
	sst.hor = change_num(st, 8, 9);
	sst.minu = change_num(st, 10, 11);

	eed.yr = change_num(et, 0, 3);
	eed.mth = change_num(et, 4, 5);
	eed.day = change_num(et, 6, 7);
	eed.hor = change_num(et, 8, 9);
	eed.minu = change_num(et, 10, 11);

	cout << sst.yr << sst.mth << sst.day << sst.hor << sst.minu << endl;
	cout << eed.yr << eed.mth << eed.day << eed.hor << eed.minu << endl;
	return 0;
}
