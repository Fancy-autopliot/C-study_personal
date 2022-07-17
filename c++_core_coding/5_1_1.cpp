#include <iostream>
#include <string.h>
#include <fstream>  // 读取文件需要包含该头文件
using namespace std;
// 总结：
// 文件操作必须包含头文件 fstream
// 读文件可以利用 ofstream, 或者 fstream
// 打开文件时需要制定操作文件的路径，以及打开方式
// 利用 << 向文件中写数据
// 操作完毕,要关闭文件

// 写文件
void test01(){
    ofstream ofs;
    ofs.open("E:/VScode/c++_core_coding/writer_txt_test.txt", ios::out);

    ofs << "Begin" << endl;
    ofs << "this is the first line of the test" << endl;
    ofs << "this is the second line of the test" << endl;
    ofs << "this is the third line of the test" << endl;
    ofs << "End" << endl;
    ofs.close();
}

int main(){
    test01();
    system("pause");
    return 0;
}