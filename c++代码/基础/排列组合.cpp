#include <iostream>
 
using namespace std;
struct timec{
	int year;
	int month;
	int day;
	int hour;
	int minutes;
	int second; 
};

int main(){
	char color[5]={'y','r','b','w','k'};
	int n=0,j,k,i;
	for(i=0;i<5;i++){
		for(j=i;j<5;j++){
			for(k=j;k<5;k++){
				if(i!=j&&j!=k&&i!=k){
					n++;
					cout<<n<<'.'<<color[i]<<color[j]<<color[k]<<endl;
				}				
			}				
		}
	}
	cout<<n;
} 
