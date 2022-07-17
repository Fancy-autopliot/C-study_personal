#include <iostream>
#include <string.h>
#include <fstream>  // 读取文件需要包含该头文件
using namespace std;
// 二进制文件--以二进制的方式对文件进行读写操作
// 打开方式：ios::binary
// 读文件：利用ostream 调用成员函数read
// 函数原型：istream& read(char *buffer, int len);
// 参数解释：字符指针buffer指向内存中的一段存储空间，len是读写的字节数

class Person{
public:
    char m_Name[64];
    int m_Age;
};

// 二进制文件--写文件
void test01(){
    ifstream ifs("E:/VScode/c++_core_coding/person.txt", ios::in | ios::binary);
    if (!ifs.is_open()){
        cout << "open file failed" << endl;
    }

    Person p;
    ifs.read((char *)&p, sizeof(p));
    cout << "Name: " << p.m_Name << endl;
    cout << "Age: " << p.m_Age << endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}