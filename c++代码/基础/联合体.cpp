#include"iostream"
using namespace std;
struct aircraft
{
	int wingspan;
	int passengers;
	union{
		float fuel;
		float bomb;
		int pallets;
	};
} fighter,bomber,transport;

int main(){
	fighter.wingspan=40;
	fighter.passengers=1;
	fighter.fuel=12000;
	
	bomber.wingspan=90;
	bomber.passengers=12;
	bomber.bomb=14000;
	
	transport.wingspan=106;
	transport.passengers=4;
	transport.pallets=42;
	
	cout<<"fighter.fuel "<<fighter.fuel<<endl;
	cout<<"bomber.bomb "<<bomber.bomb<<endl;
	cout<<"transport.pallets "<<transport.pallets<<endl<<endl;
	
	transport.fuel=18000;
	fighter.pallets=4;
	
	cout<<"fighter.fuel "<<fighter.fuel<<endl;
	cout<<"bomber.bomb "<<bomber.bomb<<endl;
	cout<<"transport.pallets "<<transport.pallets<<endl;
	cout<<"transport.fuel "<<transport.fuel<<endl;
	cout<<"fighter.pallets "<<fighter.pallets<<endl;
	/*cout<<""<<<<endl;
	cout<<""<<<<endl;
	cout<<""<<<<endl;
	cout<<""<<<<endl;*/
}