#include <iostream>
#include <string.h>
#include <fstream>  // 读取文件需要包含该头文件
using namespace std;

// 文件操作--程序运行产生的数据为临时数据，程序结束则会释放数据
// 通过文件可以将数据持久化
// 文本文件   --以ASCII码的形式存储到计算机中
// 二进制文件 --以文本的二进制形式存储，无法直接读取
// 操作文件的三大类：ofstream: 写文件   ifstream:  读文件   fstream: 读写操作
// 写文件--操作步骤
// 一、包含头文件   #include <fstream>
// 二、创建流对象   ofstream ofs
// 三、打开文件     ofs.open("文件路径", 打开方式)
// 四、写数据       ofs << "写入数据"
// 五、关闭文件     ofs.close()

// 文件打开方式
//  ios::in          为读文件而打开文件
//  ios::out         为写文件而打开文件
//  ios::ate         初始位置：文件尾
//  ios::app         追加方式写文件
//  ios::trunc       如果文件存在，先删除，再创建
//  ios::binary      二进制方式
// 文件打开方式配合使用，利用 | 操作符
// 例如：用二进制方式写文件  ios::binary | ios::out