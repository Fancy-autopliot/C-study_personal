#include <iostream>
#include <string.h>
using namespace std;
// 多态案例三--电脑组装
// 案例描述：电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）
// 将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
// 创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
// 测试时组装三台不同的电脑进行工作

// 抽象CPU类
class CPU{
public:
    // 抽象的计算函数
    virtual void calculate() = 0;
};

// 抽象显卡类
class VideoCard{
public:
    // 抽象的显示函数
    virtual void dispaly() = 0;
};

// 抽象内存条类
class Memory{
public:
    // 抽象的存储函数
    virtual void storage() = 0;
};

// 创建组装电脑
class Computer{
public:
    Computer(CPU *cpu, VideoCard *video, Memory *memory){
        m_cpu = cpu;
        m_video = video;
        m_memory = memory;
    }

    // 提供工作函数，让零件工作起来
    void Work(){
        // 调用零件接口
        m_cpu->calculate();
        m_video->dispaly();
        m_memory->storage();
    }
    ~Computer(){
        if (m_cpu != NULL){
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_video != NULL){
            delete m_video;
            m_video = NULL;
        }
        if (m_memory != NULL){
            delete m_memory;
            m_memory = NULL;
        }
    }
private:
    CPU *m_cpu;
    VideoCard *m_video;
    Memory *m_memory;
    
};

// 零部件厂商
class IntelCPU : public CPU{
public:
    void calculate(){
        cout << "Intel CPU has calculating" << endl;
    }
};

class AMDCPU : public CPU{
public:
    void calculate(){
        cout << "AMD CPU has calculating" << endl;
    }
};

class NvidiaVedioCard : public VideoCard{
public:
    void dispaly(){
        cout << "NVIDIA Card has displaying" << endl;
    }
};

class AMDVedioCard : public VideoCard{
public:
    void dispaly(){
        cout << "AMD Card has displaying" << endl;
    }
};

class WestDigitalMemory : public Memory{
public:
    void storage(){
        cout << "West Digital Memory has storaging" << endl;
    }
};

class KIOXIAMemory : public Memory{
public:
    void storage(){
        cout << "KIOXIA Memory has storaging" << endl;
    }
};

void test01(){
    // 第一台电脑零件,提供析构函数释放下面三个指针
    CPU *intelcpu = new IntelCPU;
    VideoCard *nvidiacard = new NvidiaVedioCard;
    Memory *westdigitalmemory = new WestDigitalMemory;

    cout << "-------------The first computer has working: -------------" << endl;
    Computer *computer1 = new Computer(intelcpu, nvidiacard, westdigitalmemory);
    computer1->Work();
    delete computer1;

    cout << "-------------The second computer has working: -------------" << endl;
    Computer *computer2 = new Computer(new AMDCPU, new AMDVedioCard, new KIOXIAMemory);
    computer2->Work();
    delete computer2;

    cout << "-------------The third computer has working: -------------" << endl;
    Computer *computer3 = new Computer(new AMDCPU, new NvidiaVedioCard, new WestDigitalMemory);
    computer3->Work();
    delete computer3;

}

int main()
{ 
    test01();
    system("pause");
    return 0;
}
