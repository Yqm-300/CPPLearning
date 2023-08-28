#include<iostream>
using namespace std;
#include<stack>
struct ListNode
{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution
{
    public:
    ListNode* reverseList(ListNode*head)
    {
       

    }

    private:
 
    ListNode*recur(ListNode*cur,ListNode*pre)
    {
        //终止条件
        if(cur==NULL)return pre;
        ListNode*res=recur(cur->next,cur);
        cur->next=pre;
        return res;
    }

    stack<struct ListNode*> stk_A;
    stack<struct ListNode*> stk_B;
    ListNode*fuzhustack(ListNode*head)
    {
        while(head!=NULL)
        {
            stk_A.push(head);
            head=head->next;
        }
        while(!stk_A.empty())
        {
            stk_B.push(stk_A.top());
            stk_A.pop();
            (stk_B.top())->next=stk_A.top();
        }
        (stk_B.top())->next=NULL;
        while(stk_B.size()!=1)
        {
            stk_B.pop();
        }
        return stk_B.top();
    }
}


int main()
{


    return 0;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    //    auto res=recur(head,NULL);
       return recur(head,NULL);
    }

    private:
    ListNode*recur(ListNode*cur,ListNode*pre)
    {
        if(cur->next==NULL)return pre;
        ListNode* res=recur(cur->next,cur);
        cur->next=pre;
        return res;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return recur(head, nullptr);           // 调用递归并返回
    }
private:
    ListNode* recur(ListNode* cur, ListNode* pre) {
        if (cur == nullptr) return pre;        // 终止条件
        ListNode* res = recur(cur->next, cur); // 递归后继节点
        cur->next = pre;                       // 修改节点引用指向
        return res;                            // 返回反转链表的头节点
    }
};
