#include<iostream>
using namespace std;


void print(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
}

int main()
{
   
    vector<int>v1;

    v1.resize(15,100);//100是默认填充值

    vector<int>v2;
    for(int i=0;i<10;i++)
    {
        v2.push_back(i);
    }

    //利用[]访问数组中元素
    for(int i=0;i<v1.size();i++)
    {
        cout<<v2[i]<<endl;
    }

    //利用at访问 
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2.at(i)<<endl;
    }

    //获取第一个、最后一个元素
    cout<<v2.front()<<endl;
    cout<<v2.back()<<endl;

    //vector容器互换
    vector<int> v3;

    v3.resize(v2.size(),100);

    v2.swap(v3);

    //实际用途
    //重新指定大小后容量不变
    vector<int>(v2).swap(v2);

    //预留空间
    //不用开辟空间，节省动态扩展的操作
    //reserve 预留位置元素不可访问
    

    return 0;
}