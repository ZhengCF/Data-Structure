#include <iostream>
using namespace std;

const int MAX = 4;

int main(int argc, const char * argv[]) {

    const char *names[MAX] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali",
        "Sara Ali",
    };

    for(int i = 0;i < MAX;i++){
        cout <<"Value of names[" << i << "] = ";//输出字符串的值
        cout << names[i] << endl;
        cout <<"Value of *names[" << i << "] = ";//输出指针所指向字符串首地址的值
        cout << *names[i] << endl;
        cout <<"Value of *names[" << i << "]+1 = ";//输出ascii码值
        cout << *names[i]+1 << endl;
        cout <<"Value of *(names[" << i << "]+1) = ";//输出指针所指向字符串首地址上一位的值
        cout << *(names[i]+1) << endl;
        cout <<"Value of *(names[" << i << "]+1) = ";//输出指针所指向字符串首地址上一位的值
        cout << *(names[i]+2) << endl;
        cout <<"Value of *(names[" << i << "]+1) = ";//输出指针所指向字符串首地址上一位的值
        cout << *(names[i]+3) << endl;
    }
    return 0;
}