#include <iostream>
using namespace std;

int main(){
	enum color{
		white,black=100,red,blue,green=300
	};
	cout<<white<<endl;
	cout<<black<<endl;
	cout<<red<<endl;
	cout<<blue<<endl;
	cout<<green<<endl;
	
    enum days{one, two, three}day;
    day = one;
    switch(day){
        case one:
            cout << "one" << endl;
            break;
        case two:
            cout << "two" << endl;
            break;
        default:
            cout << "three" << endl;
            break;
    }
    return 0;
}