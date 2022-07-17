#include<iostream>
#include<string.h>
using namespace std;
// 将成员属性设置为私有
// 优点1：将所有成员属性设置为私有，可以自己控制读写权限
// 优点2：对于写权限，我们可以检测数据的有效性
// 方法：通过在类内提供一些成员函数接口访问私有成员属性

class Person{
public:
    // 设置年龄并访问
    string SetName(string name){      // 可读可写
        m_name = name;
        return m_name;
    }

    int GetAge()                    // 只读，无法修改
    {
        return m_age;
    }
    
    
    void SetLover(string lover){        // 只写，无法访问
        m_Lover = lover;
    }


private:
    string m_name;
    int m_age = 10;
    string m_Lover;
};

int main(){
    Person person01;
    string name = person01.SetName("james");
    // person01.m_age = 18;        // 私有成员不可访问


    cout << "name: " << name << endl;
    cout << "age: " << person01.GetAge() << endl;
    // cout << "lover: " << person01.GetLover() << endl;  //智能

    system("pause");
    return 0;
}