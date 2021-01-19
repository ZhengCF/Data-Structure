#include<iostream>

using namespace std;

void get(int *p)
{
    *p = 5;
    return;
}

int main()
{
    int a = 1;
    cout<<a<<endl;
    get(&a);
    cout<<a<<endl;
    return 0;
}