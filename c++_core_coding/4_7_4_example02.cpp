#include <iostream>
#include <string.h>
using namespace std;
// 多态案例--制造饮品

// 定义饮品制作的抽象类
class DrinkingAbstract{
public:
    // 烧水
    virtual void BoilWater() = 0;
    // 冲泡
    virtual void Brew() = 0;
    // 倒入杯中
    virtual void PourInCup() = 0;
    // 加入材料
    virtual void PutMaterialIn() = 0;
    void MakeDrinking(){
        BoilWater();
        Brew();
        PourInCup();
        PutMaterialIn();
    }
};

// COFFEE
class COFFEE : public DrinkingAbstract{
public:
    virtual void BoilWater(){
        cout << "Boil NongFu " << endl;
    }
    virtual void Brew(){
        cout << "Brew coffee" << endl;
    }
    virtual void PourInCup(){
        cout << "Pour coffe in coffe cup" << endl;
    }
    virtual void PutMaterialIn(){
        cout << "Put sugar and milk in coffe cup" << endl;
    }
};

// Tea
class Tea : public DrinkingAbstract{
public:
    virtual void BoilWater(){
        cout << "Boil ShanQuan " << endl;
    }
    virtual void Brew(){
        cout << "Brew Tea" << endl;
    }
    virtual void PourInCup(){
        cout << "Pour tea in tea cup" << endl;
    }
    virtual void PutMaterialIn(){
        cout << "Put lemon in tea cup" << endl;
    }
};

// 两种方式：父类指针  或  引用  指向子类对象
// 指针指向子类
void DoDrinking(DrinkingAbstract *drinking){
    drinking->MakeDrinking();
}

// 引用指向子类
void DoDrinking(DrinkingAbstract &drinking){
    drinking.MakeDrinking();
}

void test01(){
    // 引用需要先实例化对象
    COFFEE coffee;
    DoDrinking(coffee);
    cout << "---------------------------------" << endl;
    // 指针指向  直接利用new传递
    DoDrinking(new Tea);
}

int main()
{
    test01();
    system("pause");
    return 0;
}
