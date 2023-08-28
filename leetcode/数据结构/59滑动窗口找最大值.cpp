#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<algorithm>

vector<int> slideWindow(vector<int> &nums,int k)
{
    vector<int> res;
    if(nums.size()==0||k==0) return res;


}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size()==0 || k==0) return res;
        deque<int> d;
        for (int j=0, i=1-k; j<nums.size(); i++, j++) {

           if(d.size()==k) d.pop_front();

           while(!d.empty()&&d.back()<nums[j])
           {
            d.pop_back();
           }
           d.push_back(nums[j]);
           if(i>=0) res.push_back(nums[j]);


        }
        return res;

    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size()==0 || k==0) return res;
        deque<int> d;
        for (int j=0, i=1-k; j<nums.size(); i++, j++) {
            if (i>0 && d.front()==nums[i-1]) d.pop_front();
            while (!d.empty() && d.back() < nums[j]) d.pop_back();
            d.push_back(nums[j]);
            if (i>=0) res.push_back(d.front());
        }
        return res;

    }
};

作者：levelna
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/58rgqe/?discussion=XiQddk
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


int main()
{


    return 0;
}