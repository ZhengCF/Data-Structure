#include"iostream"
#include"employee.h"
#include"iomanip"
using namespace std;

int main(){
	employee a,b,c,d;
	float pay;

	a.add_No(1);
	a.promote(9);
	cout << "请输入雇员编号" << a.get_No() << "的月薪：";	
	cin >> pay;
	a.set_pay(pay);
	
	b.add_No(2);
	b.promote(8);
	cout<< "请输入雇员编号" << b.get_No() << "的月薪：";
	cin >> pay;
	b.set_pay(pay);
		
	c.add_No(3);
	c.promote(8);
	cout << "请输入雇员编号" << c.get_No() << "的月薪：";
	cin >> pay;
	c.set_pay(pay);

	d.add_No(4);
	d.promote(8);
	cout << "请输入雇员编号" << d.get_No() << "的月薪：";
	cin >> pay;	
	d.set_pay(pay);

	cout << "员工编号" << a.get_No() << " 级别为" << setw(2) << a.get_stage() << " 本月工资" << a.get_pay() << endl;
	cout << "员工编号" << b.get_No() << " 级别为" << setw(2) << b.get_stage() << " 本月工资" << b.get_pay() << endl;
	cout << "员工编号" << c.get_No() << " 级别为" << setw(2) << c.get_stage() << " 本月工资" << c.get_pay() << endl;
	cout << "员工编号" << d.get_No() << " 级别为" << setw(2) << d.get_stage() << " 本月工资" << d.get_pay() << endl;
}