#include<iostream>
using namespace std;

class Solution
{
    public:
    int strToInt(string str)
    {
        //初始化
        int res=0,bndry=INT_MAX/10;
        int i=0,sign=1,length=str.size();

        if(length==0) return 0;
        while(str[i]==' ')//用遍历跳过空格 
        {
            //如果全是空格返回0
            if(++i==length) return 0;
        }
        if(str[i]=='-')sign=-1;
        if(str[i]=='-'||str[i]=='+')i++;
        for(int j=i;j<length;j++)
        {
             if(str[j]<'0'||str[j]>'9')break;
             if(res>bndry||res==bndry&&str[j]>'7')
             {
              return sign==1?INT_MAX:INT_MIN;
             }
             res=res*10+(str[j]-'0');
             
        }
        return res*sign;


    }
}



int main()
{


    return 0;
}