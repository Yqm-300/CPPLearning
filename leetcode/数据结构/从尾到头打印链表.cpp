#include<iostream>
using namespace std;
#include<stack>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution
{
    public:
    vector<int> reversePrint(ListNode*head)
    {
        recur(head);
        return res;


    }

      vector<int>rp(ListNode*head)
    {
        stack<int>stk;
        while(head!=NULL)
        {
            stk.push(head->val);
            head=head->next;
        }
        vector<int>res;
        while(!stk.empty())//当stk不为空时
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;

    }
    private:

    vector<int>res;

    void recur(ListNode*head)
    {
        if(head==NULL) return;
        recur(head->next);
        res.push_back(head->val);
    }

  
};

int main()
{
    ListNode*n1=new ListNode(1);
    ListNode*n2=new ListNode(3);
    ListNode*n3=new ListNode(2);
    
    n1->next=n2;
    n2->next=n3;

    return 0;
}