#include<iostream>
using namespace std;
#include<queue>
#include<deque>

class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {

return deque.empty() ? -1:deque.front();

    }
    
    void push_back(int value) {

queue.push(value);
while(!deque.empty()&&deque.back()<value)//为空不能pop_back
{
    deque.pop_back();
}
deque.push_back(value);



    }
    
    int pop_front() {
if(queue.empty())return -1;
int val=queue.front();
if(val==deque.front()) deque.pop_front();
queue.pop();
return val;
    }

    queue<int>queue;
    deque<int>deque;
};


int main()
{



    system("pause");
    return 0;
}