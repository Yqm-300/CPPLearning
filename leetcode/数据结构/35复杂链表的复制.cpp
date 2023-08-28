#include<iostream>
using namespace std;
#include<map>
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
    public:
    //复制普通链表
    Node*copyRamdomList(Node*head)
    {
        Node* cur=head;
        Node* dum=new Node(0);
        Node* pre=dum;

        while(cur!=NULL)
        {

            Node*node=new Node(cur->val);
            pre->next=node;
            cur=cur->next;
            pre=node;
        }
        
    }
    
    Node*copyRL(Node*head)
    {
        if(head==NULL)return NULL;
        Node*cur=head;
        while(cur!=NULL)
        {
            map[cur]=new Node(cur->val);
            cur=cur->next;
        }
        
        cur=head;
        while(cur!=NULL)
        {
            map[cur]->next=map[cur->next];
            map[cur]->random=map[cur->random];
        }
    }

};
int main()
{


    return 0;
}