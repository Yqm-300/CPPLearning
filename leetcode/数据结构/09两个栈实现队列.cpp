#include<iostream>
using namespace std;
#include<stack>
class CQueue {
public:
    CQueue() {
      
    }
    
    void appendTail(int value) 
    {
        A.push(value);
    }
    
    int deleteHead() 
    {
       if(!B.empty())
       {
        int tmp=B.top();
        B.pop();
        return tmp;
       }
       if(A.empty()) return -1;

       while(!A.empty())
       {
        int tmp=A.top();
        B.push(tmp);
       }
       
       int tmp=B.top();
       B.pop();
       return tmp;
    }

    stack<int> A;
    stack<int> B;
};

int main()
{
     
    return 0;
}