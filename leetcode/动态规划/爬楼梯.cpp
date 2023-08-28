#include<iostream>
using namespace std;



int frog(int n)
{
    int a=1,b=1,sum=0;

    for(int i=0;i<n;i++)
    {
        sum=(a+b)%1000000007;
        a=b;
        b=sum;
        
    }
    return a;
}



int main()
{

    return 0;
}