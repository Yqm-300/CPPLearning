#include<iostream>
using namespace std;


void test01()
{
    string s1;//默认构造
    
    const char*str="hello world";
    string s2(str);//使用字符串初始化

    string s3(s2);//拷贝构造

    string s4(10,'a');//10个a

    cout<<s4<<endl;

}
//string的赋值操作
void test02()
{
    string str1;
    str1="hello world";

    string str2;
    str2=str1;

    string str3;
    str3.assign("hello c++");

    string str4;
    str4.assign(str3,3);//赋值前3个字符

}

//字符串拼接
void test_pinjie()
{
    string str1="我";
    
    str1+="爱玩游戏";

    string str3="I";
    str3.append("love playing games.",5);

    str1.append(str3,0,4);//从第0位置截取4个

    
}

int main()
{

   test01();


system("pause");
return 0;

} 