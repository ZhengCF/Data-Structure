#include"iostream"
#include"employee.h"
#include"iomanip"
using namespace std;

int main(){
	employee a,b,c,d;
	float pay;

	a.add_No(1);
	a.promote(9);
	cout << "�������Ա���" << a.get_No() << "����н��";	
	cin >> pay;
	a.set_pay(pay);
	
	b.add_No(2);
	b.promote(8);
	cout<< "�������Ա���" << b.get_No() << "����н��";
	cin >> pay;
	b.set_pay(pay);
		
	c.add_No(3);
	c.promote(8);
	cout << "�������Ա���" << c.get_No() << "����н��";
	cin >> pay;
	c.set_pay(pay);

	d.add_No(4);
	d.promote(8);
	cout << "�������Ա���" << d.get_No() << "����н��";
	cin >> pay;	
	d.set_pay(pay);

	cout << "Ա�����" << a.get_No() << " ����Ϊ" << setw(2) << a.get_stage() << " ���¹���" << a.get_pay() << endl;
	cout << "Ա�����" << b.get_No() << " ����Ϊ" << setw(2) << b.get_stage() << " ���¹���" << b.get_pay() << endl;
	cout << "Ա�����" << c.get_No() << " ����Ϊ" << setw(2) << c.get_stage() << " ���¹���" << c.get_pay() << endl;
	cout << "Ա�����" << d.get_No() << " ����Ϊ" << setw(2) << d.get_stage() << " ���¹���" << d.get_pay() << endl;
}