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
        cout <<"Value of names[" << i << "] = ";//����ַ�����ֵ
        cout << names[i] << endl;
        cout <<"Value of *names[" << i << "] = ";//���ָ����ָ���ַ����׵�ַ��ֵ
        cout << *names[i] << endl;
        cout <<"Value of *names[" << i << "]+1 = ";//���ascii��ֵ
        cout << *names[i]+1 << endl;
        cout <<"Value of *(names[" << i << "]+1) = ";//���ָ����ָ���ַ����׵�ַ��һλ��ֵ
        cout << *(names[i]+1) << endl;
        cout <<"Value of *(names[" << i << "]+1) = ";//���ָ����ָ���ַ����׵�ַ��һλ��ֵ
        cout << *(names[i]+2) << endl;
        cout <<"Value of *(names[" << i << "]+1) = ";//���ָ����ָ���ַ����׵�ַ��һλ��ֵ
        cout << *(names[i]+3) << endl;
    }
    return 0;
}