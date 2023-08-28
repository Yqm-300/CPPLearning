#include<iostream>
using namespace std;
#include<stack>
class MinStack
{
    public:
    stack<int>stk_A;
    stack<int>stk_B;

    MinStack(){};

    void push(int a)
    {
      stk_A.push(a);
      if(stk_B.empty()||a<=stk_B.top())
      {
        stk_B.push(a);
      }

    }
    void pop()
    {
      if(stk_A.top()==stk_B.top())
      {
        stk_B.pop();
      }
      stk_A.pop();
    }

    int top()
    {
       return stk_A.top();
    }

    int min()
    {
       return stk_B.top();
    }

};



int main()
{


    return 0;
}