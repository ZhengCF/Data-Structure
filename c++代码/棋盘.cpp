#include"iostream"
using namespace std;
//#define size 30 //ע1   

int main(){
	const int size = 30;   //ע1
	int x,y;
	char pan[size][size];
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			pan[i][j]='+';
	}
	
	while(1){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++)
				cout<<pan[i][j]<<" ";
			cout<<endl;
		}
		cin>>x>>y;
		pan[x][y]='O';
		cin>>x>>y;
		pan[x][y]='X';
	}
	
} 