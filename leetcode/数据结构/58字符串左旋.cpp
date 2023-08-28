#include<iostream>
using namespace std;
#include<vector>
string zuoxuanstring(string str,int n)
{
  string str_l=str.append(str,0,n);//从下标0开始截取n个放到后面
  str_l=str.erase(0,n);
  return str_l;
};

int slideWindow(vector nums)
{
   
}


int main()
{


    return 0;
}