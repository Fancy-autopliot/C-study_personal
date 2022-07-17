#include <iostream>
#include <string.h>
#include <fstream>  // 读取文件需要包含该头文件
using namespace std;
// 二进制文件--以二进制的方式对文件进行读写操作
// 打开方式：ios::binary
// 写文件：利用ostream 调用成员函数write
// 函数原型：ostream& write(const char *buffer, int len);
// 参数解释：字符指针buffer指向内存中的一段存储空间，len是读写的字节数

class Person{
public:
    char m_Name[64];
    int m_Age;
};

// 二进制文件--写文件
void test01(){
    // 1、包含头文件 #include <fstream>
    // 2、创建输出流对象
    ofstream ofs("E:/VScode/c++_core_coding/person.txt", ios::out | ios::binary);

    // 3、打开文件
    // ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"Tom", 18};

    // 4、写文件
    ofs.write((const char *)&p, sizeof(p));

    // 5、关闭文件
    ofs.close();
}

int main(){
    test01();
    system("pause");
    return 0;
}