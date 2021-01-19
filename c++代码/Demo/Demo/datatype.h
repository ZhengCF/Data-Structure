#include"iostream"
using namespace std;
class  datetype
{
	enum
	{
		inter,
		double_p,
		charac
	}type;

	union 
	{
		char c;
		double f;
		int i;
	};
public:
	 datetype();
	 datetype(int);
	 datetype(double);
	 datetype(char);
	~ datetype();

private:

};

 datetype:: datetype()
{
}

datetype::datetype(int ii)
{
	type = inter;
	i = ii;
	cout << "int: " << i << endl;
}

datetype::datetype(char cc)
{
	type = charac;
	c = cc;
	cout << "char: " << c << endl;
}

datetype::datetype(double ff)
{
	type = double_p;
	f = ff;
	cout << "double: " << f << endl;
}

 datetype::~ datetype()
{
}

 /*#include"datatype.h"
#include"iostream"
using namespace std;

int main() {
	datetype A(10), B(0.54), C('z'),D(0.123);
}*/