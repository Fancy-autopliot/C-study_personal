#include<iostream>
#include<string.h>
using namespace std;
// 继承
// 继承是面向对象三大特性之一
// 有些类与类之间存在特定的关系，下一级别的成员除了拥有上一级的共性，还拥有自己的特性
// 此时考虑利用继承的技术，减少重复代码
// 基本语法：
// 例如某个网站中，有公共的头部，底部甚至左侧列表，只有中心内容不同
// 通过比较普通写法和继承写法，得出继承存在的意义以及好处

// 普通实现页面     √       重复代码太多
// Java页面
class Java{
public:
    void header(){
        cout << "login, logout, signup, public class" << endl;
    }
    void footer(){
        cout << "help, commuication, map for web" << endl;
    }
    void left(){
        cout << "Java, Python, C++," << endl;
    }
    void content(){
        cout << "class for Java" << endl;
    }
};

// python页面的组成与java一样
class Python{
public:
    void header(){
        cout << "login, logout, signup, public class" << endl;
    }
    void footer(){
        cout << "help, commuication, map for web" << endl;
    }
    void left(){
        cout << "Java, Python, C++," << endl;
    }
    void content(){
        cout << "class for Python" << endl;
    }
};

class CPP{
public:
    void header(){
        cout << "login, logout, signup, public class" << endl;
    }
    void footer(){
        cout << "help, commuication, map for web" << endl;
    }
    void left(){
        cout << "Java, Python, C++," << endl;
    }
    void content(){
        cout << "class for CPP" << endl;
    }
};

void test01(){
    cout << "Java Course as below: " << endl;
    Java java;
    java.header();
    java.footer();
    java.left();
    java.content();
}

void test02(){
    cout << "Python Course as below: " << endl;
    Python python;
    python.header();
    python.footer();
    python.left();
    python.content();
}

void test03(){
    cout << "CPP Course as below: " << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}


int main(){
    test01();
    cout << "------------------------------------------" << endl;
    test02();
    cout << "------------------------------------------" << endl;
    test03();
    system("pause");
    return 0;

}
