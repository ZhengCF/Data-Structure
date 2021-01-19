//网上的代码
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<list>

using namespace std;

struct IP {
	IP(string s, int len) :s(s), len(len) {}
	string s;
	int len;
	//以IP地址为第一关键字，前缀长度为第二关键字，从小到大排序
	bool operator <(const IP &a)const
	{
		return s == a.s ? (len<a.len) : (s<a.s);
	}
};

list<IP>v;


//字符串转换成base进制的整数 
int stoi(string s, int base)
{
	int res = 0;
	for (int i = 0; i<s.length(); i++)
		res = res * base + s[i] - '0';
	return res;
}

//将读入的IP前缀用struct<IP>类型的数据表示，并插入到数据结构list<IP>v中 
void f(char str[])//str为字符串存储的点分十进制 
{
	vector<string>vec;
	char *sp = strtok(str, ".");//先用"."对str进行分割，将分割的各个部分放在vec中 
	while (sp)
	{
		vec.push_back(sp);
		sp = strtok(NULL, ".");
	}
	int num = vec.size();//形成了num个部分
						 //确定是否有前缀，如果有一定是在最后一部分分，且含有"/"符号 
	string s = vec.back(), l = "";//l存储表示长度的字符串 
	vec.pop_back();
	int pos = s.find("/");
	//含有"/"说明有长度 
	if (pos != string::npos)
	{
		string ss = s;
		//将长度分割出来 
		s = ss.substr(0, pos);
		l = ss.substr(pos + 1);
	}
	int len;
	if (l == "")//如果l为空，说明没有长度，是省略长度型，那么它的长度为num*8
		len = num * 8;
	else//l不为空，即l表示长度，把它转换成十进制整数 
		len = stoi(l, 10);
	vec.push_back(s);//将最后一部分重新压入vec中 
	while (num<4)//如果不足4部分，就加0 
	{
		vec.push_back("0");
		num++;
	}
	//将4个部分换成字符串存储的32位二进制 
	string res = "";
	for (int i = 0; i<vec.size(); i++)
	{
		string t = "00000000";
		int temp = stoi(vec[i], 10);//转换成十进制整数 
									//将temp转换成二进制
		int k = 7;
		while (temp)
		{
			t[k--] = temp % 2 + '0';
			temp /= 2;
		}
		res += t;
	}
	//插入到数据结构list<IP>中 
	v.push_back(IP(res, len));
}

//判断q的匹配集是否为p的匹配集的子集,len为p的前缀长度 
bool check(string p, string q, int len)
{
	if (len>p.length() || len>q.length()) return false;
	for (int i = 0; i<len; i++)
		if (p[i] != q[i])
			return false;
	return true;
}

//打印输出 
void print(string s, int len)
{
	string s1 = s.substr(0, 8);
	string s2 = s.substr(8, 8);
	string s3 = s.substr(16, 8);
	string s4 = s.substr(24, 8);
	cout << stoi(s1, 2) << "." << stoi(s2, 2) << "." << stoi(s3, 2) << "." << stoi(s4, 2) << "/" << len << endl;
}

int main()
{
	char s[200];
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf(" %s", s);
		f(s);
	}
	//1.排序 
	v.sort();
	//2.从小到大合并 
	for (list<IP>::iterator cur = v.begin(); cur != v.end();)//遍历列表 
	{
		list<IP>::iterator next = cur;
		next++;
		if (next == v.end())
			break;

		IP p1 = *cur;//当前元素 
		IP p2 = *next;//下一个元素 
		if (check(p1.s, p2.s, p1.len))
		{//如果p2的匹配集是p1的匹配集的子集,就删除p2，即 next所指元素 
			v.erase(next);
		}
		else//否则直接考虑下一个元素 
			cur++;
	}
	//3.同级合并 
	for (list<IP>::iterator cur = v.begin(); cur != v.end();)//遍历列表 
	{
		list<IP>::iterator next = cur;
		next++;
		if (next == v.end())
			break;

		IP p1 = *cur; //当前元素 
		IP p2 = *next;//下一个元素 
					  //p1.len==p2.len且p1前缀长度减一后依然合法（只要p1.s[p1.len-1]=0就是合法的） 
		if (p1.len == p2.len&&p1.len>0 && p1.s[p1.len - 1] == '0')
		{
			IP tmp = p1;
			tmp.len--;
			//能合并 
			if (check(tmp.s, p2.s, tmp.len))
			{
				v.erase(next);//删除下一个元素 
				*(cur) = tmp;//删除当前元素，并插入tmp，等价于将当前元素的值变为tmp 
				if (cur != v.begin())//如果cur所指的不是第一个元素，那么就要从cur的前一个元素考虑，就cur-- 
					cur--;
			}
			//不能合并，直接考虑下一个元素 
			else
				cur++;
		}
		//减一后不合法，直接考虑下一个元素 
		else
			cur++;
	}
	//输出 
	for (list<IP>::iterator cur = v.begin(); cur != v.end(); cur++)
		print((*cur).s, (*cur).len);
	return 0;
}