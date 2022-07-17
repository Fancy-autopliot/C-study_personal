#include <iostream>
#include <string.h>
#include <fstream>  // 读取文件需要包含该头文件
using namespace std;
// 读文件--四种方式
// 步骤：
// 1、包含头文件                #include <fstream>
// 2、创建流对象                ifstream ifs
// 3、打开文件并判断是否成功     ifs.open("文件路径", 打开方式)
// 4、读取数据                  四种方式
// 5、关闭文件                  ifs.close()

// 写文件
void test01(){
    ifstream ifs;
    ifs.open("E:/VScode/c++_core_coding/writer_txt_test.txt", ios::in);
    if  (!ifs.is_open()){
        cout << "open file failed" << endl;
        return;
    }
    // 第一种方式--单个字符读取，每个字符之间均换行
    // char buf[1024] = { 0 };
    // while (ifs >> buf){
    //     cout << buf << endl;
    // }

    // 第二种方式--整行读取，整行输出
    // char buf[1024] = { 0 };
    // while (ifs.getline(buf, sizeof(buf))){
    //     cout << buf << endl;
    // }

    // 第三种方式--
    // string buf;
    // while (getline(ifs, buf)){
    //     cout << buf << endl;
    // }

    // 第四种方式
    char c;
    while ((c = ifs.get()) != EOF){
        cout << c;
    }


    ifs.close();
}

int main(){
    test01();
    system("pause");
    return 0;
}