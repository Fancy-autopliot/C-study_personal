#include<iostream>
#include<string.h>
using namespace std;
// 继承
// 语法： class 子类 : 继承方式  父类
// 子类  又称  派生类
// 父类  又称  基类
// 派生类中的成员，包括两个部分：
// 一类是从基类(父类)继承过来的，一类是自己增加的成员
// 继承过来的表示其共性，而新增的成员体现了其个性


// 继承实现页面
// 公共页面
class BasePage{
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
};

// Java页面
class Java : public BasePage{
public:
    void content(){
        cout << "class for Java" << endl;
    }
};

class Python : public BasePage{
public:
    void content(){
        cout << "class for Python" << endl;
    }
};

class CPP : public BasePage{
public:
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
