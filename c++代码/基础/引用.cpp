#include <iostream>

using namespace std;

int main()
{
	int rats = 100;
	int &rodent = rats;
	
	cout << "rats = "<<rats<<", rosent = "<<rodent<<endl;
	cout << "rats address = "<<&rats<<endl;
	cout << "rosent address = "<<&rodent<<endl;
	
	cout <<"==================================="<<endl;
	int bunnies = 50;
	rodent = bunnies;
	
	cout << "rats = "<<rats<<", rosent = "<<rodent<<", bunnies = "<<bunnies<<endl;
	cout << "rats address = "<<&rats<<endl;
	cout << "rosent address = "<<&rodent<<endl;
	cout << "bunniess address = "<<&bunnies<<endl;
	
	return 0;
}