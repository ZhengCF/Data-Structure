//���ϵĴ���
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
	//��IP��ַΪ��һ�ؼ��֣�ǰ׺����Ϊ�ڶ��ؼ��֣���С��������
	bool operator <(const IP &a)const
	{
		return s == a.s ? (len<a.len) : (s<a.s);
	}
};

list<IP>v;


//�ַ���ת����base���Ƶ����� 
int stoi(string s, int base)
{
	int res = 0;
	for (int i = 0; i<s.length(); i++)
		res = res * base + s[i] - '0';
	return res;
}

//�������IPǰ׺��struct<IP>���͵����ݱ�ʾ�������뵽���ݽṹlist<IP>v�� 
void f(char str[])//strΪ�ַ����洢�ĵ��ʮ���� 
{
	vector<string>vec;
	char *sp = strtok(str, ".");//����"."��str���зָ���ָ�ĸ������ַ���vec�� 
	while (sp)
	{
		vec.push_back(sp);
		sp = strtok(NULL, ".");
	}
	int num = vec.size();//�γ���num������
						 //ȷ���Ƿ���ǰ׺�������һ���������һ���ַ֣��Һ���"/"���� 
	string s = vec.back(), l = "";//l�洢��ʾ���ȵ��ַ��� 
	vec.pop_back();
	int pos = s.find("/");
	//����"/"˵���г��� 
	if (pos != string::npos)
	{
		string ss = s;
		//�����ȷָ���� 
		s = ss.substr(0, pos);
		l = ss.substr(pos + 1);
	}
	int len;
	if (l == "")//���lΪ�գ�˵��û�г��ȣ���ʡ�Գ����ͣ���ô���ĳ���Ϊnum*8
		len = num * 8;
	else//l��Ϊ�գ���l��ʾ���ȣ�����ת����ʮ�������� 
		len = stoi(l, 10);
	vec.push_back(s);//�����һ��������ѹ��vec�� 
	while (num<4)//�������4���֣��ͼ�0 
	{
		vec.push_back("0");
		num++;
	}
	//��4�����ֻ����ַ����洢��32λ������ 
	string res = "";
	for (int i = 0; i<vec.size(); i++)
	{
		string t = "00000000";
		int temp = stoi(vec[i], 10);//ת����ʮ�������� 
									//��tempת���ɶ�����
		int k = 7;
		while (temp)
		{
			t[k--] = temp % 2 + '0';
			temp /= 2;
		}
		res += t;
	}
	//���뵽���ݽṹlist<IP>�� 
	v.push_back(IP(res, len));
}

//�ж�q��ƥ�伯�Ƿ�Ϊp��ƥ�伯���Ӽ�,lenΪp��ǰ׺���� 
bool check(string p, string q, int len)
{
	if (len>p.length() || len>q.length()) return false;
	for (int i = 0; i<len; i++)
		if (p[i] != q[i])
			return false;
	return true;
}

//��ӡ��� 
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
	//1.���� 
	v.sort();
	//2.��С����ϲ� 
	for (list<IP>::iterator cur = v.begin(); cur != v.end();)//�����б� 
	{
		list<IP>::iterator next = cur;
		next++;
		if (next == v.end())
			break;

		IP p1 = *cur;//��ǰԪ�� 
		IP p2 = *next;//��һ��Ԫ�� 
		if (check(p1.s, p2.s, p1.len))
		{//���p2��ƥ�伯��p1��ƥ�伯���Ӽ�,��ɾ��p2���� next��ָԪ�� 
			v.erase(next);
		}
		else//����ֱ�ӿ�����һ��Ԫ�� 
			cur++;
	}
	//3.ͬ���ϲ� 
	for (list<IP>::iterator cur = v.begin(); cur != v.end();)//�����б� 
	{
		list<IP>::iterator next = cur;
		next++;
		if (next == v.end())
			break;

		IP p1 = *cur; //��ǰԪ�� 
		IP p2 = *next;//��һ��Ԫ�� 
					  //p1.len==p2.len��p1ǰ׺���ȼ�һ����Ȼ�Ϸ���ֻҪp1.s[p1.len-1]=0���ǺϷ��ģ� 
		if (p1.len == p2.len&&p1.len>0 && p1.s[p1.len - 1] == '0')
		{
			IP tmp = p1;
			tmp.len--;
			//�ܺϲ� 
			if (check(tmp.s, p2.s, tmp.len))
			{
				v.erase(next);//ɾ����һ��Ԫ�� 
				*(cur) = tmp;//ɾ����ǰԪ�أ�������tmp���ȼ��ڽ���ǰԪ�ص�ֵ��Ϊtmp 
				if (cur != v.begin())//���cur��ָ�Ĳ��ǵ�һ��Ԫ�أ���ô��Ҫ��cur��ǰһ��Ԫ�ؿ��ǣ���cur-- 
					cur--;
			}
			//���ܺϲ���ֱ�ӿ�����һ��Ԫ�� 
			else
				cur++;
		}
		//��һ�󲻺Ϸ���ֱ�ӿ�����һ��Ԫ�� 
		else
			cur++;
	}
	//��� 
	for (list<IP>::iterator cur = v.begin(); cur != v.end(); cur++)
		print((*cur).s, (*cur).len);
	return 0;
}