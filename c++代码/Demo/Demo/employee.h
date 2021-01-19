#include"string"
#include"iostream"
using namespace std;

class Date
{
public:
	Date();
	Date(int nyear,int nmonth,int nday);
	Date(Date &d);
	~Date();
	void get_date();
private:
	int year, month, day;
};

Date::Date()
{
	cout << "------------------------here is no no argument constructor!" << endl;
}

Date::Date(int nyear, int nmonth, int nday) {
	year = nyear;
	month = nmonth;
	day = nday;  
	cout << "----------------------------here is argument constructor!" << endl;
}

Date::Date(Date &d) {
	year = d.year;
	month = d.month;
	//day = d.day;    //day is bug;
	cout << "--------------------------------here is copy!" << endl;
}
Date::~Date()
{
	cout << "--------------------------------here is destructor!" << endl;
}

void Date::get_date() {
	cout << year << "." << month << "." << day << endl;
}

class employee {
protected:
	int No;
	char sex;
	Date day_both;
	string id_number;
public:
	employee();
	~employee();
	void set_No(int);
	void set_sex(char);
	void set_day_both(Date);
	void set_id_number(string);
	int get_No();
	void get_both();
	char get_sex();
	string get_id();
};

employee::employee() {
	No = 1000;
	sex = ' ';
	id_number = 330727000000001212;
}

employee::~employee() {}

void employee::set_No(int no){	No = no;}

inline void employee::set_sex(char s){sex = s;}

inline void employee::set_day_both(Date day) { day_both = day; }

inline void employee::set_id_number(string id) { id_number = id; }

int employee::get_No() { return No; }

char employee::get_sex() { return sex; }

string employee::get_id() { return id_number; }

void employee::get_both() {
	day_both.get_date();
}



/*#include"employee.h"


int main() {
	//const char man = 'm',womam='w';
	Date d(1994, 10, 07);
	employee A;
	A.set_No(1001);
	A.set_sex('m');
	A.set_id_number("330727100010101212");
	A.set_day_both(d);
	cout << A.get_No() << endl;
	cout << A.get_id() << endl;
	cout << A.get_sex() << endl;
	A.get_both();
}*/