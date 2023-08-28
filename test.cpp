#include<iostream>
using namespace std;

//静态成员
class Person
{
    public:
    
    static int m_A;

    private:

    static int m_B;
};
//类内声明，类外初始化
int Person::m_A=10;
int Person::m_B=10;
//所有初始化出来的该类的对象共享同一份数据

void fangwen()
{
    cout<<Person::m_A<<endl;
}

class Person_1
{
    public:

//静态成员函数
    static void func()
    {
        cout<<"static func"<<endl;
        m_A=100;//只能访问静态成员变量
    }

    static int m_A;
    int m_B;
};
int Person_1::m_A=10;


int main()
{
Person_1::func();


return 0;

}
