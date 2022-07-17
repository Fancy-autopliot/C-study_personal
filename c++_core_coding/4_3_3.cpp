#include<iostream>
#include<string.h>
using namespace std;
// 空指针访问成员函数
// 空指针可以调用成员函数，要注意有没有用到this指针
// 如果用到this指针，需要加以判断保证代码的鲁棒性

class Person {
public:

	void ShowClassName() {
		cout << "我是Person类!" << endl;
	}

	void ShowPerson() {
        // 该部分是防止传入空指针访问时出现异常
		if (this == NULL) {
			return;
		}
		cout << mAge << endl;       // mAge 与 this->mAge 是一个意思
	}

public:
	int mAge;
};

void test01()
{
	Person * p = NULL;
	p->ShowClassName(); //空指针，可以调用成员函数
	p->ShowPerson();  //但是如果成员函数中用到了this指针，就不可以了
}

int main() {

	test01();

	system("pause");

	return 0;
}