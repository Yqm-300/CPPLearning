#include<iostream>
using namespace std;

class Solution
{
    public:
    string replaceSpace(string *s)
    {
        int count=0,len=s->size();
        //统计空格数量
        for(char c : *s)
        {
            if(c ==' ')//注意char是单引号''
            {
                count++;
            }
        }
        //修改字符串长度
        s->resize(len+2*count);
        
        //倒序遍历修改
        //i指向原始的末尾，j指向增加长度后的末尾
        for(int i=len-1,j=s->size()-1;i<j;i--,j--)
        {
            if((*s)[i] != ' ')
            {
              (*s)[j]=(*s)[i];
            }
            else
            {
                (*s)[j]='0';
                (*s)[j-1]='2';
                (*s)[j-2]='%';
                j-=2;
            }

        }
    return *s;

    }
};


int main()
{
    string s = "We are happy.";
    cout<<s<<endl;
    Solution s1;
    s=s1.replaceSpace(&s);

    cout<<s<<endl;

    system("pause");
    return  0;
}