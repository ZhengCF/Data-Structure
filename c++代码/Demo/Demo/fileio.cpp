#include<iostream>
#include<fstream>

using namespace std;
int main() {
	char data[100];

	//ofstream afile;
	//afile.open("file.dat");
	//cout << "now it's typing to file.dat" << endl;
	//cout << "Enter your name: " ;
	//cin.getline(data, 100);            // getline()�������ⲿ��ȡһ�У�
	//afile << data << endl;

	//cout << "Enter your age: ";
	//cin >> data ;
	//cin.ignore();                     // ignore() ��������Ե�֮ǰ��������µĶ����ַ�
	//afile << data << endl << endl;
	//afile.close();

	ifstream bfile;
	bfile.open("file.dat");
	cout << "Reading from the file.dat" << endl;
	//bfile.seekg(0, ios::end);
	//bfile.seekg(n, ios::beg);ios::cur;
	while (!bfile.eof())
	{
		bfile >> data;
		cout << data << endl;
		/*bfile >> data;
		cout << data << endl;*/
	}
	

	bfile.close();
	return 0;
}